#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, c, max1, max2;
	int *ptr;
	printf("Enter the count\n");
	if (scanf("%d",&c) == 1) {
		ptr = malloc(sizeof(int) * c);
	}
	printf("Enter the number\n");
	for ( i = 0; i < c; i++) {
		if (scanf("%d",ptr+i) == 1);
	}
	
	if (*ptr < *(ptr +1)) {
		max1 = *ptr;
		max2 = *(ptr + 1);
	} else {
		max1 = *(ptr + 1);
		max2 = *ptr;
	}

	for (i = 2; i < c; i++) {
		if ( *(ptr + i) > max2) {
			max1 = max2;
			max2 = *(ptr + i);
		} else if ( *(ptr + i) > max1) {
			max1 = *(ptr + i);
		}
			
	}
	printf("%d %d", max1, max2);
	printf("Produnct = %d\n",max1*max2);
	return 0;
}
