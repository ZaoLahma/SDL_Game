#include "game_nvm.h"
#include "game_nvm_cfg.h"
#include "game_nvm_int.h"
#include <string.h>
#include <stdio.h>

static FILE* nvmFile;

static uint8_t nvmRamMirror[GAME_NVM_SIZE];

static void writeBlock(const GAME_NvmBlock* block);

static void writeBlock(const GAME_NvmBlock* block)
{
  fseek(nvmFile, block->nvmStartAddr, SEEK_SET);
  fwrite(&nvmRamMirror[block->nvmStartAddr], block->nvmSize, 1, nvmFile);
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
  uint32_t i = 0u;
  for(; i < NUM_NVM_BLOCKS; ++i)
  {
    writeBlock(&nvmBlocks[i]);
  }

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

  if(NUM_NVM_BLOCKS != indexToWrite)
  {
    GAME_NvmBlock* blockToWrite = &nvmBlocks[indexToWrite];
    memcpy(&nvmRamMirror[blockToWrite->nvmStartAddr],
           data,
           blockToWrite->nvmSize);

    writeBlock(blockToWrite);
  }
}
