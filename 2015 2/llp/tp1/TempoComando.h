#ifndef TEMPOCOMANDO_H
#define TEMPOCOMANDO_H

#include "Comando.h"
#include "Nota.h"

using namespace std;

class TempoComando : public Comando {
	Nota nota;
	double duracao;
	string palavra;
public:
	TocarComando(Nota, double, string);
	void executar();
};

#endif