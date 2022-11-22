#include "print_helpers.h"

#include <limits.h>

/**
  * print_unsigned_helper - Prints unsigned int using `_putchar`
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_unsigned_helper(unsigned int n, int *len)
{
	int last_digit = 0;

	last_digit = n % 10;
	if (n >= 10)
		print_unsigned_helper(n / 10, len);

	(*len)++;
	_putchar(last_digit + '0');
}

/**
 * print_unsigned - print unsigned int
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_unsigned(va_list arg)
{
	int len = 0;
	unsigned int num = va_arg(arg, unsigned int);

	print_unsigned_helper(num, &len);
	return (len);
}

/**
  * print_int_helper - Prints number using `_putchar`
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_int_helper(int n, int *len)
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
		print_int_helper(n / 10, len);

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

	print_int_helper(num, &len);
	return (len);
}
