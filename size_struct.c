#include <stdio.h>
struct st {
	int a;
	char b;
	double c;
};


main() {
	struct st *tmp;
	printf("%d\n",sizeof(struct st));
	return 0;
}
