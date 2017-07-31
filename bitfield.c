#include <stdio.h>
struct st {
	char a:4;
	char b:4;
	char c:4;
};
main() {
	struct st tmp;
	tmp.a = 4;
	printf("%d\n",tmp.a);	
}
