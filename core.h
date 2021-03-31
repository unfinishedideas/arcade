#pragma once

//floatVec creates functionality for 2-dimensional vectors of floats.
struct floatVec {
	floatVec();
	floatVec(float _x, float _y);
	floatVec& operator=(const floatVec& obj);
	floatVec operator+(const floatVec& obj); //vector addition
	
	float operator*(const floatVec& obj); //dot product
	float x;
	float y;
};

floatVec operator*(const float c, const floatVec& obj); //left scalar mult
floatVec operator*(const floatVec& obj, const float c); //right scalar mult