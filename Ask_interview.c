#include <stdio.h>
int main()
{
	char a[] = “hello”;
	char *ptr = “hello”;
	ptr = “world”;
	*(ptr +1) = ‘a’;

/*
  
	int *ptr  = {1, 2, 3, 4, 5, 6};
	int (*ptr)[3] = a;
	printf("%d %d ", (*ptr)[1], (*ptr)[2]);
	++ptr;
	printf("%d %d\n", (*ptr)[1], (*ptr)[2]);



	char *a = "India";
	char b[] = "India";
	a = a+1;
	b = b+1;

			 // increment the base address is invalid
	char b[] = "India hsjhfks";


	int* array = new int[10];     
	delete array;  //delete [] array;


	*(*(arr + i) + j). —> 2d array

	int a[10];
	int *p; 
	p=a; //legal
	a=p; //illegal
	//Arithmetic on pointer variable is allowed.
	p++; //Legal
	a++; //illegal 
*/

}
/*
struct Widget{
    Widget(int){}
};

void fun(std::unique_ptr<Widget> uniqPtr){
    // do something with uniqPtr
}

int main(){
    auto uniqPtr = std::make_unique<Widget>(1998);
    fun(uniqPtr); 
}


Implement vector

Difference between unit ptr,smamt ptr ….other
*/

