#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* surface = IMG_Load(fileName);	// Use the SDL_Image library to load the specified texture
	if (surface == nullptr) {	// Make sure we actually loaded the texture
		Logger::Err("Failed to create surface for texture creation.");
		Logger::Err(SDL_GetError());
		cleanup(surface);
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::Renderer, surface); // Create an SDL_Texture object from the surface texture
	if (texture == nullptr) {	// Error checking
		Logger::Err("Failed to create texture.");
		Logger::Err(SDL_GetError());
		cleanup(texture, surface);
		return nullptr;
	}
	cleanup(surface); // Get rid of the no longer needed SDL_Surface object

	return texture; // Return the created SDL_Texture
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::Renderer, texture, &src, &dest);
}
