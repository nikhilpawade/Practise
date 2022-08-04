#include <stdio.h>

int main() {
	char arr[255];
	int i, t, ch, token;

	printf("Enter the line to tokenize\n");
	scanf("%[^\n]s", arr);
	
	t = 1;
	for (i =0; arr[i] != '\0'; i++) {
		if (arr[i] != ' ') {
			ch = 1;
		} else {
			t = 1;
			ch = 0;
		}

		if (ch == 1 && t == 1) {
			token ++;
			t = 0;
		}
	}
	printf("Number of token = %d\n", token);
}
