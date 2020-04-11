#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "core.h"

int main(int argc, char **argv)
{
	double xsize = atoi(argv[1]);
	double ysize = atoi(argv[2]);
	double minRe = atoi(argv[3]);
	double maxRe = atoi(argv[4]);
	double minIm = atoi(argv[5]);
	double maxIm = atoi(argv[6]);

	printf("xsize %lf\n", xsize);
	printf("ysize %lf\n", ysize);
	printf("minRe %lf\n", minRe);
	printf("maxRe %lf\n", maxRe);
	printf("minIm %lf\n", minIm);
	printf("maxIm %lf\n", maxIm);

	// create empty image file
	FILE *out = fopen("mandelbrot.pgm", "wb");
	if (!out)
		return 0;
	fprintf(out, "P2\n%d %d\n%d\n", (int) xsize, (int) ysize, 255);

	// generate mandelbrot image
	//https://www.codingame.com/playgrounds/2358/how-to-plot-the-mandelbrot-set/mandelbrot-set
	//http://warp.povusers.org/Mandelbrot/
	double reFactor = (maxRe - minRe) / (xsize - 1);
	double imFactor = (maxIm - minIm) / (ysize - 1);
	for (int y = 0; y < ysize; y++)
	{
		for (int x = 0; x < xsize; x++)
		{
			double re = minRe + x * reFactor;
			double im = minIm + y * imFactor;

			if (isMandelbrot(re, im) == 1){
				fprintf(out, "%d ", 255);
			} 
			else{
				fprintf(out, "%d ", 0);
			} 
		}
		fprintf(out, "\n");
	}
	fclose(out);

	return EXIT_SUCCESS;
}
