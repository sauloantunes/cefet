#ifndef EXPRLOGICADUPLA_H
#define EXPRLOGICADUPLA_H

#include "ExprLogica.h"
#include "Termo.h"
#include "config.h"

using namespace std;

class ExprLogicaDupla : public ExprLogica {
	Termo *termo1;
	RelOp op;
	Termo *termo2;
public:
	ExprLogicaDupla(Termo*, RelOp, Termo*);
	bool avaliar();
};

#endif