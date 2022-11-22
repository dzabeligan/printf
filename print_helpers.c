#include "print_helpers.h"

#include <string.h>
#include <unistd.h>

/**
 * print_char - print char
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	return (_putchar(c));
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

	return (_putchar('%'));
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

	return (write(1, str, strlen(str)));
}
