#include <stdio.h>
#include <stdlib.h>

int main() {
	//code
	int n, i, diff = 0, j, k , bit1, bit2;
	int *a;
	printf("Number of elemnet in arry");
	scanf("%d", &n);
	a = malloc(sizeof(int)*(n+1));
	printf("Enter the array element");
	for (i=0; i < n; i++) {
	    scanf("%d",a+i);
	}
	
    for (i=0; i < n-1; i++ ) {
	printf("test1--> %d\n",i);
        for(j=i+1; j < n; j++) {
	printf("test2--> %d\n",j);
            for (k = 31; k >= 0; k--) {
                bit1 = *(a+i) >> k;
                bit2 = *(a+j) >> k;
		printf("Bit1 = %d Bit2 = %d\n", bit1, bit2);
                if (bit1 != bit2) {
                    diff++;

	printf("diff--> %d\n",diff);
                }
            }    
        }
        
    }
	printf ("Diff = %d",diff);
	return 0;
}
