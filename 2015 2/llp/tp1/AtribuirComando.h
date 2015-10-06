#ifndef ATRIBUIRCOMANDO_H
#define ATRIBUIRCOMANDO_H

#include <bits/stdc++.h>
#include "Comando.h"
#include "Variavel.h"
#include "ExprInteira.h"

using namespace std;

class AtribuirComando : public Comando{
	Variavel* var;
	ExprInteira* expr;
public:
	AtribuirComando(Variavel*, ExprInteira*);
	void executar();
};

#endif