#ifndef HEADER_GAME_NVM_CFG
#define HEADER_GAME_NVM_CFG

#include <stdint.h>
#include "game_nvm_types.h"

#define GAME_NVM_SIZE (1024u)
#define GAME_NVM_FILE_NAME "nvm.bin"

typedef enum
{
  GAME_PARAM_BLOCK = 0,
  NUM_NVM_BLOCKS
} GAME_NvmBlocks;

static GAME_NvmBlock nvmBlocks[NUM_NVM_BLOCKS] =
{
  {0u, 8u}
};

#endif
