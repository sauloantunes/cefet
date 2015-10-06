#ifndef EXPRINTDUPLA_H
#define EXPRINTDUPLA_H

#include "ExprInteira.h"
#include "Termo.h"

using namespace std;

class ExprIntDupla : public ExprInteira {
	Termo *termo1;
	ArithOp op;
	Termo *termo2;
public:
	ExprIntDupla(Termo*, ArithOp, Termo*);
	int avaliar();
};

#endif