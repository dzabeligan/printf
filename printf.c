#include "main.h"

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

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			len += print_all(++format, args);
			format++;
		}
		len += _putchar(*format++);
	}
	va_end(args);

	return (len);
}
