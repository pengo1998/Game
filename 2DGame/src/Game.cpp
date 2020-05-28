#include "Game.h"

GameObject* player;
Map* map;

SDL_Renderer* Game::Renderer = nullptr;

Game::~Game()
{
}

void Game::Init(const char* title, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {	// Initialize SDL and check for an error
		Logger::Err("Failed to initialize SDL.");	// Got an error so log it to console and return
		Logger::Err(SDL_GetError());
		return;
	}
	Logger::Inf("SDL Initialized");	// Log successful initialization of SDL
	
	UINT32 flags = SDL_WINDOW_SHOWN;			// Create our windows flag variable and add the shown flag
	if (fullscreen) {
		flags = flags | SDL_WINDOW_FULLSCREEN;	// If enabled in init make the window fullscreen by binary and with the fullscreen flag
	}

	_window = SDL_CreateWindow("2DEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags ); // Create the window with given name, size, and flags and always center the window
	if (_window == nullptr) {	// Check if there was an error creating window
		Logger::Err("Failed to create window.");	// Log error, quit SDL, and return
		Logger::Err(SDL_GetError());
		SDL_Quit();
		return;
	}
	Logger::Inf("Window created"); // Log successfull creation of window

	Renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Create our renderer
	if (Renderer == nullptr) {	// Check for error creating renderer
		Logger::Err("Failed to create renderer.");	// Log error, cleanup window, quit SDL, and return
		Logger::Err(SDL_GetError());
		cleanup(_window);
		SDL_Quit();
		return;
	}
	Logger::Inf("Renderer created"); // Log successfull creation of renderer
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);	// Set our renderer clear color to white

	player = new GameObject("res/spong.png");
	map = new Map();

	_running = true;	// if everything whent as planned set running to true so the game will run instead of insatntly closing
}

void Game::HandleEvents()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {	// Get the oldest event
		switch (evnt.type) {	// Switch on the event type
		case SDL_QUIT:			// Check if user is closing window
			_running = false;	// If they're closing window set running to false so it breaks out of the game loop
			break;
		case SDL_KEYDOWN:
			if (evnt.key.keysym.sym == SDLK_RIGHT) { player->Move(5, 0); }
			if (evnt.key.keysym.sym == SDLK_LEFT) { player->Move(-5, 0); }
			if (evnt.key.keysym.sym == SDLK_UP) { player->Move(0, -5); }
			if (evnt.key.keysym.sym == SDLK_DOWN) { player->Move(0, 5); }
			break;
		default:
			break;
		}
	}
}

void Game::Update()
{
	_count++;				// Keep track of how many frames have been created

	player->Update();

	//std::cout << _count << std::endl;
}

void Game::Render()
{
	SDL_RenderClear(Renderer);		// Clear the renderer

	map->DrawMap();
	player->Render();

	SDL_RenderPresent(Renderer);	// Present the renderer
}

void Game::Cleanup()
{
	cleanup(_window, Renderer);	// Cleanup window and renderer
	SDL_Quit();						// Quit SDL
	Logger::Inf("Game destroyed");	// Log that the game object has been destroyed
}
