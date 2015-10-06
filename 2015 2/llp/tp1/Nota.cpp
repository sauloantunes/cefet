#include "Nota.h"

Nota::Nota(){
}

Nota::Nota(string s, double f){
	nome = s;
	frequencia = f;
}

string Nota::getNome(){
	return nome;
}

double Nota::getFrequencia(){
	return frequencia;
}