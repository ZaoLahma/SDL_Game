#ifndef HEADER_GAME_WINDOW
#define HEADER_GAME_WINDOW

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
union SDL_Event;

class GameWindow
{
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* surface;
  SDL_Texture* texture;
  bool running;
  void HandleWindowEvent(const SDL_Event& event);

protected:

public:
  GameWindow();
  ~GameWindow();

  void Execute();
};

#endif
