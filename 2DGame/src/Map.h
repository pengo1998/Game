#pragma once

#include "Game.h"
#include "TextureManager.h"

class Map {
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();
private:
	SDL_Rect _srcRect, _destRect;
	SDL_Texture* _dirt;
	SDL_Texture* _grass;
	SDL_Texture* _water;
	int map[20][25];
};
