#pragma once
#include "VisibleObject.h"
#include "Texture.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <algorithm>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void add(std::string objName);
	void add(VisibleObject* obj);
	void load(std::string texturePath, SDL_Renderer* renderer);
	void processInput(const Uint8* currentKeyStates);
	void update(float dt);
	void render();
private:
	std::vector<VisibleObject*> _objects;
	Texture* _texture;
	bool _isLoaded;
};
