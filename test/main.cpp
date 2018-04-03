#include "gamewindow.h"
#include "jobdispatcher.h"
#include "gamethreadmodel.h"

int main(void)
{
  std::shared_ptr<JobBase> window = std::make_shared<GameWindow>();

  JobDispatcher::GetApi()->ExecuteJobInGroup(window, GAME_WINDOW_EXEC_GROUP_ID);

  JobDispatcher::GetApi()->WaitForExecutionFinished();

  JobDispatcher::DropInstance();

  return 0;
}
