#include "gamewindow.h"
#include "gamemainloop.h"
#include "jobdispatcher.h"
#include "gamethreadmodel.h"

int main(void)
{
  GameWindow window;
  GameMainLoop mainLoop;

  mainLoop.WaitForEvents();

  JobDispatcher::DropInstance();

  return 0;
}
