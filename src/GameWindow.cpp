#include "gamewindow.h"
#include "gamethreadmodel.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <jobdispatcher.h>

GameWindow::GameWindow() : running(false)
{
  JobDispatcher::GetApi()->Log("gamewindow created");

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

void GameWindow::HandleWindowEvent(const SDL_Event& event)
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

void GameWindow::Execute()
{
  JobDispatcher::GetApi()->Log("Execute called");

  running = true;
  SDL_Event event;
  while(SDL_WaitEvent(&event) && running)
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
}

GameWindow::~GameWindow()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}
