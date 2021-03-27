#pragma once
#include "imports.h"
#include "Texture.h"

class Sprite
{
public:
	Sprite();
	~Sprite();
	void setTexture(Texture *texture);
	void setTextureRect(SDL_Rect rect);
	void setPosition(float x, float y);
	void setAngle(double angle);
	void setZoom(double zoom);
	void setFlip(SDL_RendererFlip flip);
	double getAngle();
	double getZoom();
	SDL_RendererFlip getFlip();

	void render();
private:
	Texture * _texture;
	SDL_Rect _textureRect;
	SDL_RendererFlip _flip;
	int posX, posY;
	bool _isLoaded;
	double _angle;
	double _zoom;
};