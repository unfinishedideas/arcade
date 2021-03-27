#include "VisibleObject.h"

VisibleObject::VisibleObject()
{
	_id = "";
}

VisibleObject::VisibleObject(std::string id)
{
	_id = id;
}
VisibleObject::~VisibleObject()
{

}

void VisibleObject::render()
{
	
}

void VisibleObject::load(Texture* text)
{

}

void VisibleObject::processInput(const Uint8* currentKeyStates)
{

}


void VisibleObject::update(float dt)
{

}

std::string VisibleObject::getID()
{
	return _id;
}

void VisibleObject::setID(std::string id)
{
	_id = id;
}