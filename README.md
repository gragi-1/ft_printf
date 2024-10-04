# ft_printf Project

## Overview

The `ft_printf` project recreates the libc `printf` function. This custom `printf` function, named `ft_printf`, aims to mimic the behavior of the original `printf` - handling format specifiers and variable argument lists. This project is a deep dive into C programming, focusing on variadic functions, string parsing, and formatting output. Using the [libft]((https://github.com/gragi-1/libft)) project

## Objective

The primary goal is to learn about low-level programming by reimplementing the `printf` function from the C standard library. This includes handling a variable number of arguments and understanding how to implement different format specifiers for printing various types of data.

## Features

- Handles conversion specifiers: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`.
- Supports width, precision, and flags for detailed formatting.
- Utilizes variadic functions to accept an undefined number of arguments.
- Mimics the original `printf` behavior as closely as possible.

## Compilation and Usage

The project includes a Makefile for easy compilation of the library:

```bash
make all
```

This will compile the libftprintf.a library which you can then link to your C programs.

Example usage of ft_printf in a C program:

```C
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    return (0);
}
```

To compile a program with libftprintf.a, use:

```bash
gcc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program
```

## Project Structure

- **ft_printf.c:** The main function implementation.
- **ft_printf.h:** Header file containing function prototypes and structure definitions.
- **ft_strings_print.c:** Helper functions for string and character printing.
- **Makefile:** Contains rules for compiling the library and cleaning up object files.

## Contribution

This project is part of the 42 School curriculum. Contributions are not expected, but feedback is always welcome.
