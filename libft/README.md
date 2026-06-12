*This project has been created as part of the 42 curriculum by vfreitas.*

# Libft

## Description
This project focuses on understanding how standard C library functions work by reimplementing them from scratch, as well as creating additional utility functions to manipulate strings, memory, and linked lists.

## Instructions

### Compilation
To compile the library, simply run `make` in the root of the repository:

```bash
make
```

This will generate the `libft.a` file.

### Makefile Targets
- `make` or `make all`: Compiles the source files and creates the library.
- `make clean`: Removes the object files (`.o`).
- `make fclean`: Removes the object files and the compiled library (`libft.a`).
- `make re`: Recompiles the entire project (fclean + all).

### Usage
To use Libft in your own projects, include the header in your C files and link the library during compilation:

```c
#include "libft.h"
```

Compile your project with:
```bash
cc your_file.c libft.a -o your_program
```

## Librasy Description
The library is divided into three main parts:

### Part 1: Libc Functions
Reimplementation of standard functions from `<ctype.h>`, `<string.h>`, and `<stdlib.h>`:
- **Character checks:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`.
- **String manipulation:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`.
- **Memory manipulation:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`.
- **Conversions:** `ft_toupper`, `ft_tolower`, `ft_atoi`.
- **Memory allocation:** `ft_calloc`.

### Part 2: Additional Functions
Functions that are not part of the standard libc but are extremely useful:
- `ft_substr`: Extracts a substring from a string.
- `ft_strjoin`: Concatenates two strings into a new one.
- `ft_strtrim`: Trims characters from the beginning and end of a string.
- `ft_split`: Splits a string into an array of strings using a delimiter.
- `ft_itoa`: Converts an integer to a string.
- `ft_strmapi` / `ft_striteri`: Applies a function to each character of a string.
- `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd`: Output functions for specific file descriptors.

### Part 3: Linked List Functions
A set of functions to manipulate a singly linked list structure:
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Resources
- [Cppreference](https://cppreference.com/c)
- [Man pages (Linux programmer's manual)](https://man7.org/linux/man-pages/index.html)
- [Estrutura de dados usando C (Aaron M. Tenenbaum, Yedidyah Langsam, Moshe J. Augenstein)]

### AI Usage
AI (ChatGPT) was used during this project for the following tasks:
- **Prompt:** Using the description given in "AI Instructions," I created a prompt that would help me in developing and understanding the code.
- **Learning:** Understanding C programming concepts such as pointers, memory allocation, and string manipulation. Having something visual to base myself on helped me understand better. As recommended, I used it after reviewing it in my other resources and colleagues.
- **Documentation:** Structuring and drafting this `README.md` to ensure it meets all the curriculum requirements while maintaining a clear and natural tone.
- **Makefile Guidance:** Discussing the structure and purpose of Makefile rules used to build the library.