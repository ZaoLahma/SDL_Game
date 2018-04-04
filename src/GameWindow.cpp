#include "gamewindow.h"
#include "gamethreadmodel.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
  else
  {
    renderer = SDL_CreateRenderer(window, -1, 0);
    surface = IMG_Load("assets/graphics/shipsprite.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
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

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  running = true;
  SDL_Event event;
  while(running)
  {
    int32_t ticks = SDL_GetTicks();
    int32_t seconds = ticks / 1000;
    int32_t spriteIndex = seconds % 2;
    SDL_Rect srcrect = { spriteIndex * 40, 0, 40, 64 };
    SDL_Rect dstrect = { 10, 10, 40, 64 };
    while(SDL_PollEvent(&event))
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
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    SDL_RenderPresent(renderer);
  }
}

GameWindow::~GameWindow()
{
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
