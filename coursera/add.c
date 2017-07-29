#include <stdio.h>
int main() {
	int a, b;
	printf("Enter the two numbers for addition\n");
	if (scanf("%d %d",&a, &b) == 2) {
		printf("%d\n",a+b);
	}
	return 0;
}
