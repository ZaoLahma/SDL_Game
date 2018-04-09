#ifndef HEADER_GAME_MAIN_LOOP
#define HEADER_GAME_MAIN_LOOP

#include "eventlistenerbase.h"
#include "gamewindowif.h"
#include <condition_variable>

struct SDL_Renderer;

class GameMainLoop : EventListenerBase
{
private:
  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;
  std::mutex getWindowCfmMutex;
  std::condition_variable getWindowCfmNotification;

protected:

public:
  GameMainLoop();
  void HandleEvent(const uint32_t eventNo, std::shared_ptr<EventDataBase> dataPtr);
  void WaitForEvents();
};

#endif
