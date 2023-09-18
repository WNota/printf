# ALX — Custom `printf` Project in C Language

## Introduction

In this project, we're creating our own version of the commonly used printf function in C. This function is all about displaying text in a specific way on the screen. Our aim is to learn how it functions by building our version.

## Project Overview

Our custom `printf` function will take a format string as the first argument, followed by a variable number of additional arguments. The format string will contain placeholders for the data that needs to be printed, and our function will replace these placeholders with the corresponding values from the additional arguments.

## Steps to Implement

1. **Function Prototype**: Define the function prototype for a custom `printf` function. The function should have a return type of `int` and accept a `const char* format` parameter followed by a variable number of arguments using the ellipsis (`...`) syntax. The return value is the number of characters printed with the function (like regular printf() does).

2. **Parsing Format String**: Implement a mechanism to parse the format string and identify the placeholders. Common placeholders include `%c` for characters, `%s` for strings, `%d` for integers, etc.

3. **Handling Placeholders**: Once we identify a placeholder, we need to extract the corresponding argument from the variable argument list.  \
The `<stdarg.h>` header provides the macros and functions to handle variable arguments.

4. **Printing**: Replace the placeholders in the format string with the actual values and print the formatted output to the console. We used our `_putchar` function to print individual characters. \
`_putchar` act the same as the standard output function `putchar`.

5. **Edge Cases**: Handle edge cases such as invalid format strings, unsupported format specifiers, and other potential errors gracefully.

6. **Testing**: Create a set of test cases to verify that our custom `printf` function behaves correctly and produces the expected output for various format strings and arguments.

### *. . . More details will added here as we progress in the project*


## Team Members:
**Winnie Nota** — [*contact*](mailto:winnienota1@gmail.com) \
**Ouadia EL-Ouardy** — [*contact*](mailto:ouadia@el-ouardy.com)
