#include <stdio.h>
#include <pthread.h>
pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
int count = 0;
#define MAX 10
void * odd_number(void* argc)
{
	while(1) {
		pthread_mutex_lock(&count_lock);
		if (count % 2 != 0) {
			pthread_cond_wait( &condition_var, &count_lock);
		}
		count++;
		printf("Odd Number = %d\n", count);
		pthread_cond_signal( &condition_var );
		if (count >= MAX) {
			pthread_mutex_unlock(&count_lock);
			return NULL;
		}
		pthread_mutex_unlock(&count_lock);

	}


}

void *even_number(void * argc)
{
	while(1) {
		pthread_mutex_lock(&count_lock);
		if (count %2 == 0) {
			pthread_cond_wait(&condition_var, &count_lock);
		}
		count++;
		printf("Even number = %d\n", count);
		pthread_cond_signal( &condition_var );
		if (count >= MAX) {
			pthread_mutex_unlock(&count_lock);
			return NULL;
		}
		pthread_mutex_unlock(&count_lock);

	}


}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, odd_number, NULL);
	pthread_create(&t2, NULL, even_number, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;

}
