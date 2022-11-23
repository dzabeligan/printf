#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

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
 * _printf - Print all formats
 * @format: format string
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%' && *(format + 1))
		{
			len += print_all(++format, args);
			format++;
			continue;
		}
		len += buffered_print(format++, 1);
	}
	len += buffered_print(NULL, -1);

	va_end(args);

	return (len);
}
