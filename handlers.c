#include "main.h"

/**
 * get_handler_func - selects the correct function to execute
 * based on the format specifier
 * @sp: placeholder specifier.
 * Return: pointer to the corresponding function OR NULL if it fails
 */
int (*get_handler_func(char sp))(va_list args)
{
	int index, array_size;

	placeholders_t placeholders[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'d', handle_number},
		{'i', handle_number},
		{'b', handle_binary}
	};

	/* get placeholders array size */
	array_size = sizeof(placeholders) / sizeof(placeholders[0]);

	/* loop over placeholders array to find a match */
	for (index = 0; index < array_size; index++)
	{
		if (placeholders[index].specifier == sp)
			return (placeholders[index].handler_func);
	}

	/* returning NULL indicates no match found*/
	return (NULL);
}

/**
 * handle_char - handle char argument
 * @args: variable arguments list
 * Return: printed characters count
 */
int handle_char(va_list args)
{

	/* print the character */
	_putchar(va_arg(args, int));

	return (1);
}

/**
 * handle_string - handle string argument
 * @args: variable arguments list
 * Return: printed characters count
 */
int handle_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		return (print_string("(null)"));
	}

	return (print_string(str));
}

/**
 * handle_number - handle number argument
 * @args: variable arguments list
 * Return: printed digitss count
 */
int handle_number(va_list args)
{
	int count = 0;
	int number_arg = va_arg(args, int);

	if (number_arg < 0) /* count minus (-) if number is negative */
		count++;

	/* count number digits */
	count += number_length(number_arg);

	print_number(number_arg);

	return (count);
}
/**
 * handle_binary - handles unsigned integer converted to binary
 * @num: number
 * Return: count (Success)
 */
int handle_binary(unsigned int num)
{
	int bits[sizeof(unsigned int) * 8];
	int count = 0;
	int i;

	for (i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
	{
		bits[i] = num % 2;
		num /= 2;
	}
	for (i = 0; i < sizeof(unsigned int) * 8; i++)
	{
		putchar(bits[i] + '0');
		count++;
	}
	return (count);
}
