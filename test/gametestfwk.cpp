#include "gametestfwk.h"
#include <iostream>

GameTestFwk* GameTestFwk::instance = nullptr;

GameTestCase::GameTestCase(const std::string& name, GameTestCaseFunction function) :
testCaseName(name), testFunc(function)
{

}

bool GameTestCase::Execute()
{
  bool retVal = true;

  std::cout<<"Running test case "<<testCaseName<<std::endl;

  if(!testFunc())
  {
    std::cout<<"Test case failed"<<std::endl;
    retVal = false;
  }

  return retVal;
}

GameTestSuite::GameTestSuite(const std::string& name) : testSuiteName(name)
{
  GameTestFwk::GetApi()->AddTestSuite(this);
}

std::string GameTestSuite::GameTestSuiteName() const
{
  return testSuiteName;
}

bool GameTestSuite::Execute()
{
  bool retVal = true;

  GameTestCaseVector::iterator testCase = testCases.begin();

  for(; testCase != testCases.end(); ++testCase)
  {
    if(!testCase->Execute())
    {
      retVal = false;
    }
  }

  return retVal;
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

void GameTestFwk::AddTestSuite(GameTestSuite* testCase)
{
  testSuites.push_back(testCase);
}

uint32_t GameTestFwk::ExecuteTestCases()
{
  uint32_t retVal = TESTS_PASSED;
  GameTestSuiteVector::iterator testCase = testSuites.begin();

  for( ; testCase != testSuites.end(); ++testCase)
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
