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

reverse_words(char *string) {
	int length,length1,i;
	char *string1,*str;
	char token[2] = "-";
	length = strlen(string);
	printf("%s %d\n",string,length);
	string1 = (char*)malloc(sizeof(char)*length);
	string1 = string;
	printf("%s\n",string1);
	str = strtok(string,token);
	printf("%s\n",str);
	while(str !=NULL) {
		printf("%s\n",str);
		length1 = strlen(str);
		for(i=0;i<length1;i++) {
			string1[i] = str[length1-i];

		}
		printf("%s\n",str);
	}
	
	




}
