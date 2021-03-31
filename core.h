#pragma once
struct floatVec {
	floatVec();
	floatVec(float _x, float _y);
	floatVec& operator=(floatVec& obj);
	floatVec operator+(const floatVec& obj1);
	float x;
	float y;
};
