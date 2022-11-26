#include "print_helpers.h"

#include "print_int_helpers.h"

/**
 * handle_width - handle width
 * @spec: specifier object
 * @num: num int
 * @nums: num short
 * @numl: num long
 * @width: width long
 *
 *  Return: length of bytes written
 */
int handle_width(specifier_t *spec, int num, short int nums,
	long int numl, unsigned int width)
{
	if (spec->width == 0 || width >= spec->width)
		return (0);
	return (print_space(
		(num < 0 && nums < 0 && numl < 0) || spec->flags & FLAG_SIGN
			? spec->width - width - 1 : spec->width - width));
}
