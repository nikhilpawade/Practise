#include <stdio.h>

int concate(int a, int b)
{
	int pow = 10;
	while(b > pow) {
		pow *= 10;
	}
	return a * pow + b;
}

void form_big_number(int a[], int size)
{
	int i, j, num1, num2, tmp;
        // sort a given array by concate 
	for (i = 0; i < size-1; i++) {
		for(j = i+1; j < size;j++) {
			num1 = concate(a[i],a[j]);
			num2 = concate(a[j], a[i]);
			if (num1 < num2) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			
		}
	}
	for (i = 0; i < size; i++) {
		printf("%d", a[i]);

	}
	printf("\n");

}

int main()
{
	int a[] = { 12,34,456,67,98,9,32};
	int size = sizeof(a)/sizeof(a[0]);
	form_big_number(a, size);
	return 0;

}
