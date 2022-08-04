#include <stdio.h>
int reverse_string(char *str)
{
	char *end = str, tmp;
	if (str) {
		while(*end) {
			++end;
		}
		end--;
		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
		
	}
	
		
}
int main()
{
	char str[100];
	printf("Enter the string to reverse\n");
	scanf("%s", str);
	reverse_string(str);
	printf("Reverse string = %s\n", str);
}
