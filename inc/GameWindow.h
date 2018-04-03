#ifndef HEADER_GAME_WINDOW
#define HEADER_GAME_WINDOW

struct SDL_Window;
union SDL_Event;

class GameWindow
{
private:
  SDL_Window* window;
  bool running;
  void HandleWindowEvent(const SDL_Event& event);

protected:

public:
  GameWindow();
  ~GameWindow();

  void Execute();
};

#endif
