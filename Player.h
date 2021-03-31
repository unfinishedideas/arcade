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
	void setPos(floatVec _pos);
private:
	Sprite _sprite;
	floatVec pos;
	floatVec vel;
	bool _isLoaded;
	float frameTime;
};