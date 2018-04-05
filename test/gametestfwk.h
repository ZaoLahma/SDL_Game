#ifndef HEADER_GAME_TEST_FWK
#define HEADER_GAME_TEST_FWK

class GameTestFwk
{
private:
  GameTestFwk();
  static GameTestFwk* instance;
protected:
public:
  static GameTestFwk* GetApi();
  void DropInstance();
};

#endif
