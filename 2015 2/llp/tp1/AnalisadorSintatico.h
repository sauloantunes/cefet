#ifndef ANALISADORSINTATICO_H
#define ANALISADORSINTATICO_H

#include <bits/stdc++.h>
#include "config.h"
#include "AnalisadorLexico.h"
#include "Nota.h"
#include "Variavel.h"
#include "BlocoComandos.h"
#include "TocarComando.h"
#include "PausarComando.h"
#include "AtribuirComando.h"
#include "ExprInteira.h"
#include "ExprIntSimples.h"
#include "ExprIntDupla.h"
#include "Termo.h"
#include "SeComando.h"
#include "ExprLogica.h"
#include "ExprLogicaDupla.h"
#include "RepetirComando.h"

using namespace std;

class AnalisadorSintatico {
	AnalisadorLexico lexico;
	Lexema atual;
	map<string, Nota> notas;
	map<string, Variavel*> variaveis;

public:
	AnalisadorSintatico(string);
	BlocoComandos* init();

private:
	int tempo;
	void matchToken(int);

	BlocoComandos* procProgram();
	void procTempo();
	BlocoComandos* procComandos();
	Comando* procComando();
	TocarComando* procTocar();
	PausarComando* procPausar();
	AtribuirComando* procAtribuir();
	SeComando* procSe();
	RepetirComando* procRepetir();
	ExprLogica* procExprBool();
	ExprInteira* procExprInt();
	Termo* procTermo();
	RelOp procOpRel();
	ArithOp procOpArit();
	Nota procNota();
	double procDuracao();
	Variavel* procVar();
	ConstInt* procNum();
	string procString();
};

#endif