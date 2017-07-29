#include<stdio.h>
#include<string.h>
int max(char *num) {
	printf("NUM = %s\n",num);
	int max = 0,j;
	char *str,*sevptr;
	str = strtok_r(num,",",&sevptr);
//	while(str != NULL) {
	for (j = 1, str = num; ; j++, str = NULL) {

	
		
		str = strtok_r(num,",",&sevptr);
		if(max < atoi(str)) {
			max = atoi(str);
			
		}
		printf("%d\n",atoi(str));
		if(str == NULL)
			break;
//		str = strtok_r(NULL,",",&sevptr);
	}
	printf("MAX Number = %d\n",max);



}

main() {
	char num[] = "1,2,3,4,5,6,7,8";
	max(num);
	max(num);



}
