#ifndef HEADER_GAME_DEBUG
#define HEADER_GAME_DEBUG

#include <stdio.h>
#include <stdbool.h>

typedef enum
{
  DEBUG_NORMAL = 0,
  DEBUG_FAILED
} DEBUG_State;

void DEBUG_setState(DEBUG_State newState);
DEBUG_State DEBUG_getState(void);

#define DEBUG_ASSERT(this, that) \
if (this != that) \
{ \
  (void) printf("%s:%u - ASSERT FAILED: %s != %s\n", __FILE__, __LINE__, #this, #that); \
  DEBUG_setState(DEBUG_FAILED); \
} \

#endif
