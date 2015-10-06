#include "BlocoComandos.h"

BlocoComandos::BlocoComandos(){
}

void BlocoComandos::adicionarComando(Comando* c){
	comandos.push_back(c);
}

void BlocoComandos::executar() {
	list<Comando*>::iterator it;
	for (it = comandos.begin(); it != comandos.end(); ++it){
		Comando* cmd = *it;
		cmd->executar();
	}
}