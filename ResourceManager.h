#pragma once
#include "VisibleObject.h"
#include <vector>


class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void add(VisibleObject* vis);
	void load(Texture * text);
	void processInput(const Uint8* currentKeyStates);
	void update(float dt);
	void render();
private:
	std::vector<VisibleObject*> _objects;
};
