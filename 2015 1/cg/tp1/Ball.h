#ifndef __BALL_H__
#define __BALL_H__

#include "Object.h"
#include "config.h"

struct velocity{
	float x;
	float y;
};

class Ball : public Object{
public:
	float m_radius;
	float m_segments;
	float m_speedup;
	struct velocity m_velocity;

	Ball();
	void update();
	void draw();
	void checkColision();

};
#endif