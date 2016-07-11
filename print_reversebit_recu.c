#include<stdio.h>
int print_bit(int num,int size) {
	if(size >= 0) {
		printf("%d",(num & (1 << size) ? 1:0));
		print_bit(num,size-1);
	}

}

int print_reverse_bit(int num,int size) {
	static int n = 31;
	if(size >= 0) {
		printf("%d",(num & (1 << n-size) ? 1:0));
		print_reverse_bit(num,size-1);
		

	}


}


main()
{
	int num,size;
	printf("Enter the Number\n");
	scanf("%d",&num);
	size = sizeof(num)*8;
	print_bit(num,size-1);
	printf("\n");
	print_reverse_bit(num,size-1);
	printf("\n");
}
