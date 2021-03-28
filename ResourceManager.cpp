#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	_isLoaded = false;
	_texture = NULL;
}

ResourceManager::~ResourceManager()
{
	//delete all memory
	for (unsigned int i = 0; i < _objects.size(); ++i)
	{
		delete _objects[i];
		_objects[i] = NULL;
	}
}

void ResourceManager::add(std::string objName)
{
	if (!_isLoaded)
		return;
	if (objName == "player")
	{
		VisibleObject* obj = new Player;
		obj->load(_texture);
		_objects.push_back(obj);
	}
}

void ResourceManager::load(Texture * text)
{
	_texture = text;
	_isLoaded = true;
}

void ResourceManager::processInput(const Uint8* currentKeyStates)
{
	for (unsigned int i = 0; i < _objects.size(); ++i)
		_objects[i]->processInput(currentKeyStates);
}


void ResourceManager::update(float dt)
{
	//Update all objects
	for (unsigned int i = 0; i < _objects.size(); ++i)
		_objects[i]->update(dt);
	//Remove all dead objects
	for (unsigned int i = 0; i < _objects.size(); ++i)
		if (_objects[i]->isDead())
		{
			delete _objects[i];
			_objects[i] = NULL;
		}
	_objects.erase(std::remove_if(_objects.begin(),
		_objects.end(),
		[](VisibleObject* x) {return x == NULL; }), _objects.end());
}

void ResourceManager::render()
{
	for (unsigned int i = 0; i < _objects.size(); ++i)
		_objects[i]->render();
}