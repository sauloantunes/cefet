#ifndef VARIAVEL_H
#define VARIAVEL_H

#include <bits/stdc++.h>
#include "Termo.h"

using namespace std;

class Variavel : public Termo{
	string nome;
	int valor;
public:
	Variavel();
	Variavel(string, int);
	int getValor();
	void setValor(int);
	string getNome();
	void setNome(string);
};

#endif