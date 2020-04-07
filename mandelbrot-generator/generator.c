#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "core.h"

int write_pgm(unsigned char *name, unsigned char *buf, int xsize, int ysize, int maxvalue);

int write_pgm(unsigned char *name, unsigned char *buf, int xsize, int ysize, int maxvalue)
{
	FILE *out = fopen(name, "w");
	if (!out)
		return 0;
	fprintf(out, "P2\n%d %d\n%d\n", xsize, ysize, maxvalue);
	for (int y = 0; y < ysize; y++)
	{
		for (int x = 0; x < xsize; x++)
		{
			fprintf(out, "%d ", buf[y * xsize + x]);
		}
		fprintf(out, "\n");
	}
	fclose(out);
	return 1;
}


int main(int argc, char **argv)
{
	if (argc < 4)
	{
		fprintf(stderr, "Not enough arguments given!\n");
		return EXIT_FAILURE;
	}

	int steps = atoi(argv[1]); 
	int steps = atoi(argv[2]); 
	int steps = atoi(argv[3]); 

	printf("pi: %lf", pi);
	return EXIT_SUCCESS;
}
