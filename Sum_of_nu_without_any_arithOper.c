#include<stdio.h>
//May not work with C++ compilers and
// may produce warnings in C.
 
// Returns sum of 'a' and 'b'
int sum(int a, int b) 
{
    char *p = a;
    return (int)&p[b];
}

main() {
	int a,b,c;
	printf("Enter two number for addition\n");
	scanf("%d %d",&a,&b);
	c = sum(a,b);
	printf("Sum = %d\n",c);
}
