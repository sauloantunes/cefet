#ifndef __BOIDS_H_
#define __BOIDS_H_

#include "config.h"

class Boids{
public:
	Boids();
	Boids(float);
	~Boids(){}

	vector<float> m_headColor;
	vector<float> m_bodyColor;
	vector<float> m_wingsColor;
	vector<float> m_tailColor;

	float m_wingPosition;
	float m_wingVelocity;

	Vec4 m_size;
	Vec4 m_position;
	Vec4 m_velocity;

	void moveWing();
	void draw();
	void setSize(float);
	void setSize(float, float, float);
	void setPosition(float, float, float);
	void setDirection(float, float, float);
};

#endif