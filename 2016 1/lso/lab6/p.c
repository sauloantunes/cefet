// int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
// int pthread_cond_signal(pthread_cond_t *cond);
// int pthread_cond_broadcast(pthread_cond_t *cond);
// int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
// int pthread_cond_destroy(pthread_cond_t *cond);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
/* class representing monitor for producer and consumer problem */
class monitor
{
static const int SIZE = 10; /* size of queue */
int queue[SIZE]; /* queue of products (values) */
int tail, head; /* tail and head of the queue */
int nr_of_prod; /* number of products in the queue */
pthread_cond_t not_full; /* used to suspend thread when queue is full */
pthread_cond_t not_empty; /* used to suspend thread when queue is empty */
pthread_mutex_t mutex; /* associated with condition variables */
public:
	monitor();
	~monitor();
	void put(const int);
	int get();
};
/* constructor of monitor’s object */
monitor::monitor()
{
 nr_of_prod = tail = head = 0; /* the queue is empty */
/* initialize a mutex and condition variables with default attributes */
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&not_full, NULL);
	pthread_cond_init(&not_empty, NULL);
}
monitor::~monitor()
{
/* destroy a mutex and conditional variables */
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&not_full);
	pthread_cond_destroy(&not_empty);
}
/* insert a new value to the queue */
void monitor::put(const int value)
{
 pthread_mutex_lock(&mutex); /* lock a mutex */
/* the queue is full - wait for free place in the queue */
	if (nr_of_prod == SIZE)
		pthread_cond_wait(&not_full, &mutex);
 queue[tail] = value; /* insert new value to the queue */
	nr_of_prod++;
	tail = (tail + 1) % SIZE;
 pthread_cond_signal(&not_empty); /* signal products in the queue */
 pthread_mutex_unlock(&mutex); /* release a mutex */
}
/* return a value from the queue */
int monitor::get()
{
 pthread_mutex_lock(&mutex); /* lock a mutex */
/* the queue is empty - wait for products in the queue */
	if (nr_of_prod == 0)
		pthread_cond_wait(&not_empty, &mutex);
 int value = queue[head]; /* take a value from the queue */
	nr_of_prod--;
	head = (head + 1) % SIZE;
 pthread_cond_signal(&not_full); /* signal free place in the queue */
 pthread_mutex_unlock(&mutex); /* release a mutex */
 return value; /* return a value taken from the queue */
}
 monitor prod_cons_mon; /* monitor used for producer and consumer problem */
 void *producer(void *arg) /* producer function */
{
	int value;
 do /* produce values (products) until produced value is non-zero */
	{
 value = rand() % 100; /* produce a value */
		printf("produced: %d\n", value);
 prod_cons_mon.put(value); /* insert produced value to the queue */
 sleep(rand() % 5); /* rest after production */
	}
	while(value);
 pthread_exit(NULL); /* terminate producer thread */
}
 void *consumer(void *arg) /* consumer function */
{
	int value;
 do /* consume values (products) until consumed value is non-zero */
	{
 value = prod_cons_mon.get(); /* get a first value from the queue */
		printf("consumed: %d\n", value);
 sleep(rand() % 5); /* consume taken product */
	}
	while(value);
 pthread_exit(NULL); /* terminate producer thread */
}
int main(int argc, char *argv[])
{
	pthread_t prod_t, cons_t;
 srand(time(0)); /* initialize a random number generator */
// create producer and consumer threads 
	pthread_create(&prod_t, NULL, producer, NULL);
	pthread_create(&cons_t, NULL, consumer, NULL);
// wait for terminate producer and consumer threads 
	pthread_join(prod_t, NULL);
	pthread_join(cons_t, NULL);
	return 0;
}