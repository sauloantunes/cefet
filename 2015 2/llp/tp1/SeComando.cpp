#include "SeComando.h"

SeComando::SeComando(ExprLogica* e, BlocoComandos* se, BlocoComandos* senao){
	expr = e;
	ComandosSe = se;
	ComandosSenao = senao;
}

void SeComando::executar(){
	if(expr->avaliar())
		ComandosSe->executar();
	else
		ComandosSenao->executar();
}