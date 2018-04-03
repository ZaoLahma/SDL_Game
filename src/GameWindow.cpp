#include "GameWindow.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <jobdispatcher.h>

GameWindow::GameWindow()
{
  JobDispatcher::GetApi()->Log("GameWindow created");
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
}

GameWindow::~GameWindow()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}
