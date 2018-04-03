#include "gamewindow.h"
#include "gamethreadmodel.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <jobdispatcher.h>

GameWindow::GameWindow()
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
  if(NULL == window)
  {
    JobDispatcher::GetApi()->Log("Failed to create SDL window: %s", SDL_GetError());
  }

  const uint32_t numWindowThreads = 1;
  JobDispatcher::GetApi()->AddExecGroup(GAME_WINDOW_EXEC_GROUP_ID, numWindowThreads);
}

void GameWindow::Execute()
{
  JobDispatcher::GetApi()->Log("Execute called");
  JobDispatcher::GetApi()->NotifyExecutionFinished();
}

GameWindow::~GameWindow()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}
