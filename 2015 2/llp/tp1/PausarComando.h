#ifndef PAUSARCOMANDO_H
#define PAUSARCOMANDO_H

#include "ConstInt.h"
#include "Comando.h"

using namespace std;

class PausarComando : public Comando{
	ConstInt* tempo;
public:
	PausarComando(ConstInt*);
	void executar();
};

#endif