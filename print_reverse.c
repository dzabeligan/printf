#include "print_helpers.h"
#include <string.h>

/**
 * print_reverse_helper - Helper function
 * @s: Pointer to char type (string)
 *
 *  Return: length of bytes written
 */
static int print_reverse_helper(char *s)
{
	int len = 0;

	if (s && *s != '\0')
	{
		len += (print_reverse_helper(s + 1) + buffered_print(s, 1));
	}

	return (len);
}

/**
 * print_reverse - Prints a string in reverse
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_reverse(specifier_t *spec, va_list arg)
{
	char *str = va_arg(arg, char *);
	(void) spec;

	return (print_reverse_helper(str));
}
