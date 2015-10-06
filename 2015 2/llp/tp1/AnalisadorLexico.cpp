#include "AnalisadorLexico.h"

AnalisadorLexico::AnalisadorLexico(string nome_arquivo) {
	arquivo = fopen(nome_arquivo.c_str(), "r+");
	if(!arquivo){
		cout << "Arquivo nao encontrado." << endl;
		exit(1);
	}

	linha = 1;
	iniciarTabelaSimbolos();
}

AnalisadorLexico::~AnalisadorLexico() {
	if (arquivo)
		fclose(arquivo);
}

int AnalisadorLexico::getLinha(){
	return linha;
}

int AnalisadorLexico::consultarTabelaSimbolos(string token){
	if(tabelaSimbolos.count(token))
		return tabelaSimbolos[token];
	else
		return TOKEN_INVALIDO;
}

void AnalisadorLexico::iniciarTabelaSimbolos(){
	
	tabelaSimbolos["tempo"] 	= TEMPO;
	tabelaSimbolos["musica"] 	= MUSICA;
	tabelaSimbolos["faca"] 		= FACA;
	tabelaSimbolos["repetir"] 	= REPETIR;
	tabelaSimbolos["tocar"] 	= TOCAR;
	tabelaSimbolos["se"] 		= SE;
	tabelaSimbolos["senao"] 	= SENAO;
	tabelaSimbolos["fim"] 		= FIM;
	tabelaSimbolos["pausar"] 	= PAUSAR;

	tabelaSimbolos["("]	= ABRE_PARENTESES;
	tabelaSimbolos[")"]	= FECHA_PARENTESES;
	tabelaSimbolos[","] = VIRGULA;
	tabelaSimbolos["."] = PONTO;
	tabelaSimbolos[";"] = PONTO_VIRGULA;
	tabelaSimbolos[":"] = DOIS_PONTOS;
	tabelaSimbolos["%"] = PORCENTO;

	tabelaSimbolos["="]  = IGUAL;
	tabelaSimbolos["=="] = IGUAL_IGUAL;
	tabelaSimbolos["!="] = DIFERENTE;
	tabelaSimbolos["<"]  = MENOR;
	tabelaSimbolos[">"]  = MAIOR;
	tabelaSimbolos["=<"] = MENOR_IGUAL;
	tabelaSimbolos["=>"] = MAIOR_IGUAL;

	tabelaSimbolos["+"] = SOMA;
	tabelaSimbolos["-"] = SUBTRACAO;
	tabelaSimbolos["*"] = MULTIPLICACAO;
	tabelaSimbolos["/"] = DIVISAO;

	tabelaSimbolos["a"] = VAR;
	tabelaSimbolos["b"] = VAR;
	tabelaSimbolos["c"] = VAR;
	tabelaSimbolos["d"] = VAR;
	tabelaSimbolos["e"] = VAR;
	tabelaSimbolos["f"] = VAR;
	tabelaSimbolos["g"] = VAR;
	tabelaSimbolos["h"] = VAR;
	tabelaSimbolos["i"] = VAR;
	tabelaSimbolos["j"] = VAR;
	tabelaSimbolos["k"] = VAR;
	tabelaSimbolos["l"] = VAR;
	tabelaSimbolos["m"] = VAR;
	tabelaSimbolos["n"] = VAR;
	tabelaSimbolos["o"] = VAR;
	tabelaSimbolos["p"] = VAR;
	tabelaSimbolos["q"] = VAR;
	tabelaSimbolos["r"] = VAR;
	tabelaSimbolos["s"] = VAR;
	tabelaSimbolos["t"] = VAR;
	tabelaSimbolos["u"] = VAR;
	tabelaSimbolos["v"] = VAR;
	tabelaSimbolos["x"] = VAR;
	tabelaSimbolos["y"] = VAR;
	tabelaSimbolos["z"] = VAR;
	tabelaSimbolos["w"] = VAR;

	tabelaSimbolos["A"]  = NOTA;
	tabelaSimbolos["A#"] = NOTA;
	tabelaSimbolos["B"]  = NOTA;
	tabelaSimbolos["C"]  = NOTA;
	tabelaSimbolos["C#"] = NOTA;
	tabelaSimbolos["D"]  = NOTA;
	tabelaSimbolos["D#"] = NOTA;
	tabelaSimbolos["E"]  = NOTA;
	tabelaSimbolos["F"]  = NOTA;
	tabelaSimbolos["F#"] = NOTA;
	tabelaSimbolos["G"]  = NOTA;
	tabelaSimbolos["G#"] = NOTA;
}

Lexema AnalisadorLexico::nextToken(){
	Lexema lex = {1, ""};
	int estado = 1;

	while(estado < 10) {
		int c = fgetc(arquivo);

		if(c == EOF && estado != 1 && lex.token != "fim"){
			lex.type = FIM_INESPERADO;
			estado = 11;
			continue;
		}

		switch(estado){
			case 1:
				if(c == -1){
					lex.type = FIM_ARQUIVO;
					estado = 11;
				}

				else if(c == '\n'){
					linha++;
					estado = 1;
				}

				else if(c == '\t' || c == ' ') {
					// Caracter em branco.
					estado = 1;
				}

				else if(c == '='){
					lex.token += c;
					estado = 2;
				}

				else if(c == '>'){
					lex.token += c;
					estado = 3;
				}

				else if(c == '!'){
					lex.token += c;
					estado = 4;
				}

				else if(c >= '0' && c <= '9'){
					lex.token += c;
					estado = 5;
				}

				else if(c == '"'){
					//Inicio de String, nao coloca no token.			
					estado = 6;
				}

				else if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
					lex.token += c;
					estado = 7;
				}

				else if(c == '/'){
					lex.token += c;
					estado = 8;
				}

				else if(c == '+' || c == '-' || c == ';' || c == '*' || c == ',' ||
				   		c == '%' || c == '(' || c == ')' || c == ':' || c == '.' || c == '<'){	
					lex.token += c;
					estado = 10;
				}

				else {
					lex.type = TOKEN_INVALIDO;
					estado = 11;
				}

				break;

			case 2:
				if(c == '<'){
					lex.token += c;
					estado = 10;
				}

				else if(c == '='){
					lex.token += c;
					estado = 10;
				}

				else {
					if (c != -1)
						ungetc(c, arquivo);

					estado = 10;
				}

				break;

			case 3:
				if(c == '='){
					lex.token += c;
					estado = 10;
				} 

				else {
					if (c != -1)
						ungetc(c, arquivo);

					estado = 10;
				}

				break;

			case 4:
				if(c == '='){
					lex.token += c;
					estado = 10;
				}

				else {			
					lex.type = TOKEN_INVALIDO;
					estado = 11;
				}

				break;

			case 5:
				if(c >= '0' && c <= '9'){
					lex.token += c;
					estado = 5;
				}

				else {
					if (c != -1)
						ungetc(c, arquivo);

					lex.type = NUMERO;
					estado = 11;
				}

				break;

			case 6:
				if(c != '"'){
					lex.token += c;
					estado = 6;
				}

				else {
					lex.type = STRING;
					estado = 11;
				}

				break;

			case 7:
				if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '#'){
					lex.token += c;
					estado = 7;
				}

				else {
					if (c != -1)
						ungetc(c, arquivo);

					estado = 10;
				}

				break;

			case 8:
				if(c == '/'){
					lex.token += c;
					estado = 9;
				}

				else {
					if (c != -1)
						ungetc(c, arquivo);

					estado = 10;
				}

				break;

			case 9:
				if(c != '\n'){
					lex.token += c;
					estado = 9;
				}

				else {
					if (c != -1)
						ungetc(c, arquivo);			// retorna comentário ou não? não

					lex.token.clear();
					estado = 1;
				}

				break;
		}
	}

	if (estado == 10)
		lex.type = consultarTabelaSimbolos(lex.token);

	return lex;
}