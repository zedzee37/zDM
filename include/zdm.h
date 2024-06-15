#include <stdint.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 144
#define TARGET_SCALE 7

extern bool init_gameboy(char *rom);
extern void exit_gameboy();
