#ifndef REPETIRCOMANDO_H
#define REPETIRCOMANDO_H

#include <bits/stdc++.h>
#include "Comando.h"
#include "ExprLogica.h"
#include "BlocoComandos.h"

using namespace std;

class RepetirComando : public Comando{
	ExprLogica *expr;
	BlocoComandos *comandos;
public:
	RepetirComando(ExprLogica*, BlocoComandos*);
	void executar();
};

#endif