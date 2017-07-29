#include <stdio.h>
int partition(int *a, int start, int end)
{
	int i,j, temp, pivot, pindex;
	pivot = a[end];
	pindex = start;
	for (i = start; i<end; i++) {
		if (a[i] <= pivot) {
			temp = a[i];
			a[i] = a[pindex];
			a[pindex] = temp;
			pindex++;
			
		} 
	}	
	temp = a[pindex];
	a[pindex] = a[end];
	a[end] = temp;
	
	return pindex;
}

int quik_sort(int *a, int start, int end) {
	int i, pindex;
	if (start < end) {
		pindex = partition(a,start,end);
		quik_sort(a, start,pindex - 1);
		quik_sort(a, pindex + 1, end);
	}

	for (i =0; i <5; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");

}
main()
{
	int i;
	int a[] ={11,8,6,56,7};
//	printf("Enter element of arry to sort\");
	for (i =0; i <5; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
	quik_sort(a,0,4);
	
}
