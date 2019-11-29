#include <stdio.h>
main() {
	int a, b, c, k;
	printf("Enter the two value\n");
	scanf("%d", &a);
	scanf("%d",&b);
	printf("a = %d , b = %d\n", a , b);
	c = a -b;
	k = (c >> 31) & 0x1;
	printf("%d %d\n", c>>31, k );
	printf("Max = %d\n",(a - k * c));
}
