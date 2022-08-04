#include<stdio.h>
/*
int find(int a[],int count) {
	int total,i;
	total = (count+1)*(count+2)/2;
	printf("%d\n",total);
	for(i=0;i<count;i++) {
		total-=a[i];
	}
	printf("Mising number = %d\n",total);
}*/

int find(int arr[], int size) {
	int a = 0, b = size -1;
	int mid;

	while ((b - a) > 1) {
		mid = (a + b) / 2;
		if ((arr[0] - a) != (arr[mid] - mid)) {
			b = mid;
		} else if ((arr[mid] - mid) != (arr[b] - b)) {
			a = mid;
		}


	} 

	return (arr[a] +1);


}
main() {
 int miss;
 int a[] ={1,2,3,5};
 miss = find(a,5);

 printf("Mising number = %d\n",miss);
}
