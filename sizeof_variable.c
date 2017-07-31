#include<stdio.h>
main()
{
	int *a,*s, v=10;
	a=&v;
	s=a;
	a++;
	int intsize=(int)a-(int)s;
	printf("%d\n",intsize);

	// anothr method 
	int b;
	printf("%u\n", (int)(&b+1)-(int)(&b));
}
