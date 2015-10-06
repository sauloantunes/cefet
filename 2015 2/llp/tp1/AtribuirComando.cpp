#include "AtribuirComando.h"

AtribuirComando::AtribuirComando(Variavel* v, ExprInteira* e){
	  var = v;
	  expr = e;
}

void AtribuirComando::executar(){
	int valor = expr->avaliar();
	var->setValor(valor);
}