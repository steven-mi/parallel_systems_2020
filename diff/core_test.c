/**
 * Test for functions in core.c
 *
 * We don't need to test anything here really.
 */
#include <assert.h>

/* Include the module under testing */
#include "core.c"

/******************************************************/

static void test_diff_calculates_diff(void)
{
	assert(-1 == diff(2,3));
	assert(0 == diff(-1,-1));
}

/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
	test_diff_calculates_diff();
	return 0;
}
