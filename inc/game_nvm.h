#ifndef HEADER_GAME_NVM
#define HEADER_GAME_NVM

#include "game_nvm_types.h"
#include <stdint.h>

void NVM_init(void);

void NVM_deInit(void);

void NVM_writeBlock(const GAME_NvmBlocks block, uint8_t* data);

void NVM_getBlock(const GAME_NvmBlocks block, uint8_t* data);

#endif
