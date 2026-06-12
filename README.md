# ft_printf

## Description

A custom implementation of the C `printf` function, developed as part of the 42 School curriculum.

The goal of this project is to recreate the behavior of the original `printf` while handling variable argument lists through the `stdarg.h` library.

Supported conversions:

* `%c` Character
* `%s` String
* `%p` Pointer address
* `%d` Signed decimal integer
* `%i` Signed integer
* `%u` Unsigned decimal integer
* `%x` Lowercase hexadecimal
* `%X` Uppercase hexadecimal
* `%%` Percent sign

## Compilation

This project depends on the user's Libft, located inside the `libft/` directory.

To compile the library:

```bash
make
```

This will:

1. Compile Libft.
2. Compile ft_printf source files.
3. Generate `libftprintf.a`.

## Makefile Targets

* `make` or `make all`
  Compiles the project and creates `libftprintf.a`.

* `make clean`
  Removes object files from both ft_printf and Libft.

* `make fclean`
  Removes object files and generated libraries.

* `make re`
  Rebuilds the entire project.

* `make test`
  Builds a test executable using `main.c` (if available).

## Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Compile your project with:

```bash
cc your_file.c libftprintf.a -o your_program
```

Example:

```c
ft_printf("Hello %s!\n", "World");
```

## Project Structure

```text
.
├── ft_printf.c
├── vm_prints.c
├── utils.c
├── ft_printf.h
├── Makefile
└── libft/
```

## Resources

* https://cppreference.com/c
* https://man7.org/linux/man-pages/index.html
* https://youtu.be/3iX9a_l9W9Y

## What I Learned

During this project I practiced:

* Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
* Type conversions and formatting
* Hexadecimal number representation
* Building static libraries with `ar`
* Organizing projects with Makefiles
* Following the 42 Norm

## AI Usage

AI (ChatGPT) was used during this project for:

* Discussing variadic functions and `stdarg.h`
* Understanding pointer and hexadecimal conversions
* Reviewing code organization and refactoring ideas
* Understanding Makefile structure and library linking
* Assisting with project documentation

All implementation decisions, debugging, testing, and final code validation were performed manually.
