#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 16

void *threadBody(void *id)
{
   long tid = (long) id ;

   printf ("t%02ld: Olá!\n", tid) ;
   sleep (3) ;   
   printf ("t%02ld: Tchau!\n", tid) ;
   
   pthread_exit (NULL) ;
}

int main (int argc, char *argv[])
{
   pthread_t thread [NUM_THREADS] ;
   pthread_attr_t attr ;   
   long i, status ;
   
   pthread_attr_init (&attr) ;
   // The  pthread_attr_init()  function  initializes  the  thread 
   // attributes object pointed to by attr with default attribute values.
   
   pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE) ;
   // The detach state attribute determines whether a thread created 
   // using the thread attributes object attr will be  created  in  a  
   // joinable  or  a detached state.
   // default is PTHREAD_CREATE_JOINABLE.

   for(i=0; i<NUM_THREADS; i++)
   {
      printf ("Main: criando thread %02ld\n", i) ;
      
      status = pthread_create (&thread[i], &attr, threadBody, (void *) i) ;
      // Crias as thread passando o attr, que é a estrutura que contém os parâmentros
      // para criação de threads
      if (status)
      {
         perror ("pthread_create") ;
         exit (1) ;
      }
   }

   for (i=0; i<NUM_THREADS; i++)
   {
      printf ("Main: aguardando thread %02ld\n", i);
      status = pthread_join (thread[i], NULL) ;
      // The  pthread_join() function waits for the thread 
      // specified by thread to terminate.  If that thread 
      // has already terminated, then pthread_join() returns 
      // immediately.  The thread specified by thread must be joinable.

      // Em NULL, pode ser colocado um variável para receber o valor de saída do thread
      if (status)
      {
         perror ("pthread_join") ;
         exit (1) ;
      }
   }
   
   pthread_attr_destroy (&attr) ;
   
   pthread_exit (NULL) ;
}