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
		{'s', print_string},
		{'%', print_percent},
	};
	format_t_len = sizeof(f) / sizeof(f[0]);

	while (j < format_t_len && *(format) != f[j].specifier)
		j++;
	if (j < format_t_len)
	{
		return (f[j].print(args));
	}
	else
	{
		_putchar('%');
		_putchar(*(format));
	}

	return (0);
}
