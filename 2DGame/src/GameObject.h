#pragma once

#include <SDL\SDL.h>

#include "Game.h"
#include "TextureManager.h"
#include "Logger.h"
#include "cleanup.h"
#include "Vec2.h"

class GameObject {
public:
	GameObject(const char* textureSheet);
	~GameObject();

	void Update();
	void Render();

	void SetScale(float w, float h);
	void SetScale(Vec2<float> scale);
	void SetPosition(int x, int y);
	void SetPosition(Vec2<int> pos);
	void Move(int x, int y);
	void Move(Vec2<int> mov);
private:
	Vec2<int> _position;
	Vec2<float> _scale;

	SDL_Texture* _objTexture;
	SDL_Rect _srcRect, _destRect;
};