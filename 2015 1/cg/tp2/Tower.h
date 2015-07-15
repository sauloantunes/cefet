#ifndef __TOWER_H_
#define __TOWER_H_

#include "config.h"

class Tower{
public:
	Tower();
	~Tower(){}

	float m_radius;
	float m_height;
	vector<float> m_color;
	Vec4 m_position;

	void setColor(float, float, float);
	void setPosition(float, float);
	void draw();
};

#endif