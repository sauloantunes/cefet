#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#define NUM_FIL 5
int numRefeicoes = 0;

//Mutexes
pthread_mutex_t palitos[NUM_FIL];
pthread_mutex_t mut_comida;


void meditar(){
	sleep (rand()%2);
}

void pegarPalito(long id, long palito){
	pthread_mutex_lock(&palitos[palito]);
	printf("Filosofo %ld, pegou palito %ld.\n", id, palito);
}

void soltarPalito(long id, long palito){
	pthread_mutex_unlock(&palitos[palito]);
	printf("Filosofo %ld, soltou palito %ld.\n", id, palito);
}

void comer(long id){
	pthread_mutex_lock(&mut_comida);
	printf("Filosofo %ld, esta comendo.\n", id);
	numRefeicoes++;
	pthread_mutex_unlock(&mut_comida);
}

void *filosofo(void *num){
	long id = (long) num;
	long palito_esq = id;
	long palito_dir = (id + 1) % NUM_FIL;


	while(1){
		meditar();

		if(id == 0){
			pegarPalito(id, palito_dir);
			pegarPalito(id, palito_esq);
		}
		else {
			pegarPalito(id, palito_esq);
			pegarPalito(id, palito_dir);
		}

		comer(id);
		soltarPalito(id, palito_esq);
		soltarPalito(id, palito_dir);
	}
}

int main (){
	int i;
	pthread_t threads[NUM_FIL];
	pthread_mutex_init (&mut_comida, NULL);

	for (i = 0; i < NUM_FIL; i++)
		pthread_mutex_init (&palitos[i], NULL);
	
	//Cria threads
	for (i = 0; i < NUM_FIL; i++)
		pthread_create (&threads[i], NULL, filosofo, (void *)i);

	while(1){
		sleep(1);
		pthread_mutex_lock (&mut_comida);
		printf ("Refeições por segundo: %d\n", numRefeicoes) ;
		numRefeicoes = 0 ;
		pthread_mutex_unlock (&mut_comida);
	}
}