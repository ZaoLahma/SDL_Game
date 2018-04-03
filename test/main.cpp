#include "gamewindow.h"
#include "jobdispatcher.h"
#include "gamethreadmodel.h"

int main(void)
{
  GameWindow window;
  window.Execute();

  JobDispatcher::DropInstance();

  return 0;
}
