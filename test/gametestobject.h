#ifndef HEADER_GAME_TEST_OBJECT
#define HEADER_GAME_TEST_OBJECT

#include "gametestfwk.h"
#include "gameobject.h"

class GameObjectForTest : public GameObject
{
private:

protected:

public:
  GameObjectForTest(const GameCoord&);
  void Render();
};

class GameTestObject : public GameTestSuite
{
private:
  static bool TestGetAndSet();

protected:

public:
  GameTestObject();
  bool Execute();
};

#endif
