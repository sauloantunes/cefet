#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <GL/glut.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct position{
	float x;
	float y;

	position(){
		x = 0;
		y = 0;
	}

	position(float _x, float _y){
		x = _x;
		y = _y;
	}

	void add(float _x, float _y){
		x += _x;
		y += _y;
	}

	void add(struct position p){
		x += p.x;
		y += p.y;
	}

	void set(float _x, float _y){
		x = _x;
		y = _y;
	}
};

struct size{
	float x;
	float y;
};

struct color{
	float r;
	float g;
	float b;
	float a;

	color(){}

	color(float r_, float g_, float b_, float a_){
		r = r_;
		g = g_;
		b = b_;
		a = a_;
	}

	void set(float r_, float g_, float b_, float a_){
		r = r_;
		g = g_;
		b = b_;
		a = a_;
	}
};

#endif