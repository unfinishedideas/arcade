#pragma once

#include "Texture.h"
#include "core.h"

class Sprite
{
public:
	Sprite();
	~Sprite();
	void setTexture(Texture *texture);
	void setTextureRect(SDL_Rect rect);
	void setPosition(floatVec pos);
	void setAngle(double angle);
	void setZoom(double zoom);
	void setFlip(SDL_RendererFlip flip);
	void setAlpha(Uint8 alpha);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	double getAngle();
	double getZoom();
	Uint8 getAlpha();
	SDL_RendererFlip getFlip();
	SDL_Rect getTextureRect();
	void render();
private:
	Texture * _texture;
	SDL_Rect _textureRect;
	SDL_RendererFlip _flip;
	int posX, posY;
	bool _isLoaded;
	double _angle;
	double _zoom;
	Uint8 _alpha, _red,_green,_blue;
};