#ifndef HEADER_GAME_WINDOW
#define HEADER_GAME_WINDOW

#include <jobbase.h>

struct SDL_Window;

class GameWindow : public JobBase
{
private:
  SDL_Window* window;

protected:

public:
  GameWindow();
  ~GameWindow();

  void Execute();
};

#endif
