_This activity has been created as part of the 42 curriculum by mohammah_

# get_next_line

## Description

`get_next_line` is a 42 project where the goal is to implement a function that reads and returns one line at a time from a file descriptor.

The function must work with any `BUFFER_SIZE`, correctly handle EOF, preserve unread data between calls, and manage dynamically allocated memory.

```c
char *get_next_line(int fd);
```

## Instructions

Compile the project with:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

You can test different buffer sizes with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 \
    get_next_line.c get_next_line_utils.c main.c
```

The default `BUFFER_SIZE` is defined in `get_next_line.h`.

## Algorithm

The implementation keeps unread data in a static **stash**.

On each call:

1. Check whether the stash already contains `\n`.
2. If not, read more data and append it to the stash.
3. Extract the first line from the stash.
4. Keep everything after that line for the next call.
5. If EOF is reached, return any remaining data as the final line.

For example:

```text
stash: "Hello\nWorld"
        ↓
return: "Hello\n"
stash: "World"
```

This approach is necessary because a single `read()` can contain part of a line, one line, or multiple lines. The stash keeps the unread portion between calls.

Checking the stash before reading also prevents unnecessary `read()` calls when a complete line is already available.

## Resources

- `read(2)` — Linux manual page // used internally in the function
- `open(2)` — Linux manual page // both open and close will be used in testing
- `close(2)` — Linux manual page
- `malloc(3)` — Linux manual page // used for mem allocations
- 42 `get_next_line` subject

### AI usage

AI was used for code review and debugging, mainly to identify edge cases, review memory management, and improve the implementation and documentation.
