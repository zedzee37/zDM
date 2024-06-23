#include "zdm.h"
#include "memory.h"
#include "registers.h"
#include "debugger.h"
#include "cpu.h"
#include "util.h"
#include <stdlib.h>
#include <string.h>

bool running = true;

int main(int argc, char **argv) {
	#ifdef DEBUGF
    return debug(argc, argv); 
    #endif

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create window
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
	SDL_Window *window = SDL_CreateWindow("zDM", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH*TARGET_SCALE, SCREEN_HEIGHT*TARGET_SCALE,
			SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


	if (window == NULL) {
		SDL_LogError(0, "Window could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	init_gameboy(argv[1]);

	// Event handler
	SDL_Event event;

	// Main loop
	while (running) {
		// Check for events
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = 0;
			}
		}

		// Clear the window (replace with your rendering logic)
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer); 
		// Update the screen
		// SDL_RenderPresent(surface);

		SDL_RenderPresent(renderer);
	}

	// Cleanup
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	exit_gameboy();

	return 0;
}

int debug(int argc, char *argv[]) {
    init_gameboy(argv[1]);
    return 0;
}

bool init_gameboy(char *rom) {
    union Memory mem;
    memset(mem.memory, 0, 0xffff);

    if (!read_rom(&mem, rom)) {
        return false;
    }

    struct Registers registers;
    struct Cpu cpu = { .mem = &mem, .registers = &registers };
    struct Debugger dbgr = { .step = 0, .cpu = &cpu };
    
    print_region(mem.program, 0, 0xf);
    print_registers(&registers);
	return true;
}

void exit_gameboy() {
}
