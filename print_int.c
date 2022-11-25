#include <limits.h>

#include "print_helpers.h"

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
  * print_short_int_helper - Prints number
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_short_int_helper(short int n, int *len)
{
	int last_digit = 0;
	int spill = 0;
	char c = 0;

	if (n < 0)
	{
		*len += buffered_print("-", 1);
		if (n <= SHRT_MIN)
			spill = 5;
		n = -(n + spill);
	}

	last_digit = n % 10;
	if (n >= 10)
		print_short_int_helper(n / 10, len);

	c = (last_digit + spill) + '0';
	*len += buffered_print(&c, 1);
}

/**
  * print_long_int_helper - Prints number
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_long_int_helper(long int n, int *len)
{
	int last_digit = 0;
	int spill = 0;
	char c = 0;

	if (n < 0)
	{
		*len += buffered_print("-", 1);
		if (n <= LONG_MIN)
			spill = 5;
		n = -(n + spill);
	}

	last_digit = n % 10;
	if (n >= 10)
		print_long_int_helper(n / 10, len);

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
	int num = 0;
	short int nums = 0;
	long int numl = 0;

	if (spec->flags & FLAG_LENGTH)
	{
		numl = va_arg(arg, long int);
		num--;
		nums--;
	}
	else if (spec->flags & FLAG_SHORT)
	{
		nums = va_arg(arg, int);
		num--;
		numl--;
	}
	else
	{
		num = va_arg(arg, int);
		numl--;
		nums--;
	}

	if (spec->flags & FLAG_SIGN && (num >= 0 || nums >= 0 || numl >= 0))
		len += buffered_print("+", 1);
	else if (spec->flags & FLAG_SPACE && (num >= 0 || nums >= 0 || numl >= 0))
		len += buffered_print(" ", 1);

	if (spec->flags & FLAG_LENGTH)
		print_long_int_helper(numl, &len);
	else if (spec->flags & FLAG_SHORT)
		print_short_int_helper(nums, &len);
	else
		print_int_helper((int)num, &len);

	return (len);
}
