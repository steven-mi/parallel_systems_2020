#include "core.h"
#include <stdlib.h>
#include <stdio.h>

/* This method check if a given number is inside the mantelbrot set
 * 
 * @param re real part of the number
 * @param im imaginary part of the number
 * @return 1 if its a mandelbrot number, 0 else
 */
int isMandelbrot(double re, double im)
{
	double Z_re = re;
	double Z_im = im;

	int mandelbrot = 1;
	for (unsigned n = 0; n < 100; ++n) // max number of iterations
	{
		double Z_re2 = Z_re * Z_re, Z_im2 = Z_im * Z_im;
		if (Z_re2 + Z_im2 > 4)
		{
			mandelbrot = 0;
			break;
		}
		Z_im = 2 * Z_re * Z_im + im;
		Z_re = Z_re2 - Z_im2 + re;
	}
	return mandelbrot;
}
