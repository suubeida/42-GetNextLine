*This activity has been created as part of the 42 curriculum by suobeida.*

# Get Next Line

## Description
**Get Next Line** is a core C programming project at 42 school. The objective is to implement a function that reads and returns a single line from a file descriptor (`fd`) each time it is called. 

Repeated calls to `get_next_line` allow reading an entire text file line-by-line until the end of file (EOF) is reached. The function handles reading from both standard files and standard input (`stdin`). Key technical goals include:
- Mastering static variables to retain unread buffer state across function calls.
- Efficiently managing memory to avoid memory leaks during dynamic allocation (`malloc` and `free`).
- Handling varying buffer sizes specified at compilation time via the `BUFFER_SIZE` macro.

## Instructions

### Compilation
Compile your code along with `get_next_line.c` and `get_next_line_utils.c`, defining the `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

### Usage
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Technical Choices

- **Static Stash Buffer:** A static pointer variable is used to store residual characters read from the file descriptor across successive calls.
- **Buffer Management:** Memory allocation dynamically scales to accommodate lines larger than `BUFFER_SIZE`.

## Resources
* [GNU C Library - File System Interface](https://www.gnu.org/software/libc/manual/html_node/File-System-Interface.html)
* [GeeksforGeeks - Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)

### AI Usage
AI tools were used for:
* **Concept & Logic Review:** Understanding the scope and behavior of static variables for buffer management across multiple function calls.
* **Debugging & Memory Leaks:** Identifying edge cases with `malloc` allocation failures and verifying proper memory freeing in utility functions.
* **General Understanding:** Provided assistance in understanding the bsic fundementals of file reading and handling as well as a deeper dive into how *read* works.