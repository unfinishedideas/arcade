#pragma once
#include "imports.h"
#include "Sprite.h"

class VisibleObject
{
public:
	VisibleObject();
	VisibleObject(std::string id);
	~VisibleObject();
	virtual void render();
	virtual void processInput(const Uint8* currentKeyStates);
	virtual void update(float dt);
	std::string getID();
	void setID(std::string id);
private:
	std::string _id;
};