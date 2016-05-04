#include <bits/stdc++.h>

using namespace std;

#define QUANTUM 3

enum estados {NOVO, PRONTO, EXECUTANDO, FINALIZADO};

typedef struct {
	int id;
	int inicio;
	int duracao;
	int prioridade;
	int status;
	int executado;
} processo;

vector<processo> processos;
int tempo = 0;
int tempoEspera = 0;
int trocasContexto = -1;
int ultimoProcesso = -1;

// Funções de Ordenação
bool ordenaPorId(processo a, processo b){
	return a.id < b.id;
}

bool ordenaPorInicio(processo a, processo b){
	return a.inicio < b.inicio;
}

bool ordenaPorTempoRestante(processo a, processo b){
	return (a.duracao - a.executado) < (b.duracao - b.executado);
}

bool ordenaPorDuracao(processo a, processo b){
	if(a.status == EXECUTANDO)
		return true;
	if(b.status == EXECUTANDO)
		return false;

	return a.duracao < b.duracao;
}

bool ordenaPorPrioridadeComPreempcao(processo a, processo b){
	return a.prioridade < b.prioridade;
}

bool ordenaPorPrioridade(processo a, processo b){
	if(a.status == EXECUTANDO)
		return true;
	if(b.status == EXECUTANDO)
		return false;
	
	return a.prioridade < b.prioridade;
}

bool ordenaPorRoundRobin(processo a, processo b){
	return (a.executado / QUANTUM) < (b.executado / QUANTUM);
}

// Funções de Impressão

void imprimeCabecalho(){
	cout << " tempo";
	for (int i = 0; i < processos.size(); ++i)
		cout << setw(3) << "P" << i;
	
	cout << endl;
}

void imprimeProcesso(processo p){
	if(p.status == PRONTO)
		cout << "  --";

	else if(p.status == EXECUTANDO)
		cout << "  ##";
	
	else
		cout << "    ";
}

void imprimeTempo(){
	cout << setw(2) << tempo << " -" << setw(2) << tempo + 1;
}

void imprimeProcessos(){
	sort(processos.begin(), processos.end(), ordenaPorId);

	imprimeTempo();
	
	for (int i = 0; i < processos.size(); ++i)
		imprimeProcesso(processos[i]);

	cout << endl;
}

// Funções de Atualização

void atualizaProcessos(){
	// Atualiza o status dos processos a cada iteração.
	for (int i = 0; i < processos.size(); ++i){
		if(processos[i].inicio > tempo)
			processos[i].status = NOVO;
		
		else if(processos[i].duracao - processos[i].executado){
			processos[i].status = PRONTO;
			tempoEspera++;
		}
		
		else
			processos[i].status = FINALIZADO;
	}
}

bool existemProcessosASeremExecutados(){
	// Verifica se ainda existem processos a serem executados.
	for (int i = 0; i < processos.size(); ++i)
		if(processos[i].status != FINALIZADO)
			return true;

	return false;
}

bool getNext(){
	atualizaProcessos();

	for (int i = 0; i < processos.size(); ++i) {
		if(processos[i].status == PRONTO){
			processos[i].executado++;
			processos[i].status = EXECUTANDO;

			// Troca de contexto
			if(ultimoProcesso != processos[i].id){
				ultimoProcesso = processos[i].id;
				trocasContexto++;
			}

			tempoEspera--;

			return true;
		}
	}

	return existemProcessosASeremExecutados();
}

// Algoritmos de Escalonamento

// First Come, First Served
bool FCFS(){
	sort(processos.begin(), processos.end(), ordenaPorInicio);
	return getNext();
}

// Shortest Job First
bool SJF(){
	sort(processos.begin(), processos.end(), ordenaPorDuracao);
	return getNext();
}

// Shortest Remaining Time First
bool SRTF(){
	sort(processos.begin(), processos.end(), ordenaPorTempoRestante);
	return getNext();
}

// Por prioridade, com preempção
bool PP(){
	sort(processos.begin(), processos.end(), ordenaPorPrioridadeComPreempcao);
	return getNext();
}

// Por prioridade, sem preempção
bool P(){
	sort(processos.begin(), processos.end(), ordenaPorPrioridade);
	return getNext();
}

// Round-Robin
bool RR(){
	sort(processos.begin(), processos.end(), ordenaPorRoundRobin);
	return getNext();
}

void envelhece(){
	if (tempo % QUANTUM == 0){
		for (int i = 0; i < processos.size(); ++i) {
			if(processos[i].status == PRONTO)
				processos[i].prioridade -= 1;
		}
	}
}

// Round-robin com prioridade e envelhecimento
bool RRPE(){
	envelhece();
	sort(processos.begin(), processos.end(), ordenaPorPrioridade);
	sort(processos.begin(), processos.end(), ordenaPorRoundRobin);
	return getNext();
}

int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		processo p;
		p.id = i;
		p.executado = 0;
		cin >> p.inicio >> p.duracao >> p.prioridade;
		processos.push_back(p);
	}

	imprimeCabecalho();

	// [FCFS, SJF, SRTF, P, PP, RR, RRPE]
	while(P()){
		imprimeProcessos();
		tempo++;
	}

	cout << endl;
	cout << "Trocas de contexto: " << trocasContexto << endl;
	cout << "Tempo de espera medio:: " << (float)tempoEspera / processos.size() << endl;
	cout << endl;
}