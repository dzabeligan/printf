#include <limits.h>

#include "print_int_helpers.h"

#include "print_helpers.h"

/**
 * print_int_helper - Prints number
 * @spec: specifier object
 * @n: int number to print
 * @len: length of bytes written
 *
 */
static void print_int_helper(specifier_t *spec, int n, int *len)
{
	int last_digit = 0;
	int spill = 0;
	char c = 0;

	if (n < 0)
	{
		if (n <= INT_MIN)
			spill = 5;
		n = -(n + spill);
	}

	last_digit = n % 10;
	if (n >= 10)
		print_int_helper(spec, n / 10, len);

	c = (last_digit + spill) + '0';
	*len += buffered_print(&c, 1);
}

/**
 * print_short_int_helper - Prints number
 * @spec: specifier object
 * @n: int number to print
 * @len: length of bytes written
 *
 */
static void print_short_int_helper(specifier_t *spec, short int n, int *len)
{
	int last_digit = 0;
	int spill = 0;
	char c = 0;

	if (n < 0)
	{
		if (n <= SHRT_MIN)
			spill = 5;
		n = -(n + spill);
	}

	last_digit = n % 10;
	if (n >= 10)
		print_short_int_helper(spec, n / 10, len);

	c = (last_digit + spill) + '0';
	*len += buffered_print(&c, 1);
}

/**
 * print_long_int_helper - Prints number
 * @spec: specifier object
 * @n: int number to print
 * @len: length of bytes written
 *
 */
static void print_long_int_helper(specifier_t *spec, long int n, int *len)
{
	int last_digit = 0;
	int spill = 0;
	char c = 0;

	if (n < 0)
	{
		if (n <= LONG_MIN)
			spill = 5;
		n = -(n + spill);
	}

	last_digit = n % 10;
	if (n >= 10)
		print_long_int_helper(spec, n / 10, len);

	c = (last_digit + spill) + '0';
	*len += buffered_print(&c, 1);
}

/**
 * handle_print - handle print
 * @spec: specifier object
 * @num: num int
 * @nums: num short
 * @numl: num long
 *
 *  Return: length of bytes written
 */
int handle_print(
	specifier_t *spec, int num, short int nums, long int numl)
{
	int len = 0;

	if (spec->flags & FLAG_LONG)
		print_long_int_helper(spec, numl, &len);
	else if (spec->flags & FLAG_SHORT)
		print_short_int_helper(spec, nums, &len);
	else
		print_int_helper(spec, num, &len);
	return (len);
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
	int len = 0, num = 0;
	unsigned int num_width = 1;
	short int nums = 0;
	long int numl = 0;

	get_variables(spec, arg, &num, &nums, &numl, &num_width);
	if (spec->flags & FLAG_LEFT)
		return (handle_left_align(spec, num, nums, numl, num_width));
	len += handle_width(spec, num, nums, numl, num_width);
	len += handle_sign(spec, num, nums, numl, num_width);
	len += handle_precision(spec, num_width);
	if ((num != 0 && nums != 0 && numl != 0) || (spec->flags & FLAG_PRECISION
		&& spec->precision != 0) || !(spec->flags & FLAG_PRECISION))
		len += handle_print(spec, num, nums, numl);
	return (len);
}
