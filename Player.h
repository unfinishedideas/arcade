#pragma once
#include "VisibleObject.h"
#include "Sprite.h"


class Player : public VisibleObject
{
public:
	Player();
	~Player();
	
	void load(Texture* text);
	void render();
private:
	Sprite _sprite;
	int posX, posY;
	bool _isLoaded;
};