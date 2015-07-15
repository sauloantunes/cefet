#ifndef __BAR_H__
#define __BAR_H__

#include "Object.h"
#include "config.h"

class Bar : public Object{
public:
	struct size m_size;
	float m_velocity;

	Bar();
	void update();
	void draw();
	struct position getPoint(int);

};
#endif