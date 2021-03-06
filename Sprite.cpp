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
	_flip = SDL_FLIP_NONE;
	_alpha = 255;
	_red = 255;
	_green = 255;
	_blue = 255;
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

void Sprite::setPosition(floatVec pos)
{
	posX = int(pos.x);
	posY = int(pos.y);
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

void Sprite::setAlpha(Uint8 alpha)
{
	_alpha = alpha;
}

Uint8 Sprite::getAlpha()
{
	return _alpha;
}

void Sprite::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	_red = red;
	_green = green;
	_blue = blue;
}

void Sprite::render()
{
	if (!_isLoaded)
		return;
	if (_alpha != 255)
	{
		_texture->setBlendMode(SDL_BLENDMODE_BLEND);
		_texture->setAlpha(_alpha);
	}
	if (_red != 255 || _green != 255 || _blue != 255)
	{
		_texture->setColor(_red, _green, _blue);
	}
	_texture->render(posX, posY, &_textureRect, _zoom,_angle, NULL, _flip);
	if (_alpha != 255)
	{
		_texture->setBlendMode(SDL_BLENDMODE_NONE);
		_texture->setAlpha(255);
	}
	if (_red != 255 || _green != 255 || _blue != 255)
	{
		_texture->setColor(255, 255, 255);
	}
}

SDL_Rect Sprite::getTextureRect()
{
	return _textureRect;
}