#ifndef HEADER_GAME_NVM_CFG
#define HEADER_GAME_NVM_CFG

#include <stdint.h>

#define GAME_NVM_SIZE (1024u)
#define GAME_NVM_FILE_NAME "nvm.bin"

typedef enum
{
  GAME_PARAM_BLOCK = 0,
  NUM_NVM_BLOCKS
} GAME_NvmBlocks;

#endif