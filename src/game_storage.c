#include "game_storage.h"
#include "game_storage_cfg.h"
#include "game_storage_int.h"
#include "game_debug.h"
#include <string.h>
#include <stdio.h>

static FILE* storageFile;

static uint8_t storageRamMirror[GAME_STORAGE_SIZE];

static void writeBlock(const GAME_StorageBlock* block);

static void writeBlock(const GAME_StorageBlock* block)
{
  fseek(storageFile, block->storageStartAddr, SEEK_SET);

  fwrite(&storageRamMirror[block->storageStartAddr],
                       block->storageSize,
                       1,
                       storageFile);
}

void STORAGE_init(void)
{
  storageFile = fopen(GAME_STORAGE_FILE_NAME, "rb");

  if(storageFile)
  {
    uint32_t i = 0u;
    for(; i < NUM_STORAGE_BLOCKS; ++i)
    {
      fseek(storageFile, storageBlocks[i].storageStartAddr, SEEK_SET);
			fread(&storageRamMirror[storageBlocks[i].storageStartAddr], storageBlocks[i].storageSize, 1, storageFile);
    }
    fclose(storageFile);
  }

  storageFile = fopen(GAME_STORAGE_FILE_NAME, "wb");
}

void STORAGE_deInit(void)
{
  fclose(storageFile);
}

void STORAGE_writeBlock(const GAME_StorageBlocks block, uint8_t* data)
{
  uint32_t i = 0u;
  uint32_t indexToWrite = NUM_STORAGE_BLOCKS;
  for(; i < NUM_STORAGE_BLOCKS; ++i)
  {
    if(storageBlocks[i].storageType == block)
    {
      indexToWrite = i;
    }
  }

  DEBUG_ASSERT(indexToWrite, !NUM_STORAGE_BLOCKS);

  DEBUG_State state = DEBUG_getState();

  if(DEBUG_NORMAL == state)
  {
    GAME_StorageBlock* blockToWrite = &storageBlocks[indexToWrite];
    memcpy(&storageRamMirror[blockToWrite->storageStartAddr],
           data,
           blockToWrite->storageSize);

    writeBlock(blockToWrite);
  }
}

void STORAGE_getBlock(const GAME_StorageBlocks block, uint8_t* data)
{
  uint32_t i = 0u;
  uint32_t indexToRead = NUM_STORAGE_BLOCKS;
  for(; i < NUM_STORAGE_BLOCKS; ++i)
  {
    if(storageBlocks[i].storageType == block)
    {
      indexToRead = i;
    }
  }

  DEBUG_ASSERT(indexToRead, !NUM_STORAGE_BLOCKS);

  DEBUG_State state = DEBUG_getState();

  if(DEBUG_NORMAL == state)
  {
    GAME_StorageBlock* blockToRead = &storageBlocks[indexToRead];
    (void) memcpy(data, &storageRamMirror[blockToRead->storageStartAddr], blockToRead->storageSize);
  }
}
