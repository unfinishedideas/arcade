#pragma once
#include "imports.h"
#include "Sprite.h"

class VisibleObject
{
public:
	VisibleObject();
	VisibleObject(std::string id);
	virtual ~VisibleObject() {}
	virtual void render();
	virtual void load(Texture* text);
	virtual void processInput(const Uint8* currentKeyStates);
	virtual void update(float dt);
	std::string getID();
	void setID(std::string id);
	void setDead();
	bool isDead();
private:
	std::string _id;
	bool _isDead;
};