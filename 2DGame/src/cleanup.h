#pragma once

#include <utility>

#include <SDL\SDL.h>

// Defines a function that takes 2 minimum arguments and pass arguments 2+ on to itself after running one of the single argument overrides on the first
template<typename T, typename... Args>
void cleanup(T* t, Args&&... args) {
	cleanup(t); // run the cleanup function for the first argument
	cleanup(std::forward<Args>(args)...); // pass the remaining arguments back into cleanup
}

template<>
inline void cleanup<SDL_Window>(SDL_Window* window) {
	if (!window) { return; }
	SDL_DestroyWindow(window);
	window = nullptr;
}

template<>
inline void cleanup<SDL_Renderer>(SDL_Renderer* renderer) {
	if (!renderer) { return; }
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

template<>
inline void cleanup<SDL_Surface>(SDL_Surface* surface) {
	if (!surface) {	return; }
	SDL_FreeSurface(surface);
	surface = nullptr;
}

template<>
inline void cleanup<SDL_Texture>(SDL_Texture* texture) {
	if (!texture) {	return; }
	SDL_DestroyTexture(texture);
	texture = nullptr;
}