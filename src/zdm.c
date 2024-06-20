#include "zdm.h"
#include "cpu.h"
#include "memory.h"
#include "test.h"

bool running = true;

int main(int argc, char **argv) {
	#ifdef DEBUG
    debug(argc, argv); 
    #endif

	#ifndef DEBUG
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
	#endif
}

bool init_gameboy(char *rom) {
	struct registers r;
	registers = r;
	if (!load_rom(rom)) {
		return false;
	}

	return true;
}

void exit_gameboy() {
}
