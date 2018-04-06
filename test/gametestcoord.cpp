#include "gametestcoord.h"

#include "gamecoord.h"

GameTestCoord::GameTestCoord() : GameTestSuite("GameTestCoord")
{
  testCases.push_back(GameTestCase("TestCtor", GameTestCoord::TestCtor));
  testCases.push_back(GameTestCase("TestCopyCtor", GameTestCoord::TestCopyCtor));
  testCases.push_back(GameTestCase("TestAssigmentAndComparisonOperator", GameTestCoord::TestAssigmentAndComparisonOperator));
  testCases.push_back(GameTestCase("TestGetAndSet", GameTestCoord::TestGetAndSet));
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

bool GameTestCoord::TestGetAndSet()
{
  bool testCaseResult = true;

  const int32_t x = 100;
  const int32_t y = 200;
  GameCoord coord(x, y);

  testCaseResult = ((coord.GetX() == x) && (coord.GetY() == y));

  const int32_t newX = 600;
  const int32_t newY = 800;

  coord.SetX(newX);
  coord.SetY(newY);

  testCaseResult = testCaseResult && ((coord.GetX() == newX) && (coord.GetY() == newY));

  return testCaseResult;
}
