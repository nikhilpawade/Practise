#include <stdio.h>
main()
{
	int i, j, tmp;
	int a[6] = {0,12,31,5,66,4};

	printf("Array before Sort\n");
	for (i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 6-1; i++) {
		for (j = 0; j < 6-i-1; j++) {
			if (a[j] > a[j+1]) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
	printf("Array After Sort\n");
	for (i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
}
