#include "sdl_game_test.h"
#include "game_nvm.h"
#include "game_debug.h"
#include <stdio.h>

static void TEST_nvm(void);

static void TEST_nvm(void)
{
    DEBUG_ASSERT(1, 0);
    NVM_init();
}

void TEST_run(void)
{
  (void) printf("TEST START\n");

  TEST_nvm();

  DEBUG_State state = DEBUG_getState();

  if(DEBUG_NORMAL == state)
  {
    (void) printf("TEST SUCCEEDED\n");
  }
  else
  {
    (void) printf("TEST FAILED\n");
  }
}
