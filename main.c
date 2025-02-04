#include "fail_malloc.h"

int main()
{
	char *res = malloc(100);
	res[0] = 'x';

	return (0);
}

