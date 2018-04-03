#include "gamewindow.h"
#include "jobdispatcher.h"

int main(void)
{
  GameWindow window;

  JobDispatcher::DropInstance();

  return 0;
}
