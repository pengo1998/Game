#define WAIT std::cin.get();
#define SDL_MAIN_HANDLED

#include <SDL\SDL.h>

#include "Logger.h"
#include "cleanup.h"
#include "Game.h"

int main(int argc, const char* argv[])
{
	Logger::Init();				// Initialize logger
	
	int targetFPS = 60;
	int frameDelay = 1000 / targetFPS;
	Uint32 frameStart;
	int frameTime;

	Uint32 lastFrame = SDL_GetTicks();
	int framesSinceLast = 0;

	Game* game = new Game();				// Create the game engine
	game->Init("RPG Game", 800, 640, false);	// Initialize the game engine

	while (game->IsRunning()) {					// Main game loop
		frameStart = SDL_GetTicks();			// Get how many ms since initialization of SDL
		game->HandleEvents();					// Handle any events
		game->Update();							// Update object locations
		game->Render();							// Render to the screen

		frameTime = SDL_GetTicks() - frameStart;// Check how many ms the frame took
		if (frameDelay > frameTime) {			// If expected frame time is more than the time the frame took
			SDL_Delay(frameDelay - frameTime);  // wait however long is needed to pad out the frame time
		}

		if (lastFrame + 1000 <= SDL_GetTicks()) {		// if its been 1 second since last frame check
			std::cout << framesSinceLast << std::endl;	// output the number of frames that occured
			lastFrame = SDL_GetTicks();					// Set the last frame check to now
			framesSinceLast = 0;						// Set number of frames to 0
		}
		else {
			framesSinceLast++;							// Increment number of frames
		}
	}

	game->Cleanup();							// Cleanup our game object
	game = nullptr;								//
	return 0;
}