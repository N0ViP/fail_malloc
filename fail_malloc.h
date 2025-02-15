#ifndef FAIL_MALLOC_H
#define FAIL_MALLOC_H

#include <sys/random.h>	//arc4random
#include <unistd.h>	//close, dup2
#include <signal.h>	//signal
#include <stdlib.h>	//malloc
#include <stdio.h>	//dprintf
#include <fcntl.h>	//open
#include <time.h>	//time

#define PR 10		//probability of failure
#define	malloc(n) fail_malloc((size_t) (n), __FILE__, __func__, __LINE__)

void	close_fd(void);
void	open_logfile(void);
void	check_sigsegv(void);
void*	fail_malloc(size_t n, char* file, const char* func, int line);

#endif
