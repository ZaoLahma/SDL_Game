#include "gametestfwk.h"
#include <iostream>

GameTestFwk* GameTestFwk::instance = nullptr;

GameTestSuite::GameTestSuite(const std::string& name) : testCaseName(name)
{
  GameTestFwk::GetApi()->AddTestCase(this);
}

std::string GameTestSuite::GameTestSuiteName() const
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

void GameTestFwk::AddTestCase(GameTestSuite* testCase)
{
  testCases.push_back(testCase);
}

uint32_t GameTestFwk::ExecuteTestCases()
{
  uint32_t retVal = TESTS_PASSED;
  GameTestSuiteVector::iterator testCase = testCases.begin();

  for( ; testCase != testCases.end(); ++testCase)
  {
    std::cout<<"Running test suite "<<(*testCase)->GameTestSuiteName()<<std::endl;
    if(!(*testCase)->Execute())
    {
      retVal = TESTS_FAILED;
    }
  }

  return retVal;
}

void GameTestFwk::DropInstance()
{
  delete instance;
	instance = nullptr;
}
