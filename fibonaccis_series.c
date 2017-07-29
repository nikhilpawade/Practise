#include<stdio.h>
fibo(int num) {
	int n = 0;
	if(num != 0) {
		printf("%d ",fibo( n--));

	}



}
main() {
	int num;
	printf("Enter the number for fibnaccis series\n");
	scanf("%d",&num);
	fibo(num);




}
