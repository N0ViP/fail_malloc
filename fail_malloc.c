#include "fail_malloc.h"

/* Undefine the malloc macro to avoid recursion with the custom fail_malloc implementation */

#ifdef malloc
#undef malloc
#endif

void* fail_malloc(size_t n, char* file, const char* func, int line)
{
	umask(0);
	srandom(time(NULL));
	long x = random() % 100;
	if (x < 50)
	{
		int fd = open("fail_malloc.log", O_RDWR | O_APPEND | O_CREAT, 0744);
		if (fd == -1)
			return (NULL);
		dprintf(fd, "Malloc failed at file %s in function %s in line %d\n", file, func, line);
		close(fd);
		return (NULL);
	}
	return (malloc(n));
}
