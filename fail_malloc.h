#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

#ifndef FAIL_MALLOC_H
#define FAIL_MALLOC_H

void* fail_malloc(size_t n, char* file, const char* func, int line);

#ifndef FAIL_MALLOC
#define malloc(n) fail_malloc((size_t) (n), __FILE__, __func__, __LINE__)
#endif


#endif
