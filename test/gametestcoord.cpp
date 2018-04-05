#include "gametestcoord.h"

#include "gamecoord.h"

GameTestCoord::GameTestCoord() : GameTestSuite("GameTestCoord")
{

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

  return (copy.GetX() == x && copy.GetY() == y);
}

bool GameTestCoord::Execute()
{
  return TestCtor() && TestCopyCtor();
}
