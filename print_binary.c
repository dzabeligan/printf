#include "print_helpers.h"

/**
  * print_binary_helper - Prints binary
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_binary_helper(unsigned int n, int *len)
{
	int last_digit = 0;
	char hex[] = { '0', '1' };

	last_digit = n & 0x1;
	if (n > 0x1)
		print_binary_helper(n >> 1, len);

	*len += buffered_print(&hex[last_digit], 1);
}

/**
 * print_binary - print binary
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_binary(specifier_t *spec, va_list arg)
{
	int len = 0;
	unsigned int num = va_arg(arg, unsigned int);
	(void) spec;

	print_binary_helper(num, &len);
	return (len);
}
