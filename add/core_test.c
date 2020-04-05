/**
 * Test for functions in core.c
 *
 * We don't need to test anything here really.
 */
#include <assert.h>

/* Include the module under testing */
#include "core.c"

/******************************************************/

static void test__add_calculates_sum(void)
{
	assert(5 == add(2,3));
	assert(-2 == add(-1,-1));
}

/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
	test__add_calculates_sum();
	return 0;
}
