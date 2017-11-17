#ifndef HEADER_GAME_NVM_TYPES
#define HEADER_GAME_NVM_TYPES

#include <stdint.h>
#include "game_nvm_cfg.h"

typedef struct
{
  GAME_NvmBlocks nvmType;
  uint32_t       nvmStartAddr;
  uint32_t       nvmSize;
} GAME_NvmBlock;

#endif
