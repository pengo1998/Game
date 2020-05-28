#pragma once

#include "Game.h"
#include "Logger.h"
#include "cleanup.h"

static class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
private:
};