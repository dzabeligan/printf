#include "print_helpers.h"

/**
 * print_char - print char
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_char(specifier_t *spec, va_list arg)
{
	char c = va_arg(arg, int);
	int len = 0;

	if (!(spec->flags & FLAG_LEFT) && spec->width)
		len += print_space(spec->width - 1);
	len += buffered_print(&c, 1);
	if (spec->flags & FLAG_LEFT && spec->width)
		len += print_space(spec->width - 1);
	return (len);
}
