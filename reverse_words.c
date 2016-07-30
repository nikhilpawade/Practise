/* Write a program to reverse all words in a sentence
 so that the sentence remains as it is but the words 
 are all reversed and placed at same position
 e.g. Q. I am at home
      A. I ma ta emoh
      Q. My name is Nikhil
      A. yM eman si lihkiN
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void * reverse_words(char*);
main()
{
	char string[100];
	printf("Enter the string\n");
	scanf("%[^\n]s",string);
	reverse_words(string);
}

void *reverse_words(char *string) {
	int length,i;
	char *string1,*str;
	int c =0;
	length = strlen(string);
	string1 = (char*)malloc(sizeof(char)*length);
	str = strtok(string," .-");
	while(str != NULL){
		length = strlen(str);
		length--;
		for(i=0;i<=length;i++) {
			string1[c] = str[length-i];
			c++;
		}
		string1[c] = ' ';
		c++;
		str = strtok(NULL," .-");
	}
	printf("%s\n",string1);
	return 0;




}
