#ifndef PLAYTONE_H
#define PLAYTONE_H

#include <stdio.h>
#include <stdlib.h>

class Playtone{
	float frequencia;
	float duracao;
public:
	Playtone(float, float);
	int beep();
};

#endif
