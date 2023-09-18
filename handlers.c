#include "main.h"

/**
 * get_handler_func - selects the correct function to execute
 * based on the format specifier
 * @sp: placeholder specifier
 * Return: pointer to the corresponding function OR NULL if it fails
 */
int (*get_handler_func(char sp))(va_list args)
{
	int index, array_size;

	placeholders_t placeholders[] = {
		{'c', handle_char},
		{'s', handle_string},
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
