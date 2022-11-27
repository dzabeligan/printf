#include "main.h"

/**
 * get_flag - Get the flag object
 * @spec: specifier object
 * @format: format string
 *
 * Return: length of characters checked
 */
static int get_flag(specifier_t *spec, const char *format)
{
	int len = 0;

	while (*format == '-' || *format == '+' || *format == ' '
	       || *format == '#' || *format == '0')
	{
		if (*format == '-')
			spec->flags |= FLAG_LEFT;
		else if (*format == '+')
			spec->flags |= FLAG_SIGN;
		else if (*format == ' ')
			spec->flags |= FLAG_BLANK;
		else if (*format == '#')
			spec->flags |= FLAG_ALT;
		else
			spec->flags |= FLAG_ZERO;
		len++;
		format++;
	}
	return (len);
}

/**
 * get_width - Get the width object
 * @spec: specifier object
 * @format: format string
 * @args: pointer to arguments to be printed
 *
 * Return: length of characters checked
 */
static int get_width(specifier_t *spec, const char *format, va_list args)
{
	int len = 0;

	spec->width = 0;
	if (*format == '*')
	{
		spec->width = va_arg(args, int);
		return (++len);
	}
	while (*format >= '0' && *format <= '9')
	{
		spec->width *= 10;
		spec->width += *format - '0';
		len++;
		format++;
	}
	return (len);
}

/**
 * get_precision - Get the precision object
 * @spec: specifier object
 * @format: format string
 * @args: pointer to arguments to be printed
 *
 * Return: length of characters checked
 */
static int get_precision(specifier_t *spec, const char *format, va_list args)
{
	int len = 0;

	spec->flags |= FLAG_PRECISION;
	if (*format == '*')
	{
		spec->precision = va_arg(args, int);
		return (++len);
	}
	while (*format >= '0' && *format <= '9')
	{
		spec->precision *= 10;
		spec->precision += *format - '0';
		len++;
		format++;
	}
	return (len);
}

/**
 * get_length - Get the length object
 * @spec: specifier object
 * @format: format string
 *
 * Return: length of characters checked
 */
static int get_length(specifier_t *spec, const char *format)
{
	int len = 0;

	while (*format == 'h')
	{
		len++;
		format++;
		spec->flags |= FLAG_SHORT;
	}
	while (*format == 'l')
	{
		len++;
		format++;
		spec->flags |= FLAG_LONG;
	}
	return (len);
}

/**
 * get_specifier - gets specifier information
 * @spec: specifier object
 * @format: format string to get info from
 * @args: pointer to arguments to be printed
 *
 * Return: specifier struct with info
 */
int get_specifier(specifier_t *spec, const char *format, va_list args)
{
	int len = 0;

	len += get_flag(spec, format + len);
	len += get_width(spec, format + len, args);

	if (*(format + len) == '.')
	{
		len++;
		len += get_precision(spec, format + len, args);
	}
	len += get_length(spec, format + len);
	spec->specifier = *(format + len);
	return (++len);
}
