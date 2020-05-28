#include "GameObject.h"

GameObject::GameObject(const char* textureSheet)
	: _srcRect(), _destRect(), _scale(2.0f, 2.0f) // Initialize scale and rect values
{
	_objTexture = TextureManager::LoadTexture(textureSheet); // Load the texture for the object
	if (_objTexture == nullptr) {	// Make sure we actually got a texture
		Logger::Err("Failed to create object texture.");
		Logger::Err(SDL_GetError());
		cleanup(_objTexture);
		return;
	}
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	_srcRect.w = 32; // Set the width and height of the texture area we want
	_srcRect.h = 32; 
	_srcRect.x = 0;  // Set the starting position in the texture we want
	_srcRect.y = 0;  // This will start at the top left most of the texture and take a 32x32 pixel area from it

	_destRect.w = _srcRect.w * _scale.x;	// Scale our texture according to the scale settings
	_destRect.h = _srcRect.h * _scale.y;
	_destRect.x = _position.x;				// Set the position of the texture according to the object's position
	_destRect.y = _position.y;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::Renderer, _objTexture, &_srcRect, &_destRect);	// Draw the texture to the screen
}

void GameObject::SetScale(float w, float h) // Set the object's scale
{
	_scale.x = w;
	_scale.y = h;
}

void GameObject::SetScale(Vec2<float> scale) // Set the object's scale overload
{
	SetScale(scale.x, scale.y);
}

void GameObject::SetPosition(int x, int y) // Set object position
{
	_position.x = x;
	_position.y = y;
}

void GameObject::SetPosition(Vec2<int> pos) // Set object position overload
{
	SetPosition(pos.x, pos.y);
}

void GameObject::Move(int x, int y) // Move the object relative to current position
{
	_position.x += x;
	_position.y += y;
}

void GameObject::Move(Vec2<int> mov) // Move the object relative to current position overload
{
	Move(mov.x, mov.y);
}
