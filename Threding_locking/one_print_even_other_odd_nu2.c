#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void *functionCount_odd(void* args);
void *functionCount_even(void* args);

int count = 0;

#define COUNT_DONE 10

int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, functionCount_odd, NULL);
	pthread_create(&thread2, NULL, functionCount_even, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

// Print odd numbers
void *functionCount_odd(void* args)
{
	for(;;) {
		// Lock mutex and then wait for signal to relase mutex
		pthread_mutex_lock( &count_mutex );
		if ( count % 2 != 0 ) {
			pthread_cond_wait( &condition_var, &count_mutex );
		}
		count++;
		printf("Counter value functionCount_odd: %d\n",count);
		pthread_cond_signal( &condition_var );
		if ( count >= COUNT_DONE ) {
			pthread_mutex_unlock( &count_mutex );
			return(NULL);
		}
		pthread_mutex_unlock( &count_mutex );
	}
}

// print even numbers
void *functionCount_even(void* args)
{
	for(;;) {
		// Lock mutex and then wait for signal to release mutex
		pthread_mutex_lock( &count_mutex );
		if ( count % 2 == 0 ) {
			pthread_cond_wait( &condition_var, &count_mutex );
		}

		count++;

		printf("Counter value functionCount_even: %d\n",count);
		pthread_cond_signal( &condition_var );
		if( count >= COUNT_DONE ) {
			pthread_mutex_unlock( &count_mutex );
			return(NULL);
		}
		pthread_mutex_unlock( &count_mutex );
	}
}
