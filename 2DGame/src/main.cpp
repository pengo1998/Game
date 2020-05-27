#define WAIT std::cin.get();
#define SDL_MAIN_HANDLED

#include <SDL.h>

#include "Logger.h"
#include "cleanup.h"

int main()
{
	Logger log = Logger("Log.txt");

	log.Inf("Info test.");
	log.War("Warning test.");
	log.Err("Error test.");
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		log.Err("Failed to initialize SDL.");
		log.Err(SDL_GetError());
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("2DEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		log.Err("Failed to create SDL window.");
		log.Err(SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		log.Err("Failed to create SDL renderer.");
		log.Err(SDL_GetError());
		cleanup(window);
		SDL_Quit();
		return 1;
	}

	bool running = true;
	while (running) {
		SDL_Event evnt;
		while (SDL_PollEvent(&evnt)) {
			switch (evnt.type) {
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}
		}


		SDL_Delay(10);
	}


	cleanup(renderer, window);
	SDL_Quit();
	
	log.Inf("End of program.");

	WAIT;
	return 0;
}