#include "fail_malloc.h"

/* Undefine the malloc macro to avoid recursion with the custom fail_malloc implementation */

#ifdef malloc
#undef malloc
#endif

/* set fd as a global variable */

int	fd = -1;

__attribute__((constructor))

void	open_logfile(void)
{
	fd = open("fail_malloc.log", O_RDWR | O_APPEND | O_CREAT, 0744);
	if (fd != -1)
	{
		dup2(fd, 2);
	}
}

void*	fail_malloc(size_t n, char* file, const char* func, int line)
{
	int x = arc4random_uniform(2147483647) % 100;

	if (x < 50)
	{
		if (fd != -1)
		{
			dprintf(fd, "Malloc failed at file %s in function %s in line %d\n", file, func, line);
		}
		return (NULL);
	}

	return (malloc(n));
}
