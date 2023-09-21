#include "main.h"
/**
 * _printf - custom printf function
 * @format: the output string format
 * @...: variable arguments to be printed
 * Description: prints all passed arguments in a specific format
 * just like the standard printf does.
 * Return: integer - the count of the printed characters (-1 for error)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format); /* initializes the va_list */

	if (!format) /* check if format is valid */
		return (-1);
	if (!format[0]) /* check if format is empty */
		return (0);
	while (*format) /* go through every format character */
	{
		if (*format == '%') /* placeholder is encountred */
		{
			format++; /* move pointer to the next character */

			if (*format == '%') /* other % encountered */
				count += _putchar('%');
			/* call the right handler function */
			else if (get_handler_func(*format) != NULL)
				count += get_handler_func(*format)(args);
			else /* none specified placeholder OR end of format string \0 */
			{
				/* in both cases print % */
				count += _putchar('%');

				if (*format != '\0') /* print the none specified placeholder */
					count += _putchar(*format);
				else /* exit loop if format string equal null termination */
					break;
			}
			format++;
		}
		else /* not a placeholder */
		{
			count += _putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
