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

	if (str == NULL)
		return (buffered_print("(null)", 6));

	return (buffered_print(str, strlen(str)));
}
