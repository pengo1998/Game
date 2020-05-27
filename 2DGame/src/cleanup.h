#pragma once

#include <utility>

#include <SDL.h>

// Defines a function that can take mandatory 1 argument and minimum of 1 extra argument
template<typename T, typename... Args>
void cleanup(T* t, Args&&... args) {
	cleanup(t); // run the cleanup function for the first argument
	cleanup(std::forward<Args>(args)...); // pass the remaining arguments back into cleanup
}

template<>
inline void cleanup<SDL_Window>(SDL_Window* window) {
	if (!window) { return; }
	SDL_DestroyWindow(window);
}

template<>
inline void cleanup<SDL_Renderer>(SDL_Renderer* renderer) {
	if (!renderer) { return; }
	SDL_DestroyRenderer(renderer);
}

template<>
inline void cleanup<SDL_Surface>(SDL_Surface* surface) {
	if (!surface) {	return; }
	SDL_FreeSurface(surface);
}

template<>
inline void cleanup<SDL_Texture>(SDL_Texture* texture) {
	if (!texture) {	return; }
	SDL_DestroyTexture(texture);
}