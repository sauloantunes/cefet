#ifndef EXPRESSAO_H
#define EXPRESSAO_H

#include "config.h"

using namespace std;

template<typename T>
class Expressao {
public:
	virtual T avaliar() = 0;
};

#endif