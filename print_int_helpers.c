#include "print_helpers.h"

#include "print_int_helpers.h"

#define num_len(n, num_width)                                                 \
	do {                                                                       \
		if ((n) < 0)                                                           \
			(n) = -(n + 5);                                                    \
		while ((n) / 10 > 0)                                                   \
		{                                                                      \
			(n) /= 10;                                                         \
			(num_width)++;                                                     \
		}                                                                      \
	} while ((n) / 10 > 0)

/**
 * handle_width - handle width
 * @spec: specifier object
 * @num: num int
 * @nums: num short
 * @numl: num long
 * @width: width
 *
 *  Return: length of bytes written
 */
int handle_width(specifier_t *spec, int num, short int nums,
	long int numl, unsigned int width)
{
	int len = 0;

	if (spec->flags & FLAG_ZERO)
		len += handle_sign(spec, num, nums, numl, width);
	if (spec->width == 0 || width >= spec->width)
		return (0);
	return (len + print_nchar(spec->flags & FLAG_ZERO ? '0' : ' ',
		(num < 0 && nums < 0 && numl < 0) || spec->flags & FLAG_SIGN
			? spec->width - width - 1 : spec->width - width));
}

/**
 * handle_precision - handle precision
 * @spec: specifier object
 * @width: width
 *
 *  Return: length of bytes written
 */
int handle_precision(specifier_t *spec, unsigned int width)
{
	if (spec->precision == 0 || width >= spec->precision)
		return (0);
	return (print_nchar('0', spec->precision - width));
}

/**
 * handle_sign - handle sign
 * @spec: specifier object
 * @num: num int
 * @nums: num short
 * @numl: num long
 * @width: width
 *
 *  Return: length of bytes written
 */
int handle_sign(specifier_t *spec, int num, short int nums, long int numl,
	unsigned int width)
{
	int len = 0;

	if (spec->flags & FLAG_SIGN && (num >= 0 || nums >= 0 || numl >= 0))
		len += buffered_print("+", 1);
	else if (spec->flags & FLAG_SPACE && (width >= spec->width) &&
		(num >= 0 || nums >= 0 || numl >= 0))
		len += buffered_print(" ", 1);
	else if ((spec->precision || spec->flags & FLAG_ZERO) &&
		(num < 0 && nums < 0 && numl < 0))
		len += buffered_print("-", 1);

	return (len);
}

/**
 * get_variables - Get the variables object
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 * @num: num int
 * @nums: num short
 * @numl: num long
 * @num_width: width
 *
 */
void get_variables(specifier_t *spec, va_list arg, int *num, short int *nums,
	long int *numl, unsigned int *num_width)
{
	if (spec->flags & FLAG_LONG)
	{
		long int num_copy;

		*numl = va_arg(arg, long int);
		num_copy = *numl;
		(*num)--;
		(*nums)--;
		num_len(num_copy, *num_width);
	}
	else if (spec->flags & FLAG_SHORT)
	{
		short int num_copy;

		*nums = va_arg(arg, int);
		num_copy = *nums;
		(*num)--;
		(*numl)--;
		num_len(num_copy, *num_width);
	}
	else
	{
		int num_copy;

		*num = va_arg(arg, int);
		num_copy = *num;
		(*numl)--;
		(*nums)--;
		num_len(num_copy, *num_width);
	}
}
