#include "game_nvm.h"
#include "game_nvm_cfg.h"
#include "game_nvm_types.h"
#include <string.h>
#include <stdio.h>

extern GAME_NvmBlock nvmBlocks[NUM_NVM_BLOCKS];

static uint8_t nvmRamMirror[GAME_NVM_SIZE];
static FILE* nvmFile;

void NVM_init(void)
{
  (void) memset(nvmRamMirror, 0u, sizeof(nvmRamMirror));

  nvmFile = fopen(GAME_NVM_FILE_NAME, "rb");

  fclose(nvmFile);
}
