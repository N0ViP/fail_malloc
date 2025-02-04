# fail_malloc

`fail_malloc` is a custom implementation of the `malloc` function that simulates memory allocation failure based on a random chance. It logs the failure details to a file and returns `NULL` when the allocation fails.

## Features

- Simulates memory allocation failures with a 50% chance.
- Logs the failure with details about the source file, function name, and line number where the failure occurred.
- Allows integration with your code by replacing `malloc` with `fail_malloc`.

## Usage

To use `fail_malloc`, simply include the `fail_malloc.h` header and replace your calls to `malloc` with the `fail_malloc` function. The `fail_malloc` function will handle the memory allocation and failure simulation. If the allocation fails, a log entry is written to the `fail_malloc.log` file.

### Example Usage:

```c
#include "fail_malloc.h"

int main()
{
	char *res = malloc(100);
	if (!res)
	{
		perror("Malloc failed\n");
		return (1);
	}

	return (0);
}

```


#### How It Works:

1. The fail_malloc function overrides the malloc macro.
2. It generates a random number and, if the number is below 50, it simulates a failure by writing a message to the log file and returning NULL.
3. Otherwise, it performs a normal memory allocation using malloc.


##### Example Log Entry

Malloc failed at file main.c in function main in line 5

###### Compilation:

```bash
gcc -o your_program your_program.c fail_malloc.c
```

