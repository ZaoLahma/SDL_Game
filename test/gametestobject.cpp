#include "gametestobject.h"
#include "gamecoord.h"


GameObjectForTest::GameObjectForTest(const GameCoord& newPos) : GameObject(newPos)
{

}

void GameObjectForTest::Render()
{

}

GameTestObject::GameTestObject() : GameTestSuite("GameTestObject")
{
  testCases.push_back(GameTestCase("TestGetAndSet", GameTestObject::TestGetAndSet));
}

bool GameTestObject::TestGetAndSet()
{
  bool testCaseResult = true;

  GameCoord pos(200, 200);

  GameObjectForTest testObject(pos);

  testCaseResult = (pos == testObject.GetPos());

  pos.SetX(400);

  testObject.SetPos(pos);

  testCaseResult = testCaseResult && (pos == testObject.GetPos());

  return testCaseResult;
}
