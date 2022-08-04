#include <stdio.h>
int binary_search(int *a, int no, int start, int end)
{
	int mid;
	if ( end >= start) {
		int mid = (end + start) / 2;
		if (a[mid] == no) {
			return mid;
		}
		if (no < a[mid]) {
			return binary_search(a, no, start, mid-1);
		} else {
			return binary_search(a, no,  mid+1, end);
		}
	}
	return -1;
}

int main()
{
	int a[6] = {3,5,7,9,10,15}, no, mid;
	printf("Enter the number to serch\n");
	scanf("%d",&no);
	mid = binary_search(a, no, 0, 6);
	if (mid < 0) {
		printf("The number is not presnt\n");
	} else {
		printf("Find the number = %d at index = %d\n", a[mid] , mid);
	}
	return 0;
}
