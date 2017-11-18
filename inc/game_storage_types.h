#ifndef HEADER_GAME_STORAGE_TYPES
#define HEADER_GAME_STORAGE_TYPES

#include <stdint.h>
#include "game_storage_cfg.h"

typedef struct
{
  GAME_StorageBlocks storageType;
  uint32_t           storageStartAddr;
  uint32_t           storageSize;
} GAME_StorageBlock;

#endif
