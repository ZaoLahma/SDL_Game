#ifndef HEADER_GAME_STORAGE
#define HEADER_GAME_STORAGE

#include "game_storage_types.h"
#include <stdint.h>

void STORAGE_init(void);

void STORAGE_deInit(void);

void STORAGE_writeBlock(const GAME_StorageBlocks block, uint8_t* data);

void STORAGE_getBlock(const GAME_StorageBlocks block, uint8_t* data);

#endif
