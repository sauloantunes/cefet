#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 16

void *threadBody (void *id)
{
   long tid = (long) id ;

   printf ("t%02ld: Olá!\n", tid) ;
   sleep (3) ;   
   printf ("t%02ld: Tchau!\n", tid) ;
   
   pthread_exit (NULL) ;
}

int main (int argc, char *argv[])
{
   pthread_t thread [NUM_THREADS] ; // Cria um vetor de threads
   long i, status ;
   
   for (i=0; i<NUM_THREADS; i++)
   {
      printf ("Main: criando thread %02ld\n", i) ;
      
      status = pthread_create (&thread[i], NULL, threadBody, (void *) i) ;
      // thread[i] = tid
      // NULL = atter; Atributos para criação da thread
      // threadBody = rotina da thread
      // i = argumentos da rotina da thread
      // Quando pthread_create é executado, não necessáriamente a rotina da thread é executada.
      // A thread vai para o estado de pronto

      if (status)
      {
         perror ("pthread_create") ;
         exit (1) ;
      }
   }
   pthread_exit (NULL) ;
}