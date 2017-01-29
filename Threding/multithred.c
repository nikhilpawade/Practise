#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printEvenNum(void *data)
{
	void **tmp = data;
	int num;
	while(*tmp != NULL) {
		num = atoi(*tmp);
		if(num % 2 == 0) {
			printf("Thread 2 : ID %d Even Number = %d\n",(int)pthread_self(),num);
		}
		tmp++;
	}

}

void *printOddNum(void **data)
{
	void **tmp = data;
	int num;
	while(*tmp != NULL) {
		num = atoi(*tmp);
		if(num % 2 == 1) {
			printf("Thread 1 : ID %d Odd Number = %d\n",(int)pthread_self(),num);
		}
		tmp++;
	}


}

main(int argc, char **argv)
{
	int i, num;
	num = argc -1;
	pthread_t tid;
	if ( argc < 2) {
		printf("Enter the number\n");
		exit(0);
	}
	printf("Before thread start-------->\n");
		pthread_create(&tid, NULL, printEvenNum, argv+1);
		pthread_create(&tid, NULL, printOddNum, argv+1);
	pthread_join(tid, NULL);
	printf("After thread--------------->\n");
	exit(0);
}	
