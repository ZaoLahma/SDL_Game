#include "game_debug.h"

static DEBUG_State state = DEBUG_NORMAL;

void DEBUG_setState(DEBUG_State newState)
{
  state = newState;
}

DEBUG_State DEBUG_getState(void)
{
  return state;
}
