#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "config.h"

class Object{
public:
	struct position m_pos;
	struct color m_color;

	Object();

	virtual void draw() = 0;
};

#endif