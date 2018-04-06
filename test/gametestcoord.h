#ifndef HEADER_GAME_TEST_COORD
#define HEADER_GAME_TEST_COORD

#include "gametestfwk.h"

class GameTestCoord : public GameTestSuite
{
private:
  static bool TestCtor();
  static bool TestCopyCtor();
  static bool TestAssigmentAndComparisonOperator();
  static bool TestGetAndSet();

protected:

public:
  GameTestCoord();
  bool Execute();
};

#endif
