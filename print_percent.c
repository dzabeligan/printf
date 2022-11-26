#include "print_helpers.h"

/**
 * print_percent - print percent
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_percent(specifier_t *spec, va_list arg)
{
	(void) arg;
	(void) spec;

	return (buffered_print("%", 1));
}
