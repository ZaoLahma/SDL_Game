#ifndef HEADER_GAME_NVM_TYPES
#define HEADER_GAME_NVM_TYPES

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
  char*    nvmStartAddr;
  uint32_t nvmSize;
  bool     dirty;
} GAME_NvmBlock;

#endif
