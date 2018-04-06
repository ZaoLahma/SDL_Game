#include "gamecoord.h"
#include <iostream>

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

bool GameCoord::operator ==(const GameCoord& other) const
{
  return ((GetX() == other.GetX()) && (GetY() == other.GetY()));
}

bool GameCoord::operator !=(const GameCoord& other) const
{
  return (!(*this == other));
}

bool operator ==(const GameCoord& first, const GameCoord& second);

int32_t GameCoord::GetX() const
{
  return x;
}

int32_t GameCoord::GetY() const
{
  return y;
}

void GameCoord::SetX(const int32_t _x)
{
  x = _x;
}

void GameCoord::SetY(const int32_t _y)
{
  y = _y;
}
