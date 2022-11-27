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
	if (spec->width == 0 || width >= (spec->width))
		return (0);
	width = spec->width - width;
	if (spec->precision >= width)
		width = 0;
	if (((num < 0 && nums < 0 && numl < 0) || spec->flags & FLAG_SIGN)
		&& width != 0)
		width--;
	if (spec->flags & FLAG_PRECISION && (num == 0 || nums == 0 || numl == 0)
		&& spec->precision == 0)
		width = spec->width;
	return (print_nchar(spec->flags & FLAG_ZERO ? '0' : ' ', width));
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
	if (num < 0 && nums < 0 && numl < 0)
		return (print_nchar('-', 1));
	if (spec->flags & FLAG_SIGN && (num >= 0 || nums >= 0 || numl >= 0))
		return (print_nchar('+', 1));
	if (spec->flags & FLAG_BLANK && spec->width < width)
		return (print_space(1));
	return (0);
}

/**
 * handle_left_align - handle left align
 * @spec: specifier object
 * @num: num int
 * @nums: num short
 * @numl: num long
 * @width: width
 *
 *  Return: length of bytes written
 */
int handle_left_align(specifier_t *spec, int num, short int nums, long int numl,
	unsigned int width)
{
	int len = 0;

	if (spec->flags & FLAG_BLANK && spec->width > width && (num >= 0 || nums >= 0 || numl >= 0))
			len += print_space(1);
	len += handle_sign(spec, num, nums, numl, width);
	if (spec->flags & FLAG_PRECISION)
	{
		if (spec->precision)
			spec->width = 0;
		len += handle_precision(spec, width);
	}
	if ((spec->flags & FLAG_SIGN || spec->flags & FLAG_BLANK) &&
		(num >= 0 || nums >= 0 || numl >= 0))
		width++;
	len += handle_print(spec, num, nums, numl);
	spec->flags = 0;
	len += handle_width(spec, num, nums, numl, width);
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
