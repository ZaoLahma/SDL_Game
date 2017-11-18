#include "sdl_game_test.h"
#include "game_storage.h"
#include "game_debug.h"
#include <stdio.h>
#include <string.h>

#define STORAGE_GAME_PARAM_BLOCK_SIZE (8u)

static void TEST_assertDebugState(void);

static void TEST_storage(void);

static void TEST_assertDebugState(void)
{
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

static void TEST_storage(void)
{
    STORAGE_init();
    uint8_t testParam[STORAGE_GAME_PARAM_BLOCK_SIZE] = {0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF};
    STORAGE_writeBlock(GAME_PARAM_BLOCK, testParam);

    uint8_t testParamToVerify[STORAGE_GAME_PARAM_BLOCK_SIZE] = "";
    STORAGE_getBlock(GAME_PARAM_BLOCK, testParamToVerify);

    DEBUG_ASSERT(memcmp(testParam, testParamToVerify, STORAGE_GAME_PARAM_BLOCK_SIZE), 0);

    STORAGE_deInit();
}

void TEST_run(void)
{
  (void) printf("TEST START\n");

  TEST_storage();

  TEST_assertDebugState();
}
