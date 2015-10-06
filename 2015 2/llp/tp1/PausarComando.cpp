#include "PausarComando.h"
#include <unistd.h>
#include <iostream>
#define Sleep(t) usleep(t*1000);

PausarComando::PausarComando(ConstInt* t){
	tempo = t;
}

void PausarComando::executar(){
	Sleep(tempo->getValor());
}