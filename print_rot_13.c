#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "print_helpers.h"

/**
 * print_rot_13 - Rotate character in string
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_rot_13(specifier_t *spec, va_list arg)
{
	int len = 0;
	char *str = va_arg(arg, char *);
	char c;
	(void) spec;

	if (str == NULL)
		return (buffered_print("(null)", 6));

	while (str && *str)
	{
		c = *str;

		if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
		{
			c += 13;
			len += buffered_print(&c, 1);
		}
		else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
		{
			c -= 13;
			len += buffered_print(&c, 1);
		}
		else
		{
			len += buffered_print(&c, 1);
		}
		str++;
	}

	return (len);
}
