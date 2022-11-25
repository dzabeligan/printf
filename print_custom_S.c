#include <stdlib.h>

#include "print_helpers.h"

/**
 * print_custom_S - Prints a string.
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_custom_S(specifier_t *spec, va_list arg)
{
	char *str = va_arg(arg, char *);
	int len = 0;
	char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
		'B', 'C', 'D', 'E', 'F' };
	(void) spec;

	if (str == NULL)
		return (buffered_print("(null)", 6));
	while (str && *str)
	{
		if (*str < 32 || *str > 126)
		{
			len += buffered_print("\\x", 2);
			len += buffered_print(&hex[(*str >> 4) & 0xF], 1);
			len += buffered_print(&hex[*str & 0xF], 1);
			str++;
			continue;
		}
		len += buffered_print(str, 1);
		str++;
	}

	return (len);
}
