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
		{'d', handle_number},
		{'i', handle_number},
		{'b', handle_binary},
		{'r', handle_reversed_string},
		{'R', handle_rot13string}
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

	/* get string argument */
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

	/* get number argument */
	int number_arg = va_arg(args, int);

	if (number_arg <= 0) /* count minus if number is negative or equal 0 */
		count++;

	/* count number digits */
	count += number_length(number_arg);

	print_number(number_arg);

	return (count);
}

/**
 * handle_binary - handle binary argument
 * @args: variable arguments list
 * Return: printed characters count
 */
int handle_binary(va_list args)
{
	int binary[32]; /* Array to store binary digits */
	int i, index = 0;

	/* get decimal argument */
	int decimal = va_arg(args, int);

	if (decimal == 0)
	{
		_putchar(0 + '0');
		return (1);
	}
	/* Handle negative numbers */
	if (decimal < 0)
	{
		/* Convert to the two's complement representation */
		int mask = 1 << 31;  /* Mask with the most significant bit set */

		for (i = 0; i < 32; i++)
		{
			binary[index++] = (decimal & mask) ? 1 : 0;
			decimal <<= 1;  /* Left shift by 1 */
		}
		/* Print the binary representation */
		for (i = 0; i < index; i++)
			_putchar(binary[i] + '0');
	}
	else
	{
		while (decimal > 0)
		{
			binary[index] = decimal % 2; /* Get the remainder (0 or 1) */
			decimal = decimal / 2;       /* Divide the decimal number by 2 */
			index++; /* Move to the next position in the binary array */
		}
		/* Print the binary representation in reverse order */
		for (i = index - 1; i >= 0; i--)
			_putchar(binary[i] + '0');
	}
	return (index);
}

/**
 * handle_reversed_string - handle string in reverse specifier
 * @args: variable arguments list
 * Return: printed characters count
 */
int handle_reversed_string(va_list args)
{
	int i = 0, count = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = ")Null(";
	}

	/* get string length */
	while (str[i])
		i++;

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}

/**
 * handle_rot13string - handle rot13string custom conversion specifier
 * @args: variable arguments list
 * Return: printed characters count
 */
int handle_rot13string(va_list args)
{
	char *str;
	unsigned int i, j, count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == str[i])
			{
				_putchar(output[j]);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
