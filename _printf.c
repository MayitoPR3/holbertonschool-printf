#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_format - Handles formatting for specific specifiers.
 * @specifier: The format specifier to handle.
 * @args: The list of arguments passed to the function.
 *
 * Return: The number of characters printed by the handling function,
 * or 2 if an unsupported specifier is encountered.
 */
int handle_format(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'c': return (print_char(args));
		case 's': return (print_string(args));
		case '%': return (print_percent(args));
		case 'd':
		case 'i': return (print_int(args));
		default:
				  _putchar('%');
				  _putchar(specifier);
				return (2);
	}
}

/**
 * _printf - produces output according to a format
 *@format: character string composed of zero or more directives
 *
 *Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += handle_format(format[i + 1], args);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			_putchar('%');
			count++;
			break;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
