#include "Sprite.h"

Sprite::Sprite()
{
	posX = 0;
	posY = 0;
	_isLoaded = false;
	_textureRect = { 0,0,0,0 };
	_texture = NULL;
}

Sprite::~Sprite()
{
	posX = 0;
	posY = 0;
	_isLoaded = false;
	_texture = NULL;
}

void Sprite::setTexture(Texture * text)
{
	_texture = text;
	_isLoaded = true;
	_textureRect.w = _texture->get_width();
	_textureRect.h = _texture->get_height();
	return;
}

void Sprite::setTextureRect(SDL_Rect rect)
{
	_textureRect = rect;
}

void Sprite::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

void Sprite::render()
{
	if (!_isLoaded)
		return;
	_texture->render(posX, posY, &_textureRect);
}