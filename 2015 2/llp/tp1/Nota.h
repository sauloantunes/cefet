#ifndef NOTA_H
#define NOTA_H

#include <bits/stdc++.h>

using namespace std;

class Nota {
	string nome;
	double frequencia;

public:
	Nota();
	Nota(string, double);

	string getNome();
	double getFrequencia();
};

#endif