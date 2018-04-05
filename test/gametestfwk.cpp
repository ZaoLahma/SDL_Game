#include "gametestfwk.h"

GameTestFwk* GameTestFwk::instance = nullptr;

GameTestCase::GameTestCase(std::string& name) : testCaseName(name)
{
  GameTestFwk::GetApi()->AddTestCase(this);
}

std::string GameTestCase::GetTestCaseName() const
{
  return testCaseName;
}

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

void GameTestFwk::AddTestCase(GameTestCase* testCase)
{
  testCases.push_back(testCase);
}

void GameTestFwk::DropInstance()
{
  delete instance;
	instance = nullptr;
}
