*This project has been created as part of the 42 curriculum by gargrigo.*

# get_next_line ooooooo

## Description

The **get_next_line** project is a fundamental challenge in the 42 common core. The objective is to write a function that returns a single line read from a file descriptor.

This project introduces the concept of **static variables** in C programming and requires careful management of dynamic memory allocation. The function must handle repeated calls to read a text file one line at a time until the end of the file, regardless of the buffer size or the file's length.

### Features
- Reads from files, standard input, or even network sockets.
- Supports any `BUFFER_SIZE` defined at compile time.
- Efficiently manages memory to prevent leaks (using `valgrind` or `leaks` for verification).
- Handles multiple file descriptors simultaneously (if implemented in the bonus part).


### Why Use a Static Variable?
In C, standard local variables are deallocated when a function returns. By declaring our stash as `static char *stash`, we ensure that any data read but not yet returned remains available for the *next* time `get_next_line` is called.

---

## Instructions

### Compilation
The project must be compiled with the `-D BUFFER_SIZE=n` flag to define the buffer size for the `read()` function.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```
### Usage

To test the function, you can create a main.c that calls the function in a loop:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    return (0);
}
```

## Resources

### Documentation
- [Unix System Calls - Read](https://man7.org/linux/man-pages/man2/read.2.html): Official documentation for the read function.
- [Understanding Static Variables](https://www.geeksforgeeks.org/static-variables-in-c/): A guide on how static memory allocation differs from stack and heap.
- [Memory Leak Detection](https://valgrind.org/): Tools for ensuring all allocated memory is properly freed.

### AI Usage

AI was used in the following parts of this project:

- **README.md creation**: AI assistance was used to structure and write the README.md file according to 42 School requirements, including formatting and section organization.

- **Code review and debugging**: AI tools were consulted for debugging assistance when encountering compilation errors or logical issues in function implementations, particularly for edge cases and memory management.

All code implementations were written manually by the student, with AI used only for debugging assistance and understanding requirements.
