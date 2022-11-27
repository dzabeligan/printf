#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "print_helpers.h"

#include "main.h"

/**
 * print_all - Print all formats
 * @spec: specifier object
 * @args: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
static int print_all(specifier_t *spec, va_list args)
{
	int format_t_len = 0;
	int j = 0;
	int len = 0;
	format_t f[] = {
		{'c', print_char},
		{'i', print_int},
		{'d', print_int},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex_cap},
		{'p', print_address},
		{'s', print_string},
		{'S', print_custom_S},
		{'%', print_percent},
		{'r', print_reverse},
		{'R', print_rot_13},
		{'b', print_binary},
	};
	format_t_len = sizeof(f) / sizeof(f[0]);

	while (spec && j < format_t_len && spec->specifier != f[j].specifier)
		j++;
	if (j < format_t_len)
	{
		return (f[j].print(spec, args));
	}
	else if (spec && spec->specifier)
	{
		len += buffered_print("%", 1);
		len += buffered_print(&spec->specifier, 1);
	}

	return (len);
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
			int skip = 0;
			specifier_t spec;

			memset(&spec, 0, sizeof(spec));
			skip = get_specifier(&spec, format + 1, args);
			format += skip;
			if (spec.specifier == '\0')
				break;
			len += print_all(&spec, args);
			format++;
			continue;
		}
		if (*format == '%' && *(format + 1) == '\0')
			break;
		len += buffered_print(format++, 1);
	}
	len += buffered_print(NULL, UINT_MAX);

	va_end(args);

	return (len);
}
