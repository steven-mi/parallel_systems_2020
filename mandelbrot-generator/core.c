#include "core.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * This is a simple function to calculate the integral of a function f in between two values l and r
 *
 * @param f method which returns a value
 * @param l left integral boundary
 * @param r right integral boundary
 * @param steps amount of steps 
 * @return the diff of x and y
 */
double integrale(double (*f)(double x), double l, double r, int steps)
{
	if (steps <= 0 || l == r)
	{
		return 0.0;
	}

	double increment = abs(r - l) / (double)steps;
	double result = 0.0;

#pragma omp parallel for reduction(+ \
								   : result)
	for (int i = 0; i < steps; i++)
	{
		double index = l + (double)i * increment;
		double area = f(index) * increment;

#pragma omp atomic
		result = result + area;
	}
	return result;
}


