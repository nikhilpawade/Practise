#include <stdio.h>
char char_return(int a) {
	return (char)a;
}
int main() {
	char (*funcptr)(int) = char_return;
	unsigned char a = funcptr(10);
	printf("%c",a);

}
