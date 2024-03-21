#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a character
 * @list: list of arguments
 * Return: Number of characters printed
 */
int print_char(va_list list)
{
	return (_putchar(va_arg(list, int)));
}

/**
 * print_string - Prints a string
 * @list: list of arguments
 * Return: Number of characters printed
 */
int print_string(va_list list)
{
	int count = 0;
	char *str = va_arg(list, char *);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str++);
		count++;
	}
	return (count);
}

/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: Number of characters printed
 */
int print_percent(__attribute__((unused)) va_list list)
{
	return (_putchar('%'));
}

/**
 * print_int - Prints an integer
 * @list: list of arguments
 * Return: Number of characters printed
 */
int print_int(va_list list)
{
	int num = va_arg(list, int);
	int count = 0;
	unsigned int num_abs;
	unsigned int num_temp;
	int base = 1;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num_abs = -num;
	}
	else
	{
		num_abs = num;
	}

	num_temp = num_abs;
	while (num_temp > 9)
	{
		num_temp /= 10;
		base *= 10;
	}

	while (base > 0)
	{
		_putchar(((num_abs / base) % 10) + '0');
		count++;
		base /= 10;
	}
	return (count);
}
