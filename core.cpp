#include "core.h"

floatVec::floatVec()
{
	x = 0.f;
	y = 0.f;
}

floatVec::floatVec(float _x, float _y)
{
	x = _x;
	y = _y;
}

floatVec& floatVec::operator=(const floatVec& obj)
{
	if (this == &obj)
		return *this;
	this->x = obj.x;
	this->y = obj.y;
	return *this;
}

floatVec floatVec::operator+(const floatVec& obj)
{
	floatVec vec;
	vec.x = this->x + obj.x;
	vec.y = this->y + obj.y;
	return vec;
}

floatVec operator*(const float c, const floatVec& obj)
{
	floatVec vec;
	vec.x = c * obj.x;
	vec.y = c * obj.y;
	return vec;
}


floatVec operator*(const floatVec & obj, const float c)
{
	floatVec vec;
	vec.x = c * obj.x;
	vec.y = c * obj.y;
	return vec;
}
float floatVec::operator*(const floatVec&obj)
{
	return this->x * obj.x + this->y * obj.y;
}