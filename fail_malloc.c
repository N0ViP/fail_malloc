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

static void	signal_handler(int __attribute__((unused)) signum)
{
	if (fd != -1)
		dprintf(fd, "SIGSEGV! Segmentation Fault detected!\n");
	exit(1);
}

__attribute__((constructor))

void	check_sigsegv(void)
{
	signal(SIGSEGV, signal_handler);
}

void*	fail_malloc(size_t n, char* file, const char* func, int line)
{
	static int x;

	if (!x)
		srandom(time(NULL));
	x =	rand() % 100 + 1;
	if (x <= PR)
	{
		if (fd != -1)
		{
			dprintf(fd, "Malloc failed at file %s in function %s in line %d\n", file, func, line);
		}
		return (NULL);
	}
	return (malloc(n));
}
