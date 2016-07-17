#include<stdio.h>
main(){
	unsigned int i=128,j;
	for(j=0;j<4;j++) {
		printf("%d\n",*((char *)&i+j));
	}
}
