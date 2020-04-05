#include <stdio.h>
#include <stdlib.h>

#include "core.h"

int main(int argc, char **argv)
{
	int x,y;

	if (argc < 3)
	{
		fprintf(stderr,"Not enough arguments given!\n");
		return EXIT_FAILURE;
	}

	/* Normally, we would check for wrong input formats (i.e., no numbers) */
	x = atoi(argv[1]);
	y = atoi(argv[2]);

	printf("%d\n",diff(x,y));

	return EXIT_SUCCESS;
}
