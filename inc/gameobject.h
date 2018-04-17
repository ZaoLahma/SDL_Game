#ifndef HEADER_GAME_OBJECT
#define HEADER_GAME_OBJECT

#include "gamecoord.h"

class GameObject
{
private:
  GameObject();

protected:
  GameCoord pos;
public:
  GameObject(const GameCoord&);
  virtual void Render() = 0;
  void SetPos(const GameCoord&);
  GameCoord GetPos() const;
};

#endif
