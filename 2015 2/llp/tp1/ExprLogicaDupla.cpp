#include "ExprLogicaDupla.h"

ExprLogicaDupla::ExprLogicaDupla(Termo *t1, RelOp rop, Termo *t2){
	termo1 = t1;
	op = rop;
	termo2 = t2;
}

bool ExprLogicaDupla::avaliar(){
	switch(op){
		case IGUAL_IGUAL: 
			return termo1->getValor() == termo2->getValor();
		case DIFERENTE: 
			return termo1->getValor() != termo2->getValor();
		case MENOR: 
			return termo1->getValor() < termo2->getValor();
		case MENOR_IGUAL: 
			return termo1->getValor() <= termo2->getValor();
		case MAIOR: 
			return termo1->getValor() > termo2->getValor();
		case MAIOR_IGUAL: 
			return termo1->getValor() >= termo2->getValor();
	}
}