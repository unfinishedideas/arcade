#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	_isLoaded = false;
	_texture = NULL;
}

ResourceManager::~ResourceManager()
{
	//delete memory
	/*for (unsigned int i = 0; i < _objects.size(); ++i)
	{
		delete _objects[i];
		_objects[i] = NULL;
	}*/
	//int i = 1;
	std::for_each(_objects.begin(), _objects.end(), [](VisibleObject* obj)  {

		
		delete obj; obj = NULL;  });

	delete _texture;
	_texture = NULL;
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

void ResourceManager::add(VisibleObject* obj)
{
	obj->load(_texture);
	_objects.push_back(obj);
}

void ResourceManager::load(std::string texturePath, SDL_Renderer * renderer)
{
	_isLoaded = true;
	_texture = new Texture(renderer);
	if (!_texture->load(texturePath))
	{
		std::cout << "Failed to load texture!\n";
		_isLoaded = false;
	}
	
}

void ResourceManager::processInput(const Uint8* currentKeyStates)
{
	/*for (unsigned int i = 0; i < _objects.size(); ++i)
		_objects[i]->processInput(currentKeyStates);*/
	std::for_each(_objects.begin(), _objects.end(), [currentKeyStates](VisibleObject* obj) {
		obj->processInput(currentKeyStates);
		});
}


void ResourceManager::update(float dt)
{
	//Update objects
	//for (unsigned int i = 0; i < _objects.size(); ++i)
	//	_objects[i]->update(dt);
	std::for_each(_objects.begin(), _objects.end(), [dt](VisibleObject* obj) {obj->update(dt); });
	//Remove dead objects
	/*for (unsigned int i = 0; i < _objects.size(); ++i)
		if (_objects[i]->isDead())
		{
			delete _objects[i];
			_objects[i] = NULL;
		}
	*/
	
	_objects.erase(std::remove_if(_objects.begin(),
		_objects.end(),
		[](VisibleObject* obj) {
			if (obj->isDead())
			{
				delete obj;
				obj = NULL;
			}
			return obj == NULL; }), _objects.end());
}

void ResourceManager::render()
{
	//for (unsigned int i = 0; i < _objects.size(); ++i)
	//	_objects[i]->render();
	std::for_each(_objects.begin(), _objects.end(), [](VisibleObject* obj) {obj->render(); });
}