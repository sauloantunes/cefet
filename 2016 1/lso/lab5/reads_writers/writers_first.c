#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <limits.h>
#include <semaphore.h>
#include <time.h>
#include "check.h"
#include <syscall.h>

/* mutex para travar os leitores*/
pthread_mutex_t r_mutex;

/* mutex para atualizar a quantidade de escritores*/
pthread_mutex_t mutex;

/* mutex para atualizar a variável compartilhada*/
pthread_mutex_t writer_mutex;


/* Número de escritores */
int writer_count=0;
/*Dado compartilhado*/
int shared_data=1;

pthread_t tid;       //Thread ID
pthread_attr_t attr; //Set of thread attributes

void *writer(void *param);
void *reader(void *param);

void *writer(void *param) {
   while(1) {
		/***Atualiza: writer_count***/
      pthread_mutex_lock(&mutex);
		writer_count++;
		/***O primeiro escritor bloqueia os leitores***/
		if(writer_count==1)
	      pthread_mutex_lock(&r_mutex);
      pthread_mutex_unlock(&mutex);
		/*REALIZA A ESCRITA*/
		//É NECESSÁRIO ESTE MUTEX?
      pthread_mutex_lock(&writer_mutex);
		shared_data++;
		printf("\n(%07d) -- wrote: %05d",syscall(SYS_gettid),shared_data);
      sleep(1); //Suponha uma operação "relativamente" demorada.
      pthread_mutex_unlock(&writer_mutex);
		/***Atualiza: writer_count***/
      pthread_mutex_lock(&mutex);
		writer_count--;
		//O último escritor libera os leitores.
		if(writer_count==0)
	      pthread_mutex_unlock(&r_mutex);
      pthread_mutex_unlock(&mutex);
		sleep(rand()%10+1);
   }
}

void *reader(void *param) {
   while(1) {
		//É NECESSÁRIO ESTE MUTEX ? NÃO BASTARIA APENAS REALIZAR A LEITURA?
      pthread_mutex_lock(&r_mutex);
		printf("\n(%07d) -- read: %05d",syscall(SYS_gettid),shared_data);
      pthread_mutex_unlock(&r_mutex);
		sleep(rand()%10+1);

   }
}

int main(int argc, char *argv[]) {
	srand(time(0)); 
   /* Verify the correct number of arguments were passed in */
   if(argc != 4) {
      fprintf(stderr, "USAGE:./main.out <INT> <INT> <INT>\n");
		exit(1);
   }

   int mainSleepTime = atoi(argv[1]); /* Time in seconds for main to sleep */
   int numWriter = atoi(argv[2]); /* Number of writers*/
   int numReader = atoi(argv[3]); /* Number of readers*/

   /* Initialize the app */
   pthread_mutex_init(&r_mutex, NULL);
   pthread_mutex_init(&mutex, NULL);
   pthread_mutex_init(&writer_mutex, NULL);

   writer_count = 0;

   pthread_t * thread  =  malloc ((numWriter+numReader)*sizeof(pthread_t));
   /* Create the writer threads */
	int i;
   for(i = 0; i < numWriter; i++) {
      /* Create the thread */
      thread[i]=pthread_create(&tid,&attr,writer,NULL);
    }

   /* Create the reader threads */
   for(i = 0; i < numReader; i++) {
      /* Create the thread */
      thread[numReader+i]=pthread_create(&tid,&attr,reader,NULL);
   }

   /* Sleep for the specified amount of time in milliseconds */
   sleep(mainSleepTime);

   /* Exit the program */
   printf("\nExit the program\n");
   exit(0);
}

