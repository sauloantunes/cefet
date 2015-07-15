#ifndef __VEC4_H_
#define __VEC4_H_

class Vec4{
public:
	float x,y,z,h;
	Vec4();
	Vec4(float);
	Vec4(float, float, float, float);
	~Vec4();

	float module();
	float angle(char axis);

	Vec4 operator+(const Vec4&);
	Vec4 operator-(const Vec4&);
	Vec4 operator*(const float&);
	Vec4 operator/(const float&);
};

#endif