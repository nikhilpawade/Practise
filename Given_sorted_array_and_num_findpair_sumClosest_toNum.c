#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void find_pair(int arr[], int num, int size)
{
	int diff = INT_MAX;
	int ind_l, ind_r;
	int l = 0, r = size -1;
	
	while(r > l) {
		if (abs(num - (arr[r] + arr[l])) < diff) {
			ind_l = arr[l];
			ind_r = arr[r];
			diff = abs(num - (arr[r] + arr[l]));
		
		}

		if (arr[l] + arr[r]  > num) {
			r--;
		} else {
			l++;
		}

	}
	printf("%d %d\n",ind_l, ind_r);

}
int main()
{
	int arr[] = {1,5,10,15,31,32,43};
	int num = 17;
	int size = sizeof(arr)/sizeof(arr[0]);
	find_pair(arr, num, size);

}
