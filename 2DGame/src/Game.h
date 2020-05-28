#pragma once

#include <SDL\SDL.h>
#include <SDL\SDL_image.h>

#include "TextureManager.h"
#include "GameObject.h"
#include "Logger.h"
#include "cleanup.h"
#include "Map.h"

class Game {
public:
	Game()
		: _running(false), _count(0), _window(nullptr) {};
	~Game();

	void Init(const char* title, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Cleanup();

	bool IsRunning() { return _running; }

	static SDL_Renderer* Renderer;
private:
	int _count;
	bool _running;
	SDL_Window* _window;
};
