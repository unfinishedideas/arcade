#pragma once
#include "VisibleObject.h"
#include "Player.h"
#include <vector>


class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void add(std::string objName);
	void load(Texture * text);
	void processInput(const Uint8* currentKeyStates);
	void update(float dt);
	void render();
private:
	std::vector<VisibleObject*> _objects;
	Texture* _texture;
	bool _isLoaded;
};
