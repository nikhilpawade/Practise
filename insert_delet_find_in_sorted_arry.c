#include <stdio.h>

int binary_search(int *arr, int start, int end, int key) {
	int mid = (end + start) / 2;
	printf("NIKHIL---------> %d\n", arr[mid]);
	if (end < start) {
		return -1;
	}
	if (arr[mid] == key) {
		return mid;
	}
	if (arr[mid] > key) {
		return binary_search(arr, 0, mid-1, key);
	} else {
		return binary_search(arr, mid+1, end, key);
	}
}
int find_element(int *arr, int start, int end, int key) {
	int mid;
	if (end < 0) {
		return -1;
	}

	mid = binary_search(arr, start, end, key);
	if (mid >= 0) {
		printf("Element %d present at index %d\n",arr[mid], mid);
	}
}

int insert_element(int *arr, int start, int end, int key, int n) {
	int i;
	if (n >= end) {
		return -1;
	}
	
	printf("Sorted Array before insert\n");
	for (i = 0; i < end; i++) {
		printf(" %d ",arr[i]);
	}
	printf("\n");
	for (i = n-1; (i >= 0 && arr[i] > key); i--) {
		arr[i+1] = arr[i];
		
	}
	arr[i+1] = key;
	printf("Sorted Array After insert\n");
	for (i = 0; i < end; i++) {
		printf(" %d ",arr[i]);
	}
	printf("\n");
}

int delet_element(int *arr, int start, int end, int key) {
	int i, index;
	
	printf("Sorted Array before delet\n");
	for (i = 0; i < end; i++) {
		printf(" %d ",arr[i]);
	}


	index = binary_search(arr, start, end, key);

	if (index < 0) {
		return -1;
	}
	for (i = index; i < end-1; i++) {
		arr[i] = arr[i+1];
	}

		
	printf("Sorted Array After delet\n");
	for (i = 0; i < end; i++) {
		printf(" %d ",arr[i]);
	}
	printf("\n");
}
int main() {
	int ch, key, capacity;
	int arr[10] = {0, 1, 4, 5, 7, 12,15};
	capacity = sizeof(arr) / sizeof(arr[0]);
	printf("PLease Enter the Choice [find = 0]  [insert = 1 ] [delete = 2]\n");
	scanf("%d",&ch);
	if (ch == 0) {
		printf("Please Enter key to find\n");
		scanf("%d",&key);
		find_element(arr, 0, capacity, key);
	} else if (ch == 1) {
		printf("Enter key to insert\n");
		scanf("%d",&key);
		insert_element(arr, 0, capacity, key, 7);
	} else if (ch == 2) {
		printf("Enter key to del\n");
		scanf("%d",&key);
		delet_element(arr, 0, capacity, key);
	}
}
