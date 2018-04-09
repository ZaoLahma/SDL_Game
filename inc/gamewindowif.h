#ifndef HEADER_GAME_WINDOW_IF
#define HEADER_GAME_WINDOW_IF

#include "eventdatabase.h"

struct SDL_Window;

#define GAME_WINDOW_GET_WINDOW_REQ (0x000000A0u)

class GameWindowGetWindowCfm : public EventDataBase
{
private:
  GameWindowGetWindowCfm();
public:
  GameWindowGetWindowCfm(SDL_Window* win)
  {
    window = win;
  }
  static const uint32_t GAME_WINDOW_GET_WINDOW_CFM  = GAME_WINDOW_GET_WINDOW_REQ + 0x1u;
  SDL_Window* window;
};

#endif
