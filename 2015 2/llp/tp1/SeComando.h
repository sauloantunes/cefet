#ifndef SECOMANDO_H
#define SECOMANDO_H

#include <bits/stdc++.h>
#include "Comando.h"
#include "ExprLogica.h"
#include "BlocoComandos.h"

using namespace std;

class SeComando : public Comando{
	ExprLogica* expr;
	BlocoComandos* ComandosSe;
	BlocoComandos* ComandosSenao;
public:
	SeComando(ExprLogica*, BlocoComandos*, BlocoComandos*);
	void executar();
};

#endif