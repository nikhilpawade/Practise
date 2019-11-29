#include <stdio.h>
int main()
{
	int a[5] = {0,1,2,3,4};
	int *p = a;
	printf("%d %d %d\n", sizeof(a), sizeof(a[0]), sizeof(&a));
	printf("%u %u %u %u\n",a, a+1 , &a+1, &a[0]+1);
	printf("%d %d %d\n", sizeof(a), sizeof(a[0]), sizeof(&a));
}
