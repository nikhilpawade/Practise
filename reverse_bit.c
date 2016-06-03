#include<stdio.h>
void print_bit(int num,int size) {
	size = size -1;
	for(;size>=0;size--) {
		printf("%d",1<<size & num ? 1 : 0);
	}
	printf("\n");

}
void reverse_bit(int num,int size) {
	int arr[size],i=0,n;
	n = size -1 ;
	for(;size>=0;size--) {
		arr[size] = 1<<size & num ? 1 : 0;
        }
	
	for(i=0;i<=n;i++) {
		printf("%d",arr[i]);
	}
	printf("\n");
	


}
main() 
{
	int i,n;
	printf("Enter the element\n");
	scanf("%d",&i);
	int size = sizeof(i) * 8;
	print_bit(i,size);
	reverse_bit(i,size);

}
