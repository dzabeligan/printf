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
  * print_short_unsigned_helper - Prints unsigned int
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_short_unsigned_helper(unsigned short int n, int *len)
{
	int last_digit = 0;
	char c = 0;

	last_digit = n % 10;
	if (n >= 10)
		print_short_unsigned_helper(n / 10, len);

	c = last_digit + '0';
	*len += buffered_print(&c, 1);
}

/**
  * print_long_unsigned_helper - Prints unsigned int
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_long_unsigned_helper(unsigned long int n, int *len)
{
	int last_digit = 0;
	char c = 0;

	last_digit = n % 10;
	if (n >= 10)
		print_long_unsigned_helper(n / 10, len);

	c = last_digit + '0';
	*len += buffered_print(&c, 1);
}

/**
 * updater - update number in num len function
 * @num: number
 *
 * Return: updated number
 */
static unsigned long int updater(unsigned long int num)
{
	return (num / 10);
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
	unsigned long int num = va_arg(arg, unsigned long int);
	unsigned int width = num_len(num, updater);

	if (!(spec->flags & FLAG_LEFT))
	{
		if (width < spec->width)
			len += print_nchar(spec->flags & FLAG_ZERO ? '0' : ' ',
				spec->width - width);
		if (width < spec->precision)
			len += print_nchar('0', spec->precision - width);
		if (spec->flags & FLAG_PRECISION && spec->precision == 0 && num == 0)
			return (len);
	}

	if (spec->flags & FLAG_LONG)
		print_long_unsigned_helper(num, &len);
	else if (spec->flags & FLAG_SHORT)
		print_short_unsigned_helper(num, &len);
	else
		print_unsigned_helper(num, &len);
	if (width < spec->width && spec->flags & FLAG_LEFT)
		len += print_space(spec->width - width);
	return (len);
}
