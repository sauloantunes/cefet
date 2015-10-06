#include "ConstInt.h"

ConstInt::ConstInt(int v){
	valor = v;
}

int ConstInt::getValor(){
	return valor;
}

void ConstInt::setValor(int v){
	valor = v;
}
