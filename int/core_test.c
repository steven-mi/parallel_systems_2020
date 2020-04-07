#include <assert.h>
#include "core.c"

double const_func(double x);
void test_integrale_with_constant_function(void);

double const_func(double x)
{
	return 1;
}

void test_integrale_with_constant_function(void)
{
	assert(0.0 - integrale(&const_func, 1, 1, 10) < 0.0001);
	assert(0.0 - integrale(&const_func, 1, 1, 0) < 0.0001);
	assert(0.0 - integrale(&const_func, 1, 1, 10) < 0.0001);
	assert(0.0 - integrale(&const_func, -1, 1, 0) < 0.0001);
	assert(2.0 - integrale(&const_func, -1, 1, 10) < 0.0001);
	assert(2.0 - integrale(&const_func, 1, 3, 10) < 0.0001);
}

/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
	test_integrale_with_constant_function();
	return 0;
}
