#include<stdio.h>
typedef union st {
	int no;
	char arr[2];
} st;
main() {
	st en;
	en.no=1;
	printf("%d\n",en.no);
	printf("%d %d\n",en.arr[0],en.arr[1]);
	//Another method
	int number = 1;
	int *p = &number;
	if(*p) {
		printf("Litil endian\n");
	} else {
		printf("Big endian\n");

	}

}
