#include <stdlib.h>

#include "print_helpers.h"

/**
  * print_hex_helper - Prints hex number
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_hex_helper(unsigned int n, int *len)
{
	int last_digit = 0;
	char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
		'b', 'c', 'd', 'e', 'f' };

	last_digit = n & 0xF;
	if (n > 0xF)
		print_hex_helper(n >> 4, len);

	*len += buffered_print(&hex[last_digit], 1);
}

/**
 * print_hex - print hex
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_hex(specifier_t *spec, va_list arg)
{
	int len = 0;
	unsigned int num = va_arg(arg, unsigned int);

	if (spec->flags & FLAG_HEX && num)
		len += buffered_print("0x", 2);
	print_hex_helper(num, &len);
	return (len);
}

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
 * print_hex_cap - print hex (capital letters)
 * @spec: specifier object
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_hex_cap(specifier_t *spec, va_list arg)
{
	int len = 0;
	unsigned int num = va_arg(arg, unsigned int);

	if (spec->flags & FLAG_HEX && num)
		len += buffered_print("0X", 2);
	print_hex_helper_cap(num, &len);
	return (len);
}
