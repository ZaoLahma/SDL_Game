#ifndef HEADER_GAME_TEST_FWK
#define HEADER_GAME_TEST_FWK

#include <string>
#include <vector>

class GameTestCase
{
private:
  GameTestCase();
  std::string testCaseName;

protected:

public:
  GameTestCase(std::string&);
  std::string GetTestCaseName() const;

  virtual bool Execute() = 0;
};

typedef std::vector<GameTestCase*> GameTestCaseVector;

class GameTestFwk
{
private:
  GameTestFwk();
  GameTestCaseVector testCases;
  static GameTestFwk* instance;
protected:
public:
  static GameTestFwk* GetApi();
  void AddTestCase(GameTestCase*);
  void DropInstance();
};

#endif
