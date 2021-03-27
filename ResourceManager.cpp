#include "ResourceManager.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::add(VisibleObject* vis)
{
	_objects.push_back(vis);
}

void ResourceManager::load(Texture * text)
{
	for (unsigned int i = 0; i < _objects.size(); ++i)
		_objects[i]->load(text);
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