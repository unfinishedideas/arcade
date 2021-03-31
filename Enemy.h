#pragma once
#include "Sprite.h"
#include "VisibleObject.h"
#include "core.h"
#include <iostream>


//TO DO: Implement this class.


class Enemy : public VisibleObject
{
public:
	Enemy();
	~Enemy();
	
	void setCenter(floatVec center);
	void setOffset(floatVec offset);
	void printCenter();
	floatVec getCenter();
	floatVec getOffset();
private:
	floatVec _center;
	floatVec _offset;
	bool _isLoaded;
};
