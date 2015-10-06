#ifndef EXPRINTSIMPLES_H
#define EXPRINTSIMPLES_H

#include "ExprInteira.h"
#include "Termo.h"

using namespace std;

class ExprIntSimples : public ExprInteira {
	Termo *termo;
public:
	ExprIntSimples(Termo*);
	int avaliar();
};

#endif