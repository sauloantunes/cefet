#ifndef EXPRINTEIRA_H
#define EXPRINTEIRA_H

#include "Expressao.h"

using namespace std;

class ExprInteira : public Expressao<int> {
public:
	virtual int avaliar() = 0;
};

#endif