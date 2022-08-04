#include <string.h>
#include <stdio.h>

char * test () {
	char *p = "str";
	return p;
}

main() {
	char *q;
	q = test();
	printf("%s\n", q);
}
