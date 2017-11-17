#include "game_nvm.h"
#include "game_nvm_cfg.h"
#include "game_nvm_int.h"
#include "game_debug.h"
#include <string.h>
#include <stdio.h>

static FILE* nvmFile;

static uint8_t nvmRamMirror[GAME_NVM_SIZE];

static void writeBlock(const GAME_NvmBlock* block);

static void writeBlock(const GAME_NvmBlock* block)
{
  fseek(nvmFile, block->nvmStartAddr, SEEK_SET);

  fwrite(&nvmRamMirror[block->nvmStartAddr],
                       block->nvmSize,
                       1,
                       nvmFile);
}

void NVM_init(void)
{
  nvmFile = fopen(GAME_NVM_FILE_NAME, "rb");

  if(nvmFile)
  {
    uint32_t i = 0u;
    for(; i < NUM_NVM_BLOCKS; ++i)
    {
      fseek(nvmFile, nvmBlocks[i].nvmStartAddr, SEEK_SET);
			fread(&nvmRamMirror[nvmBlocks[i].nvmStartAddr], nvmBlocks[i].nvmSize, 1, nvmFile);
    }
    fclose(nvmFile);
  }

  nvmFile = fopen(GAME_NVM_FILE_NAME, "wb");
}

void NVM_deInit(void)
{
  fclose(nvmFile);
}

void NVM_writeBlock(const GAME_NvmBlocks block, uint8_t* data)
{
  uint32_t i = 0u;
  uint32_t indexToWrite = NUM_NVM_BLOCKS;
  for(; i < NUM_NVM_BLOCKS; ++i)
  {
    if(nvmBlocks[i].nvmType == block)
    {
      indexToWrite = i;
    }
  }

  DEBUG_ASSERT(indexToWrite, !NUM_NVM_BLOCKS);

  DEBUG_State state = DEBUG_getState();

  if(DEBUG_NORMAL == state)
  {
    GAME_NvmBlock* blockToWrite = &nvmBlocks[indexToWrite];
    memcpy(&nvmRamMirror[blockToWrite->nvmStartAddr],
           data,
           blockToWrite->nvmSize);

    writeBlock(blockToWrite);
  }
}

void NVM_getBlock(const GAME_NvmBlocks block, uint8_t* data)
{
  uint32_t i = 0u;
  uint32_t indexToRead = NUM_NVM_BLOCKS;
  for(; i < NUM_NVM_BLOCKS; ++i)
  {
    if(nvmBlocks[i].nvmType == block)
    {
      indexToRead = i;
    }
  }

  DEBUG_ASSERT(indexToRead, !NUM_NVM_BLOCKS);

  DEBUG_State state = DEBUG_getState();

  if(DEBUG_NORMAL == state)
  {
    GAME_NvmBlock* blockToRead = &nvmBlocks[indexToRead];
    (void) memcpy(data, &nvmRamMirror[blockToRead->nvmStartAddr], blockToRead->nvmSize);
  }
}
