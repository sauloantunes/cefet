#ifndef __SKYBOX_H_
#define __SKYBOX_H_

#include "config.h"

class Skybox{
public:
	vector<float> m_floorColor;
	vector<float> m_skyColor;
	vector<float> m_sideColor;
	
	Skybox();
	~Skybox();

	void draw();
};

#endif