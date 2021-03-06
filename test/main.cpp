#include "gametestfwk.h"
#include "gametestcoord.h"
#include "gametestobject.h"
#include <iostream>

int main(void)
{
  GameTestCoord coordTests;
  GameTestObject objectTests;

  uint32_t result = GameTestFwk::GetApi()->ExecuteTestCases();

  if(GameTestFwk::TESTS_PASSED == result)
  {
    std::cout<<"TESTS PASSED"<<std::endl;
  }
  else
  {
    std::cout<<"TESTS FAILED"<<std::endl;
  }

  GameTestFwk::GetApi()->DropInstance();
  return 0;
}
