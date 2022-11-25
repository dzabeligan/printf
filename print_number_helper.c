#include <limits.h>

#include "print_helpers.h"

/**
  * print_unsigned_helper - Prints unsigned int
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_unsigned_helper(unsigned int n, int *len)
{
	int last_digit = 0;
	char c = 0;

	last_digit = n % 10;
	if (n >= 10)
		print_unsigned_helper(n / 10, len);

	c = last_digit + '0';
	*len += buffered_print(&c, 1);
}

/**
 * print_unsigned - print unsigned int
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_unsigned(specifier_t *spec, va_list arg)
{
	int len = 0;
	unsigned int num = va_arg(arg, unsigned int);
	(void) spec;

	print_unsigned_helper(num, &len);
	return (len);
}

/**
  * print_int_helper - Prints number
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_int_helper(int n, int *len)
{
	int last_digit = 0;
	int spill = 0;
	char c = 0;

	if (n < 0)
	{
		*len += buffered_print("-", 1);
		if (n <= INT_MIN)
			spill = 5;
		n = -(n + spill);
	}

	last_digit = n % 10;
	if (n >= 10)
		print_int_helper(n / 10, len);

	c = (last_digit + spill) + '0';
	*len += buffered_print(&c, 1);
}

/**
 * print_int - print int
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_int(specifier_t *spec, va_list arg)
{
	int len = 0;
	int num = va_arg(arg, int);

	if (spec->flags & FLAG_SIGN && num >= 0)
		len += buffered_print("+", 1);
	else if (spec->flags & FLAG_SPACE && num >= 0)
		len += buffered_print(" ", 1);
	print_int_helper(num, &len);
	return (len);
}
