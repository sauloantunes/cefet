#ifndef EXPRLOGICA_H
#define EXPRLOGICA_H

#include "Expressao.h"

using namespace std;

class ExprLogica : public Expressao<bool> {
public:
	virtual bool avaliar() = 0;
};

#endif