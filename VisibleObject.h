#pragma once
#include "imports.h"
#include "Sprite.h"

class VisibleObject
{
public:
	VisibleObject();
	~VisibleObject();
	virtual void render();
	virtual void update(float dt);
private:
	//int posX, posY;
};