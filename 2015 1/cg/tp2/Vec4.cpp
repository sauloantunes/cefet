#include "Vec4.h"
#include "config.h"

Vec4::Vec4(){
	x = y = z = 0;
	h = 1;
}

Vec4::Vec4(float v){
	x = y = z = v;
	h = 1;
}

Vec4::Vec4(float _x, float _y, float _z, float _h)
	: x(_x), y(_y), z(_z), h(_h){}


Vec4::~Vec4(){}

float Vec4::module(){
	return sqrt(x*x + y*y + z*z);
}

float Vec4::angle(char axis){
	if(module() == 0)
		return 0;

	if(axis == 'x' || axis == 'X')
		return acos(x / module()) * 180 / M_PI;

	if(axis == 'y' || axis == 'Y')
		return acos(y / module()) * 180 / M_PI;

	if(axis == 'z' || axis == 'Z')
		return acos(z / module()) * 180 / M_PI;
}

Vec4 Vec4::operator+(const Vec4 &b){
	Vec4 v;
	v.x = x + b.x;
	v.y = y + b.y;
	v.z = z + b.z;
	return v;
}

Vec4 Vec4::operator-(const Vec4 &b){
	Vec4 v;
	v.x = x - b.x;
	v.y = y - b.y;
	v.z = z - b.z;
	return v;
}

Vec4 Vec4::operator*(const float &n){
	Vec4 v;
	v.x = x * n;
	v.y = y * n;
	v.z = z * n;
	return v;
}

Vec4 Vec4::operator/(const float &n){
	Vec4 v;
	v.x = x / n;
	v.y = y / n;
	v.z = z / n;
	return v;
}