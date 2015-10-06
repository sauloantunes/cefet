#ifndef TOCARCOMANDO_H
#define TOCARCOMANDO_H

#include <bits/stdc++.h>
#include "Comando.h"
#include "Nota.h"

using namespace std;

class TocarComando : public Comando {
	Nota nota;
	double duracao;
	string palavra;

public:
	TocarComando(Nota, double, string);
	void executar();
};

#endif