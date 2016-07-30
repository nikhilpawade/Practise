#include<stdio.h>
int add(int a,int b) {

	printf("Addition = %d\n",a+b);
}

int sub(int a,int b) {

	printf("Subtraction = %d\n",a-b);

}

int mul(int a,int b) {

	printf("Multiplication = %d\n",a*b);
}

int div(int a,int b) {
	printf("Div = %d\n",a/b);

}

main() {
	int ( *func_ptr_arr[])(int,int) = {add,sub,mul,div};
	int ch,a=15,b=10;
	printf("Enter the choice ADD 0 , sub 1 , mul 2 , div 3\n");
	scanf("%d",&ch);
	if(ch < 0 && ch >3) return 0;
	(*func_ptr_arr[ch])(a,b);



}
