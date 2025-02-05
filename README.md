[![Last Commit](https://img.shields.io/github/last-commit/N0ViP/fail_malloc)]()

# Fail Malloc

## Description

`fail_malloc` is a custom implementation of the `malloc` function, designed to simulate memory allocation failures for testing purposes. The function attempts to allocate memory with a configurable probability of failure, logging any failures to a file. This can be used for testing how your program behaves when memory allocation fails, helping to ensure more robust error handling.

## Features

- **Custom Memory Allocation**: Replaces the standard `malloc` function with `fail_malloc` to simulate failures.
- **Error Logging**: When memory allocation fails, the failure is logged in a file `fail_malloc.log`, including the file, function, and line where the failure occurred.
- **Signal Handling**: Catches segmentation faults (SIGSEGV) to log them and cleanly exit.
- **Configurable Failure Probability**: The probability of failure can be adjusted by changing the `PR` constant in `fail_malloc.h`.

## Installation

Simply include the `fail_malloc.c` and `fail_malloc.h` files in your project and compile them along with your other source files. No special installation process is required.

```bash
gcc -o my_program my_program.c fail_malloc.c
```

## Usage

To use `fail_malloc` in your project, include the `fail_malloc.h` header file, and call `malloc` as usual. The custom `fail_malloc` function will automatically replace the standard `malloc` function due to the macro definition:

```c
/* this program will exit with (SIGSEGV) if malloc failed */

#include "fail_malloc.h"

int main() {
    char *ptr = malloc(1);
    *ptr = 'X';

  return (0);
}
```

## Configuration

Failure Probability: The probability of a failure is set by the PR macro, which is currently set to 10 (i.e., 10%). You can modify this value in fail_malloc.h to adjust the failure rate.

```c
#define PR 10  // Probability of failure (1-100)
```

## Log File

Failures are logged to a file named `fail_malloc.log` in the current working directory. Each log entry includes:
- The file and function name where the failure occurred
- The line number where the failure occurred

**For example**:

```bash
Malloc failed at file main.c in function main in line 42
```

## Signal Handling

If a segmentation fault (SIGSEGV) is detected, the program will log the occurrence in `fail_malloc.log` and terminate gracefully.

```bash
SIGSEGV! Segmentation Fault detected!
```
