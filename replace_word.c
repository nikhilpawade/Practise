#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	char line[256], str[64], str1[64];
	char *ptr, *ptr1;
	printf("Enter the line to replace\n");
	scanf("%[^\n]",line);
	printf("Enter the word to replace\n");
	scanf("%s",str);
	printf("Enter the new word\n");
	scanf("%s",str1);
	ptr = strstr(line, str);
	while (ptr != NULL) {
		ptr1 = ptr;
		for (i= 0 ; *ptr1 != ' ' && *ptr1 != '\0'; i++) {
			*ptr1 = str1[i];
			ptr1++;	
		}
		ptr = strstr(line, str);
//		printf("%s\n",line);
	}
//	*ptr1 = '\0';	
	printf("%s\n",line);
}
