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
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_reverse(va_list arg)
{
	char *str = va_arg(arg, char *);

	return (print_reverse_helper(str));
}
