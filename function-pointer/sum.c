#include <stdio.h>
int sum(int a, int b) {
	return a + b;



}
int main() {
	int total;
	int (*funptr)(int,int);
	funptr = sum;
	total = funptr(10,10);
	printf("%d\n",total);




}

