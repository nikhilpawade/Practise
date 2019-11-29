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
	for (i = 0; i < 6; i++) {
		for (j = i+1; j < 6; j++) {
			if (a[i] > a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	printf("Array After Sort\n");
	for (i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
}
