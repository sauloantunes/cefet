#include "ExprIntDupla.h"

ExprIntDupla::ExprIntDupla(Termo *t1, ArithOp aop, Termo *t2){
	termo1 = t1;
	op = aop;
	termo2 = t2;
}

int ExprIntDupla::avaliar(){
	switch(op){
		case SOMA: 
			return termo1->getValor() + termo2->getValor();
		case SUBTRACAO: 
			return termo1->getValor() - termo2->getValor();
		case MULTIPLICACAO: 
			return termo1->getValor() * termo2->getValor();
		case DIVISAO: 
			return termo1->getValor() / termo2->getValor();
	}
}