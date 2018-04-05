#ifndef HEADER_GAME_TEST_FWK
#define HEADER_GAME_TEST_FWK

#include <string>
#include <vector>

class GameTestSuite
{
private:
  GameTestSuite();
  std::string testCaseName;

protected:

public:
  GameTestSuite(const std::string&);
  std::string GameTestSuiteName() const;

  virtual bool Execute() = 0;
};

typedef std::vector<GameTestSuite*> GameTestSuiteVector;

class GameTestFwk
{
private:
  GameTestFwk();
  GameTestSuiteVector testCases;
  static GameTestFwk* instance;
protected:
public:
  static const uint32_t TESTS_PASSED = 0;
  static const uint32_t TESTS_FAILED = 1;
  static GameTestFwk* GetApi();
  void AddTestCase(GameTestSuite*);
  uint32_t ExecuteTestCases();
  void DropInstance();
};

#endif
