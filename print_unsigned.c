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
 * print_unsigned - print unsigned int
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_unsigned(specifier_t *spec, va_list arg)
{
	int len = 0;
	unsigned long int numl = va_arg(arg, unsigned long int);

	if (spec->flags & FLAG_LENGTH)
		print_long_unsigned_helper(numl, &len);
	else if (spec->flags & FLAG_SHORT)
		print_short_unsigned_helper(numl, &len);
	else
		print_unsigned_helper(numl, &len);
	return (len);
}
