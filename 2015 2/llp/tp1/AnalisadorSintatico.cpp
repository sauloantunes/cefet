#include "AnalisadorSintatico.h"

AnalisadorSintatico::AnalisadorSintatico(string nome_arquivo) 
	: lexico(nome_arquivo) {
	
	atual = lexico.nextToken();
	tempo = 500;

	notas["C"]	= Nota("C",  261.6);
	notas["C#"]	= Nota("C#", 277.2);
	notas["D"]	= Nota("D",  293.7);
	notas["D#"]	= Nota("D#", 311.1);
	notas["E"]	= Nota("E",  329.6);
	notas["F"]	= Nota("F",  349.2);
	notas["F#"]	= Nota("F#", 370.0);
	notas["G"]	= Nota("G",  392.0);
	notas["G#"]	= Nota("G#", 415.3);
	notas["A"]	= Nota("A",  440.0);
	notas["A#"]	= Nota("A#", 466.2);
	notas["B"]	= Nota("B",  493.9);
}

void AnalisadorSintatico::matchToken(int type){
	if(atual.type == type)
		atual = lexico.nextToken();
	else{
		cout << setfill('0') << setw(2) << lexico.getLinha() << ": ";
		if(atual.type == FIM_INESPERADO)
			cout << "Fim de arquivo inesperado" << endl;
		else if(atual.type == TOKEN_INVALIDO)
			cout << "Lexema invalido [" << atual.token << "]" << endl;
		else 
			cout << "Lexema nao esperado [" << atual.token << "]" << endl;
		exit(1);
	}
}

BlocoComandos* AnalisadorSintatico::init() {
	return procProgram();
}

BlocoComandos* AnalisadorSintatico::procProgram(){
	if(atual.type == TEMPO)
		procTempo();

	matchToken(MUSICA);
	procString();
	matchToken(PONTO_VIRGULA);
	matchToken(FACA);
	BlocoComandos* cmds = procComandos();
	matchToken(FIM);
	matchToken(FIM_ARQUIVO);

	return cmds;
}

void AnalisadorSintatico::procTempo(){
	matchToken(TEMPO);
	ConstInt* c = procNum();
	tempo = c->getValor();
	matchToken(PONTO_VIRGULA);
}

BlocoComandos* AnalisadorSintatico::procComandos(){
	BlocoComandos* bloco = new BlocoComandos();

	while (atual.type == TOCAR || 
		   atual.type == PAUSAR ||
		   atual.type == VAR ||
		   atual.type == SE ||
		   atual.type == REPETIR ){
		Comando* cmd = procComando();
		bloco->adicionarComando(cmd);
	}

	return bloco;
}

Comando* AnalisadorSintatico::procComando(){
	Comando* cmd;

	switch(atual.type){
		case TOCAR:
			cmd = procTocar();
			break;	
		case PAUSAR: 
			cmd = procPausar();
			break;
		case VAR:
			cmd = procAtribuir();
			break;
		case SE:
			cmd = procSe();
			break;
		case REPETIR:
			cmd = procRepetir();
			break;
	}

	return cmd;
}

TocarComando* AnalisadorSintatico::procTocar() {
	matchToken(TOCAR);
	matchToken(ABRE_PARENTESES);
	Nota nota = procNota();
	matchToken(VIRGULA);
	double duracao = procDuracao();
	matchToken(FECHA_PARENTESES);

	string str = "";
	if(atual.type == DOIS_PONTOS){
		matchToken(DOIS_PONTOS);
		str = procString();
	}

	matchToken(PONTO_VIRGULA);

	return new TocarComando(nota, duracao, str);
}

PausarComando* AnalisadorSintatico::procPausar(){
	matchToken(PAUSAR);
	matchToken(ABRE_PARENTESES);
	ConstInt *c = procNum();
	c->setValor(c->getValor() * tempo);
	matchToken(FECHA_PARENTESES);
	matchToken(PONTO_VIRGULA);

	return new PausarComando(c);
}

AtribuirComando* AnalisadorSintatico::procAtribuir(){
	Variavel* var = procVar();
	matchToken(IGUAL);
	ExprInteira* ei  = procExprInt();
	matchToken(PONTO_VIRGULA);
	return new AtribuirComando(var, ei);
}


SeComando* AnalisadorSintatico::procSe(){
	matchToken(SE);
	matchToken(ABRE_PARENTESES);
	ExprLogica* expr = procExprBool();
	matchToken(FECHA_PARENTESES);
	matchToken(PONTO_VIRGULA);
	matchToken(FACA);
	BlocoComandos* se = procComandos();
	BlocoComandos* senao = NULL;
	if(atual.type == SENAO){
		matchToken(SENAO);
		senao = procComandos();
	}
	matchToken(FIM);

	return new SeComando(expr, se, senao);
}

RepetirComando* AnalisadorSintatico::procRepetir(){
	matchToken(REPETIR);
	matchToken(ABRE_PARENTESES);
	ExprLogica* expr = procExprBool();
	matchToken(FECHA_PARENTESES);
	matchToken(PONTO_VIRGULA);
	matchToken(FACA);
	BlocoComandos* blc = procComandos();
	matchToken(FIM);

	return new RepetirComando(expr, blc);
}

ExprLogica* AnalisadorSintatico::procExprBool(){
	Termo* t1 = procTermo();
	RelOp  op = procOpRel();
	Termo* t2 = procTermo();

	return new ExprLogicaDupla(t1, op, t2);
}

ExprInteira* AnalisadorSintatico::procExprInt(){
	Termo *t1 = procTermo();
	
	if(atual.type == SOMA ||
	   atual.type == SUBTRACAO ||
	   atual.type == MULTIPLICACAO ||
	   atual.type == DIVISAO){
	   	ArithOp op = procOpArit();
	   	Termo *t2 = procTermo();

	   	return new ExprIntDupla(t1, op, t2);
	}

	return new ExprIntSimples(t1);
}

Termo* AnalisadorSintatico::procTermo(){
	if(atual.type == VAR)
		return procVar();
	else
		return procNum();
}


RelOp AnalisadorSintatico::procOpRel(){
	switch(atual.type){
		case IGUAL_IGUAL: 
			matchToken(IGUAL_IGUAL); 
			return IGUAL_IGUAL;
		
		case DIFERENTE: 
			matchToken(DIFERENTE); 
			return DIFERENTE;
		
		case MENOR: 
			matchToken(MENOR); 
			return MENOR;
		
		case MENOR_IGUAL: 
			matchToken(MENOR_IGUAL); 
			return MENOR_IGUAL;
					
		case MAIOR: 
			matchToken(MAIOR); 
			return MAIOR;

		case MAIOR_IGUAL: 
			matchToken(MAIOR_IGUAL); 
			return MAIOR_IGUAL;
	}
}

ArithOp AnalisadorSintatico::procOpArit(){
	switch(atual.type){
		case SOMA: 
			matchToken(SOMA); 
			return SOMA;
		
		case SUBTRACAO: 
			matchToken(SUBTRACAO); 
			return SUBTRACAO;
		
		case DIVISAO: 
			matchToken(DIVISAO); 
			return DIVISAO;
		
		case MULTIPLICACAO: 
			matchToken(MULTIPLICACAO); 
			return MULTIPLICACAO;
	}
}

Nota AnalisadorSintatico::procNota() {
	string token = atual.token;
	matchToken(NOTA);
	return notas[token];
}

double AnalisadorSintatico::procDuracao() {
	double res;
	if(atual.type == PORCENTO){
		matchToken(PORCENTO);
		ConstInt* num = procNum();
		res = tempo / num->getValor();
	} else{
		ConstInt* num = procNum();
		res = tempo * num->getValor();
		if(atual.type == PONTO){
			matchToken(PONTO);
			res *= 1.5;
		}
	}

	return res;
}

Variavel* AnalisadorSintatico::procVar() {
	string nome = atual.token;
	matchToken(VAR);
	if(!variaveis.count(nome))
		variaveis[nome] = new Variavel(nome, 0);
	return variaveis[nome];
}

ConstInt* AnalisadorSintatico::procNum() {
	string token = atual.token;
	matchToken(NUMERO);
	int n = atoi(token.c_str());
	return new ConstInt(n);
}

string AnalisadorSintatico::procString() {
	string token = atual.token;
	matchToken(STRING);
	return token;
}