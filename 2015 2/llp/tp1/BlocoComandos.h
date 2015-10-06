#ifndef BLOCOCOMANDOS_H
#define BLOCOCOMANDOS_H

#include <bits/stdc++.h>
#include "Comando.h"

using namespace std;

class BlocoComandos : public Comando {
	list<Comando*> comandos;

public:
	BlocoComandos();
	
	void adicionarComando(Comando*);
	void executar();
};

#endif