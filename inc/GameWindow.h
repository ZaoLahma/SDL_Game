#ifndef HEADER_GAME_WINDOW
#define HEADER_GAME_WINDOW

#include "eventlistenerbase.h"
#include "gamewindowif.h"

class GameWindow : public EventListenerBase
{
private:
  SDL_Window* window;

protected:

public:
  GameWindow();
  ~GameWindow();

  void HandleEvent(const uint32_t eventNo, std::shared_ptr<EventDataBase> dataPtr);
};

#endif
