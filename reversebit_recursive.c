#include<stdio.h>
#include<stdlib.h>
int reverse(int num,int size,int length);
main(){
	int Num,size,length;
	printf("Enter the Number\n");
	scanf("%d",&Num);
	size = sizeof(Num)*8;
	length = size;
	reverse(Num,size-1,length);
}

int reverse(int num,int size,int length) {
	int arr[length];
	int i;
	if(size >= 0) {
		printf("%d",1<<size & num ? 1 : 0);
		arr[size] = (1<<size & num ? 1 : 0);
//		printf("TEST %d :",arr[size]);
		size--;
		reverse(num,size,length);
	} else {
		printf("\n");
		for(i=0 ;i<length;i++) {
//			printf("TEST ");
			printf("%d",arr[i]);
		}
		printf("\n");
	}




}
