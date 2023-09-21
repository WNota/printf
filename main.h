#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct placeholders - string placeholder struct
 *
 * @specifier: specifier character (ex: c / s / d ...etc)
 * @handler_func: The handler function associated
 */
typedef struct placeholders
{
	char specifier;
	int (*handler_func)(va_list args);
} placeholders_t;

/* handlers */
int handle_char(va_list args);
int handle_string(va_list args);
int handle_number(va_list args);

/* functions */
int (*get_handler_func(char sp))(va_list args);
int _putchar(char c);
int _printf(const char *format, ...);
int print_string(char *str);
void print_number(int n);
int number_length(int number);

#endif
