#include "gameobject.h"

GameObject::GameObject(const GameCoord& newPos) : pos(newPos)
{
  
}

void GameObject::SetPos(const GameCoord& newPos)
{
  pos = newPos;
}

GameCoord GameObject::GetPos() const
{
  return pos;
}
