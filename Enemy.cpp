#include "Enemy.h"



Enemy::Enemy()
{
	_isLoaded = false;
}

Enemy::~Enemy()
{

}

void Enemy::setCenter(floatVec center)
{
	_center = center;
}

void Enemy::printCenter()
{
	std::cout << _center.x << ' ' << _center.y << std::endl;
}

floatVec Enemy::getCenter()
{
	return _center;
}

void Enemy::setOffset(floatVec offset)
{
	_offset = offset;
}

floatVec Enemy::getOffset()
{
	return _offset;
}