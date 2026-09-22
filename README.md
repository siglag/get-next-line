_This activity has been created as part of the 42 curriculum by mohammah_

# get_next_line

A 42 project where the goal is to read and return one line at a time from a file descriptor.

This README is an early plan for how i want the implementation to work. It will probably change while i'm working on the project.

## How it should work

The main state between calls will be a `static` stash for each file descriptor:

```c
static char *stash[MAX_FD];
```

For every call to `get_next_line(fd)`:

1. Check if the stash already contains a `\n`.
2. If it does, extract and return that line without calling `read()` again.
3. If it doesn't, read another chunk and append it to the stash.
4. Keep reading until a `\n` is found or EOF is reached.
5. Keep everything after the returned line in the stash for the next call.
6. At EOF, return any remaining content as the last line, then clear the stash.

The implementation should work regardless of `BUFFER_SIZE`, since a line can be split across multiple reads and one read can contain multiple lines.

## Helpers

Since libft is not allowed here, i'll implement the small helpers i need myself, mainly for:

- string length
- finding `\n`
- joining strings
- extracting a line
