#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define NUM_CONSUMERS 2
#define NUM_PRODUCERS 3
#define TAM_FILA 5

int fila[TAM_FILA];
int head = 0;
int tail = 0;

sem_t s_item, s_vaga;
pthread_mutex_t s_buffer;

void insertItem(int item){
	fila[head] = item;
	head = (head + 1) % TAM_FILA;
}

int removeItem(){
	int item =  fila[tail];
	tail = (tail + 1) % TAM_FILA;
	return item;
}

void *producer(void *id) {
	int item;

	while(1) {
		/* sleep for a random period of time */
		sleep(1 / ((rand() % 10) + 1) );
		sem_wait(&s_vaga);
		pthread_mutex_lock(&s_buffer);
		/* generate a random number */
		item = rand() % 100;
		insertItem(item);

		printf("P%01ld produziu %d\n", (long)id, item);

		pthread_mutex_unlock(&s_buffer);
		sem_post(&s_item);
   }
}

void *consumer(void *id) {
	int item;

	while(1) {
		/* sleep for a random period of time */
		sleep(1 / ((rand() % 10) + 1) );
		sem_wait(&s_item);
		pthread_mutex_lock(&s_buffer);
		/* generate a random number */
		item = removeItem();

		printf("                C%01ld consumiu %d\n", (long)id, item);

		pthread_mutex_unlock(&s_buffer);
		sem_post(&s_vaga);
   }
}

void init(){
	srand(time(NULL));

	pthread_mutex_init(&s_buffer, NULL);
	sem_init(&s_vaga, 0, 5);
	sem_init(&s_item, 0, 0);
}

int main (){
	int i;
	init();
	pthread_t thread [NUM_CONSUMERS + NUM_PRODUCERS] ;

	// CONSUMERS

	for (i = 0; i < NUM_CONSUMERS; ++i)
		pthread_create (&thread[i], NULL, consumer, (void *) i) ;

	// PRODUCERS
	for (i = NUM_CONSUMERS; i < NUM_CONSUMERS + NUM_PRODUCERS; ++i)
		pthread_create (&thread[i], NULL, producer, (void *) i) ;

	sleep(10);

	pthread_exit (NULL) ;
}