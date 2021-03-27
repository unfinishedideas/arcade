#include "Sprite.h"

Sprite::Sprite()
{
	posX = 0;
	posY = 0;
	_isLoaded = false;
	_textureRect = { 0,0,0,0 };
	_texture = NULL;
	_angle = 0.0;
	_zoom = 1.0;
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

void Sprite::setPosition(float x, float y)
{
	posX = int(x);
	posY = int(y);
}

void Sprite::setAngle(double angle)
{
	_angle = angle;
}

void Sprite::setZoom(double zoom)
{
	_zoom = zoom;
}

void Sprite::setFlip(SDL_RendererFlip flip)
{
	_flip = flip;
}

double Sprite::getAngle()
{
	return _angle;
}

double Sprite::getZoom()
{
	return _zoom;
}

SDL_RendererFlip Sprite::getFlip()
{
	return _flip;
}

void Sprite::render()
{
	if (!_isLoaded)
		return;
	_texture->render(posX, posY, &_textureRect, _zoom,_angle, NULL, _flip);
}