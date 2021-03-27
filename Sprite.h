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
	void setPosition(int x, int y);
	void render();
private:
	Texture * _texture;
	SDL_Rect _textureRect;
	int posX, posY;
	bool _isLoaded;
};