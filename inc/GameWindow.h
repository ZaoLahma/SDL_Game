#ifndef HEADER_GAME_WINDOW
#define HEADER_GAME_WINDOW

struct SDL_Window;

class GameWindow
{
private:
  SDL_Window* window;

protected:

public:
  GameWindow();
  ~GameWindow();
};

#endif
