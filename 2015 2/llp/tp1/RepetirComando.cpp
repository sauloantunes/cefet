#include "RepetirComando.h"

RepetirComando::RepetirComando(ExprLogica* e, BlocoComandos* c){
	expr = e;
	comandos = c;
}

void RepetirComando::executar(){
	while(expr->avaliar())
		comandos->executar();
}