#ifndef __BRICK_H__
#define __BRICK_H__

#include "Object.h"
#include "config.h"

class Brick : public Object{
public:
	struct size m_size;

	Brick();
	void draw();
	struct position getPoint(int);
};
#endif