#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "core.h"

double function(double x);

double function(double x)
{
	return sqrt(1.0 - (x * x));
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Not enough arguments given!\n");
		return EXIT_FAILURE;
	}

	int steps = atoi(argv[1]); // Normally, we would check for wrong input formats (i.e., no numbers)
	double pi = integrale(&function, -1, 1, steps) * 2;
	printf("pi: %lf", pi);
	return EXIT_SUCCESS;
}
