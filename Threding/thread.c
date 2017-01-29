#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *mythreadFun1(void *vargp) 
{
	sleep(1);
	printf("In thread 1----\n");
	return NULL;
}

main()
{
	pthread_t *tid;
	printf("Before thread start-------->\n");
	pthread_create(&tid, NULL, mythreadFun1, NULL);
	pthread_join(tid, NULL);
	printf("After thread--------------->\n");
	exit(0);
}	
