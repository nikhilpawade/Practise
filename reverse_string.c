#include<stdio.h>
#include<string.h>
main() {

	char str[100],tmp;
	int i,j=0;
	printf("Enter string\n");
	scanf("%s",str);
	i= 0;
	j = strlen(str) -1;
	while(i<j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;


	}
	printf("%s\n",str);

}
