#include "GameWindow.h"
#include <iostream>
#include <SDL2/SDL.h>

GameWindow::GameWindow()
{
  std::cout<<"GameWindow(); called"<<std::endl;
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
    std::cout<<"Failed to create SDL window: %s"<<SDL_GetError()<<std::endl;
  }
}

GameWindow::~GameWindow()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}
