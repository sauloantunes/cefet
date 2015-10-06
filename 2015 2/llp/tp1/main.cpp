#include <bits/stdc++.h>
#include "AnalisadorSintatico.h"

using namespace std;

int main(int argc, char const *argv[]){
	AnalisadorSintatico as(argv[1]);
	BlocoComandos* cmd = as.init();
	cmd->executar();
}