#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - print a given string using _putchar()
 * @str: input string
 * Return: number of the printed characters
 */
int print_string(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_number - print a number using recursive
 * @n: a number to be printed.
 * Description: print a given number digit by digit
 * Return: void
 */
void print_number(int n)
{
	if (n == -2147483648) /* handle INT_MIN special case */
	{
		_putchar('-');
		_putchar('2');
		print_number(147483648);
		return;
	}
	else if (n < 0) /* negative number */
	{
		_putchar('-');
		n = -n;
	}
	if (n >= 10) /* multi-digit number*/
	{
		print_number(n / 10);
		_putchar((n % 10) + '0');
	}
	else /* number contains one digit */
	{
		_putchar(n + '0');
	}
}

/**
 * number_length - output the length of number
 * @number: input integer
 * Description: get the length of the input number using recursive
 * Return: integer - number length
 */
int number_length(int number)
{
	if (number == 0)
		return (0);
	return (1 + number_length(number / 10));
}

