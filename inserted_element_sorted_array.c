#include <stdio.h>

insert_arry(int *arr, int min, int max, int key)
{
	int mid, i;
	if ( min < 0) {
		return -1;
	}
	mid = (max - min) / 2;
	if (arr[mid] < key && arr[mid+1] > key) {
		for (i = mid+1; i < max; i++) {
			temp = arr[i+1];
			arr[i+1] = arr[i]
			
			
		}
	}
	
}
int main() {
	int min = 0, max, key;
	int arr[10] = {0,3,6,11,15};
	max = sizeof(arr)/ sizeof(arr[0]);
	printf("Enter value to insert\n");
	scanf("%d", &key);
	insert_arry(arr,min,max,key);
	
	printf("%d %d\n", arr[9], max);
}
