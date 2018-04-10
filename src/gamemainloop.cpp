#include "gamemainloop.h"
#include "jobdispatcher.h"
#include "gamewindowif.h"
#include <SDL2/SDL.h>

GameMainLoop::GameMainLoop() :
running(false),
renderReqReceived(false),
window(nullptr),
renderer(nullptr)
{
  JobDispatcher::GetApi()->SubscribeToEvent(GameWindowGetWindowCfm::GAME_WINDOW_GET_WINDOW_CFM, this);
}

void GameMainLoop::HandleEvent(const uint32_t eventNo, std::shared_ptr<EventDataBase> dataPtr)
{
  switch(eventNo)
  {
    case GameWindowGetWindowCfm::GAME_WINDOW_GET_WINDOW_CFM:
    {
      JobDispatcher::GetApi()->Log("Received GetWindowCfm");
      std::shared_ptr<GameWindowGetWindowCfm> getWindowCfm = std::static_pointer_cast<GameWindowGetWindowCfm>(dataPtr);
      this->window = getWindowCfm->window;
      std::unique_lock<std::mutex> getWindowCfmLock(getWindowCfmMutex);
      getWindowCfmNotification.notify_one();
    }
    break;
    default:
    JobDispatcher::GetApi()->Log("Received unexpected event: 0x%x", eventNo);
    break;
  }
}

void GameMainLoop::HandleWindowEvent(const SDL_Event& event)
{
  switch(event.window.event)
  {
    case SDL_WINDOWEVENT_CLOSE:
      running = false;
      break;
    default:
      break;
  }
}

void GameMainLoop::WaitForEvents()
{
  running = true;
  JobDispatcher::GetApi()->RaiseEvent(GAME_WINDOW_GET_WINDOW_REQ, nullptr);

  while(running)
  {
      if(nullptr == renderer)
      {
        JobDispatcher::GetApi()->Log("Waiting for GetWindowCfm");
        std::unique_lock<std::mutex> getWindowCfmLock(getWindowCfmMutex);
    		getWindowCfmNotification.wait(getWindowCfmLock);
        renderer = SDL_CreateRenderer(window, -1, 0);
      }

      JobDispatcher::GetApi()->Log("Game Main Loop running");

      SDL_Event event;
      while(running && (SDL_WaitEvent(&event) || renderReqReceived))
      {
        if(!renderReqReceived)
        {
          switch(event.type)
          {
            case SDL_WINDOWEVENT:
              HandleWindowEvent(event);
            break;
            default:
            break;
          }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
      }
  }
}
