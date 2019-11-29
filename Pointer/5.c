#include<stdio.h>
int main(){
	char *ptr = "Pointer in c", arr[15];
	arr[15] = *ptr;
	printf("%c",arr[0]);
	return 0;
}
