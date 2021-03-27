#pragma once
#include "VisibleObject.h"
#include "Sprite.h"


class Player : public VisibleObject
{
public:
	Player();
	~Player();
	void processInput(const Uint8* currentKeyStates);
	void update(float dt);
	void load(Texture* text);
	void render();
private:
	Sprite _sprite;
	int posX, posY;
	float velX, velY;
	bool _isLoaded;
	
};