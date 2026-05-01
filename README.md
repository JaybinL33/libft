*This project has been created as part of the 42 curriculum by jungblee.*

# Libft

## Description
Libft is a library of C functions re-implemented as part of the 42 Gyeongsan curriculum. It includes versions of standard C library functions (`libc`) as well as additional utility functions for string manipulation, memory management, linked list handling, and formatted output.

## Library Functions

### Libc Functions
- `ft_isalpha`: Checks if a character is alphabetic.
- `ft_isdigit`: Checks if a character is a digit.
- `ft_isalnum`: Checks if a character is alphanumeric.
- `ft_isascii`: Checks if a character is ASCII.
- `ft_isprint`: Checks if a character is printable.
- `ft_strlen`: Calculates the length of a string.
- `ft_memset`: Fills memory with a constant byte.
- `ft_bzero`: Sets memory to zero.
- `ft_memcpy`: Copies memory area.
- `ft_memmove`: Copies memory area, handling overlapping regions.
- `ft_strlcpy`: Copies a string to a specific size.
- `ft_strlcat`: Concatenates a string to a specific size.
- `ft_toupper`: Converts a character to uppercase.
- `ft_tolower`: Converts a character to lowercase.
- `ft_strchr`: Locates a character in a string.
- `ft_strrchr`: Locates a character in a string from the end.
- `ft_strncmp`: Compares two strings up to a specific number of characters.
- `ft_memchr`: Scans memory for a character.
- `ft_memcmp`: Compares memory areas.
- `ft_strnstr`: Locates a substring in a string within a specific length.
- `ft_atoi`: Converts a string to an integer.
- `ft_calloc`: Allocates memory and initializes it to zero.
- `ft_strdup`: Duplicates a string.

### Additional Functions
- `ft_substr`: Extracts a substring from a string.
- `ft_strjoin`: Concatenates two strings.
- `ft_strtrim`: Trims specified characters from the beginning and end of a string.
- `ft_split`: Splits a string into an array of strings using a delimiter.
- `ft_itoa`: Converts an integer to a string.
- `ft_strmapi`: Applies a function to each character of a string to create a new one.
- `ft_striteri`: Applies a function to each character of a string (modifies in-place).
- `ft_putchar_fd`: Outputs a character to a file descriptor.
- `ft_putstr_fd`: Outputs a string to a file descriptor.
- `ft_putendl_fd`: Outputs a string followed by a newline to a file descriptor.
- `ft_putnbr_fd`: Outputs an integer to a file descriptor.

### Formatted Output
- `ft_printf`: Writes formatted output to standard output.
- `ft_dprintf`: Writes formatted output to a file descriptor.
- `ft_vdprintf`: Writes formatted output from a `va_list` to a file descriptor.

Supported conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
All formatted-output functions are included in `libft.a`; no separate `libftprintf.a` is required.

### Linked List Functions
These functions use the `t_list` structure defined in `libft.h`:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
```
- `ft_lstnew`: Creates a new list node.
- `ft_lstadd_front`: Adds a node to the beginning of a list.
- `ft_lstsize`: Counts the number of nodes in a list.
- `ft_lstlast`: Returns the last node of a list.
- `ft_lstadd_back`: Adds a node to the end of a list.
- `ft_lstdelone`: Frees a single list node using a provided function.
- `ft_lstclear`: Frees an entire list and its contents.
- `ft_lstiter`: Applies a function to the content of every node in a list.
- `ft_lstmap`: Creates a new list by applying a function to the content of every node.

## Function Contract & Undefined Behavior

To maintain consistency with the C standard library, `libft` follows specific rules regarding argument validity. Unless explicitly stated otherwise, the following conditions result in **Undefined Behavior (UB)**:

### General Rules
- **NULL Pointers:** Passing `NULL` as an argument to any function that expects a pointer (strings, function pointers, list pointers) is UB, unless the function is explicitly documented to handle `NULL`.
- **Invalid File Descriptors:** Passing an invalid or negative file descriptor to `ft_put*_fd` functions is UB.
- **Overlap:** For functions like `ft_memcpy`, providing overlapping memory regions is UB (use `ft_memmove` for overlapping regions).

### Specific UB Cases
- **String Functions:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`, `ft_putstr_fd`, `ft_putendl_fd` assume all `char *` arguments are valid, null-terminated strings. Passing `NULL` will result in a crash or unpredictable behavior.
- **List Functions:** 
    - `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstclear` require a valid pointer to a list pointer (`t_list **`).
    - `ft_lstadd_front` requires a valid `new` node pointer; passing `NULL` is UB.
    - `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` require valid function pointers.
- **Memory Allocation:** While not UB, all functions that allocate memory (e.g., `ft_calloc`, `ft_strdup`, `ft_strjoin`) will return `NULL` if the allocation fails.

## Instructions

### Compilation
The library is compiled into `libft.a` using the provided `Makefile`.

To compile the library:
```bash
make
```

To remove object files:
```bash
make clean
```

To remove object files and the library file:
```bash
make fclean
```

To recompile the library:
```bash
make re
```

### Usage
To use the library in a C project, include the required module header and link `libft.a`:
```c
#include "ft_printf.h"
```
```bash
cc main.c -I include -L. -lft
```

## Resources
- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)

### AI Usage
AI (Gemini CLI) was used for:
- Organizing the list of functions and their descriptions.
- Formatting the README file structure.
- Extracting technical details from the `libft.h` and `Makefile`.
