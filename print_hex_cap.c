#include "print_helpers.h"

/**
  * print_hex_helper_cap - Prints hex number (cap)
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_hex_helper_cap(unsigned int n, int *len)
{
	int last_digit = 0;
	char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
		'B', 'C', 'D', 'E', 'F' };

	last_digit = n & 0xF;
	if (n > 0xF)
		print_hex_helper_cap(n >> 4, len);

	*len += buffered_print(&hex[last_digit], 1);
}

/**
  * print_short_hex_helper_cap - Prints hex number (cap)
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_short_hex_helper_cap(unsigned short int n, int *len)
{
	int last_digit = 0;
	char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
		'B', 'C', 'D', 'E', 'F' };

	last_digit = n & 0xF;
	if (n > 0xF)
		print_short_hex_helper_cap(n >> 4, len);

	*len += buffered_print(&hex[last_digit], 1);
}

/**
  * print_long_hex_helper_cap - Prints hex number (cap)
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_long_hex_helper_cap(unsigned long int n, int *len)
{
	int last_digit = 0;
	char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
		'B', 'C', 'D', 'E', 'F' };

	last_digit = n & 0xF;
	if (n > 0xF)
		print_long_hex_helper_cap(n >> 4, len);

	*len += buffered_print(&hex[last_digit], 1);
}

/**
 * updater - update number in num len function
 * @num: number
 *
 * Return: updated number
 */
static unsigned long int updater(unsigned long int num)
{
	return (num >> 4);
}

/**
 * print_hex_cap - print hex (capital letters)
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_hex_cap(specifier_t *spec, va_list arg)
{
	int len = 0;
	unsigned long int num = va_arg(arg, unsigned long int);
	unsigned int width = num_len(num, updater);

	if (!(spec->flags & FLAG_LEFT) && width < spec->width)
		len += print_nchar(spec->flags & FLAG_ZERO ? '0' : ' ',
			spec->width - width);

	if (spec->flags & FLAG_ALT && num)
		len += buffered_print("0X", 2);

	if (width < spec->precision)
		len += print_nchar('0', spec->precision - width);
	if (spec->flags & FLAG_PRECISION && spec->precision == 0 && num == 0)
		return (len);

	if (spec->flags & FLAG_LONG)
		print_long_hex_helper_cap(num, &len);
	else if (spec->flags & FLAG_SHORT)
		print_short_hex_helper_cap(num, &len);
	else
		print_hex_helper_cap(num, &len);
	if (width < spec->width && spec->flags & FLAG_LEFT)
		len += print_space(spec->width - width);
	return (len);
}
