#ifndef HEADER_GAME_COORD
#define HEADER_GAME_COORD

#include <cstdint>

class GameCoord
{
private:
  GameCoord();

  int32_t x;
  int32_t y;

protected:

public:
  GameCoord(int32_t, int32_t);
  GameCoord(const GameCoord&);

  void operator =(const GameCoord& other);
  bool operator ==(const GameCoord&) const;
  bool operator !=(const GameCoord&) const;

  int32_t GetX() const;
  int32_t GetY() const;
  void SetX(const int32_t);
  void SetY(const int32_t);
};

#endif
