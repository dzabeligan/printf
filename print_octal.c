#include "print_helpers.h"

/**
  * print_octal_helper - Prints octal
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_octal_helper(unsigned int n, int *len)
{
	int last_digit = 0;
	char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7' };

	last_digit = n & 0x7;
	if (n > 0x7)
		print_octal_helper(n >> 3, len);

	*len += buffered_print(&hex[last_digit], 1);
}

/**
 * print_octal - print octal
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_octal(specifier_t *spec, va_list arg)
{
	int len = 0;
	unsigned int num = va_arg(arg, unsigned int);

	if (spec->flags & FLAG_HEX && num)
		len += buffered_print("0", 1);
	print_octal_helper(num, &len);
	return (len);
}
