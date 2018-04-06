#ifndef HEADER_GAME_TEST_FWK
#define HEADER_GAME_TEST_FWK

#include <string>
#include <vector>
#include <functional>

typedef std::function<bool(void)> GameTestCaseFunction;

class GameTestCase
{
private:
  GameTestCase();
  const std::string testCaseName;
  GameTestCaseFunction testFunc;

protected:

public:
  GameTestCase(const std::string&, GameTestCaseFunction);
  bool Execute();
};

typedef std::vector<GameTestCase> GameTestCaseVector;

class GameTestSuite
{
private:
  GameTestSuite();
  std::string testSuiteName;

protected:
  GameTestCaseVector testCases;

public:
  GameTestSuite(const std::string&);
  std::string GameTestSuiteName() const;

  bool Execute();
};

typedef std::vector<GameTestSuite*> GameTestSuiteVector;

class GameTestFwk
{
private:
  GameTestFwk();
  GameTestSuiteVector testSuites;
  static GameTestFwk* instance;
protected:
public:
  static const uint32_t TESTS_PASSED = 0;
  static const uint32_t TESTS_FAILED = 1;
  static GameTestFwk* GetApi();
  void AddTestSuite(GameTestSuite*);
  uint32_t ExecuteTestCases();
  void DropInstance();
};

#endif
