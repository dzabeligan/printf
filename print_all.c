#include "print_helpers.h"
#include "main.h"

/**
 * print_all - Print all formats
 * @format: format string
 * @args: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_all(const char *format, va_list args)
{
	int format_t_len = 0;
	int j = 0;
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
		{'%', print_percent},
		{'r', print_reverse},
	};
	format_t_len = sizeof(f) / sizeof(f[0]);

	while (j < format_t_len && *format != f[j].specifier)
		j++;
	if (j < format_t_len)
	{
		return (f[j].print(args));
	}
	else if (*format)
	{
		buffered_print("%", 1);
		buffered_print(format, 1);
		return (2);
	}

	return (0);
}
