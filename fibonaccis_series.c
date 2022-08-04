#include<stdio.h>

int fib(int n) {
	if(n <= 1) {
		return 1;
	}
	return fib(n-1) + fib(n-2);



}
main() {
	int num;
	printf("Enter the number for fibnaccis series\n");
	scanf("%d",&num);
	printf("%d\n", fib(num));

}
