//Given a sorted array and a number x, find the pair in array whose sum is closest to x.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int closest(int *arr, int n, int x)
{
	int i = 0, j = n-1;
	int diff = INT_MAX;
	int l, r;
	while( i < j) {
		if (abs((arr[i] + arr[j]) - x)  < diff) {
			l = i;
			r = j;
			diff = abs((arr[i] + arr[j]) - x);
		}
		if (arr[i] + arr[j]   < x) {
			i++;
		} else {
			j--;
		}
	}
	printf("Closest -->  %d %d \n", arr[l], arr[r]);	
}



int main() {
	int arr[] = {10, 22, 28, 29, 30, 40};
	int x = 54;
	int n = sizeof(arr)/sizeof(arr[0]);
	closest(arr, n, x);
	return 0;

}
