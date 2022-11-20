#include "main.h"
#include "print_helpers.h"

#include <limits.h>
#include <string.h>
#include <unistd.h>

/**
 * print_char - print char
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	return (_putchar(c));
}

/**
 * print_percent - print percent
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_percent(va_list arg)
{
	(void)arg;

	return (_putchar('%'));
}

/**
  * print_number - Prints number using `_putchar`
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_number(int n, int *len)
{
	int last_digit = 0;
	int spill = 0;

	if (n < 0)
	{
		_putchar('-');
		(*len)++;
		if (n <= INT_MIN)
			spill = 5;
		n = -(n + spill);
	}

	last_digit = n % 10;
	if (n >= 10)
		print_number(n / 10, len);

	(*len)++;
	_putchar((last_digit + spill) + '0');
}

/**
 * print_int - print int
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_int(va_list arg)
{
	int len = 0;
	int num = va_arg(arg, int);

	print_number(num, &len);
	return (len);
}

/**
 * print_string - Prints a string.
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);

	return (write(1, str, strlen(str)));
}
