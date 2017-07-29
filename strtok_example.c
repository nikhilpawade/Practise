#include<stdio.h>
#include<string.h>
int max(char *num) {
	printf("NUM = %s\n",num);
	int max = 0;
	char *str;
	str = strtok_r(num,",");
	while(str != NULL) {
		if(max < atoi(str)) {
			max = atoi(str);
			
		}
		str = strtok_r(NULL,",");
	}
	printf("MAX Number = %d\n",max);



}

main() {
	char num[] = "1,2,3,4,5,6,7,8";
	max(num);
	max(num);



}
