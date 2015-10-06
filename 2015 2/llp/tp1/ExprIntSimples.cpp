#include "ExprIntSimples.h"

ExprIntSimples::ExprIntSimples(Termo *t){
	termo  = t;
}

int ExprIntSimples::avaliar(){
	return termo->getValor();
}