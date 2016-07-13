#include<stdio.h>
int find(int a[],int count) {
	int total,i;
	total = (count+1)*(count+2)/2;
	printf("%d\n",total);
	for(i=0;i<count;i++) {
		total-=a[i];
	}
	printf("Mising number = %d\n",total);
}
main() {
 int a[] ={1,2,3,5};
 find(a,4);
}
