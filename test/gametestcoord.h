#ifndef HEADER_GAME_TEST_COORD
#define HEADER_GAME_TEST_COORD

#include "gametestfwk.h"

class GameTestCoord : public GameTestSuite
{
private:
  bool TestCtor();
  bool TestCopyCtor();

protected:

public:
  GameTestCoord();
  bool Execute();
};

#endif
