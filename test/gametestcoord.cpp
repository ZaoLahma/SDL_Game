#include "gametestcoord.h"

#include "gamecoord.h"

GameTestCoord::GameTestCoord() : GameTestSuite("GameTestCoord")
{
  testCases.push_back(GameTestCase("TestCtor", GameTestCoord::TestCtor));
  testCases.push_back(GameTestCase("TestCopyCtor", GameTestCoord::TestCopyCtor));
  testCases.push_back(GameTestCase("TestAssigmentAndComparisonOperator", GameTestCoord::TestAssigmentAndComparisonOperator));
}

bool GameTestCoord::TestCtor()
{
  int32_t x = 100;
  int32_t y = 200;
  GameCoord coord(x, y);

  return (coord.GetX() == x && coord.GetY() == y);
}

bool GameTestCoord::TestCopyCtor()
{
  int32_t x = 100;
  int32_t y = 200;
  GameCoord coord(x, y);
  GameCoord copy(coord);

  return (copy.GetX() == coord.GetX() && copy.GetY() == coord.GetY());
}

bool GameTestCoord::TestAssigmentAndComparisonOperator()
{
  bool testCaseResult = true;

  int32_t x = 100;
  int32_t y = 200;
  GameCoord first(x, y);
  GameCoord second(x + 200, y + 300);

  testCaseResult = (first != second);

  second = first;

  testCaseResult = testCaseResult && (first == second);

  return testCaseResult;
}
