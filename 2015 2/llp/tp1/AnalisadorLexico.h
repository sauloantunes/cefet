#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <bits/stdc++.h>
#include "config.h"

using namespace std;

struct Lexema{
	int type;
	string token;
};

class AnalisadorLexico{
	int linha;
	FILE *arquivo;
	map <string, int> tabelaSimbolos;

	void iniciarTabelaSimbolos();
	int consultarTabelaSimbolos(string);

public:
	AnalisadorLexico(string);
	virtual ~AnalisadorLexico();

	int getLinha();
	Lexema nextToken();
};

#endif