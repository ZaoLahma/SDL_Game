#include "gamewindow.h"
#include "gamethreadmodel.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <jobdispatcher.h>
#include "gamewindowif.h"

GameWindow::GameWindow()
{
  JobDispatcher::GetApi()->Log("gamewindow created");
  JobDispatcher::GetApi()->SubscribeToEvent(GAME_WINDOW_GET_WINDOW_REQ, this);

  window = SDL_CreateWindow(
                              "SDL_GAME",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              640,
                              480,
                              SDL_WINDOW_OPENGL
                            );
  if(nullptr == window)
  {
    JobDispatcher::GetApi()->Log("Failed to create SDL window: %s", SDL_GetError());
  }
}

void GameWindow::HandleEvent(const uint32_t eventNo, std::shared_ptr<EventDataBase> dataPtr)
{
  dataPtr = dataPtr; //Not used here

  if(eventNo == GAME_WINDOW_GET_WINDOW_REQ)
  {
    JobDispatcher::GetApi()->Log("Received GetWindowReq");
    std::shared_ptr<EventDataBase> getWindowCfm = std::make_shared<GameWindowGetWindowCfm>(window);
    JobDispatcher::GetApi()->RaiseEvent(GameWindowGetWindowCfm::GAME_WINDOW_GET_WINDOW_CFM, getWindowCfm);
  }
}

GameWindow::~GameWindow()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}
