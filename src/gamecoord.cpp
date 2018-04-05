#include "gamecoord.h"

GameCoord::GameCoord(int32_t _x, int32_t _y) : x(_x), y(_y)
{

}

GameCoord::GameCoord(const GameCoord& other)
{
  x = other.GetX();
  y = other.GetY();
}

void GameCoord::operator =(const GameCoord& other)
{
  x = other.GetX();
  y = other.GetY();
}

int32_t GameCoord::GetX() const
{
  return x;
}

int32_t GameCoord::GetY() const
{
  return y;
}
