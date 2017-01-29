#include <stdio.h>
#include <stdlib.h>
main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Enter the number\n");
		exit(0);
	}
	printf("TEST %d \n",atoi(argv[1]));
}
