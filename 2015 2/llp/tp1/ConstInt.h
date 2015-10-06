#ifndef CONSTINT_H
#define CONSTINT_H

#include "Termo.h"

using namespace std;

class ConstInt : public Termo{
	int valor;
public:
	ConstInt(int);
	int getValor();
	void setValor(int);
};

#endif