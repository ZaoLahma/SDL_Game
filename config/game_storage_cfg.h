#ifndef HEADER_GAME_STORAGE_CFG
#define HEADER_GAME_STORAGE_CFG

#include <stdint.h>

#define GAME_STORAGE_SIZE (1024u)
#define GAME_STORAGE_FILE_NAME "nvm.bin"

typedef enum
{
  GAME_PARAM_BLOCK = 0,
  NUM_STORAGE_BLOCKS
} GAME_StorageBlocks;

#endif
