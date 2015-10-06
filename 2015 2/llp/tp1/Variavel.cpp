#include "Variavel.h"

Variavel::Variavel(){
}

Variavel::Variavel(string s, int v){
	nome = s;
	valor = v;
}

int Variavel::getValor(){
	return valor;
}

void Variavel::setValor(int v){
	valor = v;
}

string Variavel::getNome(){
	return nome;
}

void Variavel::setNome(string s){
	nome = s;
}
