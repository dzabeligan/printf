#include "print_helpers.h"
#include <string.h>

/**
 * print_char - print char
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	return (buffered_print(&c, 1));
}

/**
 * print_percent - print percent
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_percent(va_list arg)
{
	(void)arg;

	return (buffered_print("%", 1));
}

/**
 * print_string - Prints a string.
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);

	return (buffered_print(str, strlen(str)));
}
