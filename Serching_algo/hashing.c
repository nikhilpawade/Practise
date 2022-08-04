#include <stdio.h>
#include <limits.h>

int display(int arr[], int size)
{
	int i = 0;
	printf("Index  Value\n");
	for (i = 0; i < size; i++) {
		printf("%d  %d\n", i, arr[i]);
	}
}

int delete(int arr[], int hfn, int size)
{
	int no, n = 0, pos;
	printf("Enter element to delete\n");
	scanf("%d", &no);
	
	pos = no % hfn;

	while (n++ != size) {
		if (arr[pos] == INT_MIN) {
			printf("Element not found in hash table\n");
		} else if (arr[pos] == no) {
			arr[pos] = INT_MAX;
			printf("Element deleted\n");
			break;
		} else {
			pos = (pos+1) % hfn;
		}
	}
}

int serching(int arr[], int hfn, int size)
{
	int no, n =0, pos;
	printf("Enter the element to serch\n");
	scanf("%d", &no);
	
	pos = no % hfn;

	while (n++ != size) {
		if (arr[pos] == no) {
			printf("Element found at index %d\n", pos);
			break;
		} else {
			if (arr[pos] == INT_MAX || arr[pos] != INT_MIN) {
				pos = (pos+1) % hfn;
			}

		}
		
	}
	if (--n == size) {
		printf("Element not found\n");
	}
}

int insert(int arr[], int hfn, int size)
{
	int no,n=0, pos;
	printf("Enter the elememnt to insert\n");
	scanf("%d", &no);
	pos = no % hfn;
	
	while (arr[pos] != INT_MIN ) {
		if (arr[pos] == INT_MAX) {
			break;
		}
		pos = (pos+1) % hfn;
		n++;
		if (n == size) {
			break;
		}
		
	}
	
	if (n == size) {
		printf("Hash table is full\n");
	} else {
		arr[pos] = no;
	}
	
}

int main()
{
	int size, hfn, i , choice;
	printf("Enter the size of hash table\n");
	scanf("%d", &size);
	
	printf("Enter the hash function [if mod 10 enter 10]\n");
	scanf("%d", &hfn);

	int arr[size];

	for (i = 0; i < size; i++) {
		arr[i] = INT_MIN; // Assigning INT_MIN to indicate cell is empty.
	}

	do {
		printf("Enter your Choice\n");
		printf("1-> Insert\n 2-> Delete\n 3-> Display\n 4-> Searching\n 0-> Exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				insert(arr, hfn, size);
				break;
			case 2:
				delete(arr, hfn, size);
				break;
			case 3:
				display(arr, size);
				break;
			case 4:
				serching(arr, hfn, size);
				break;
			default:
				printf("Enter the correct choice\n");
				break;
			
		}
	} while(choice);
	
	return 0;
	

	
	
}
