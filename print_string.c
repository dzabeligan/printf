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
	(void) spec;

	if (str == NULL)
		return (buffered_print("(null)", 6));

	return (buffered_print(str, strlen(str)));
}
