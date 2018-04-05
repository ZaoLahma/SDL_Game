#include "gametestfwk.h"

GameTestFwk* GameTestFwk::instance = nullptr;

GameTestFwk::GameTestFwk()
{
  
}

GameTestFwk* GameTestFwk::GameTestFwk::GetApi()
{
  if(nullptr == instance)
  {
    instance = new GameTestFwk();
  }

  return instance;
}

void GameTestFwk::DropInstance()
{
  delete instance;
	instance = nullptr;
}
