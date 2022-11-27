#include <string.h>

#include "print_helpers.h"

/**
 * print_string - Prints a string.
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_string(specifier_t *spec, va_list arg)
{
	char *str = va_arg(arg, char *);
	size_t width = 0;
	int len = 0;

	if (str == NULL)
		return (buffered_print("(null)", 6));

	width = strlen(str);

	if (!(spec->flags & FLAG_LEFT) && width < spec->width)
		len += print_space(spec->width - (unsigned int)width);
	if (spec->flags & FLAG_PRECISION && spec->precision < width)
		width = spec->precision;
	len += buffered_print(str, width);
	if (spec->flags & FLAG_LEFT && width < spec->width)
		len += print_space(spec->width - (unsigned int)width);
	return (len);
}
