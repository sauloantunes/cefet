#include "TocarComando.h"
#include "Playtone.h"

#include <unistd.h>
#define Sleep(t) usleep(t*1000);

TocarComando::TocarComando(Nota n, double d, string s){
	nota = n;
	duracao = d;
	palavra = s;
}

void TocarComando::executar() {
	cout << "(" << nota.getNome() << ", " << duracao << ")";
	if(!palavra.empty())
		cout << " -> " << palavra;
	cout << endl;

	// Beep!
	Playtone p(nota.getFrequencia(), duracao);
	p.beep();
}