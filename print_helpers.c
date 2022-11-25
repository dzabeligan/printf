#include <string.h>
#include <unistd.h>

#include "print_helpers.h"

/**
 * buffered_print - puts constant format chars into buffer
 *
 * @str: string
 * @sLen: string length
 *
 * Return: number of printed
 */
int buffered_print(const char *str, int sLen)
{
	static int len;
	static char buffer[1024] = {'\0'};
	int writen = 0;
	int i = 0;

	if (sLen == -1)
	{
		writen = (write(1, buffer, len));
		len = 0;
		memset(buffer, 0, sizeof(buffer));
	}
	while (str && (str + i) && sLen--)
	{
		buffer[len++] = *(str + i++);
		if (len == 1024)
		{
			writen = (write(1, buffer, len));
			len = 0;
			memset(buffer, 0, sizeof(buffer));
		}
	}

	return (writen);
}

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
	(void) spec;

	return (buffered_print(&c, 1));
}

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
