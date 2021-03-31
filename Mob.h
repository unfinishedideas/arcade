#pragma once
#include "Enemy.h"
#include <vector>

//TO DO: implement


class Mob : public VisibleObject
{
public:
	Mob();
	~Mob();
	void processInput(const Uint8* currentKeyStates);
	void update(float dt);
	void load(Texture* text); 
	void render();
	void setCenter(floatVec center);
	floatVec getCenter();
private:
	std::vector<Enemy*> _enemies;
	std::vector<floatVec> _offsets; //Do we need to keep track of offsets in Mob?
	floatVec _center;
	float _radius;

	
};
