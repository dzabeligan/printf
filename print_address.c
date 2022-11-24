#include <stdlib.h>

#include "print_helpers.h"

/**
  * print_address_helper - Prints hex number
  * @n: int number to print
  * @len: length of bytes written
  *
  */
static void print_address_helper(unsigned long n, int *len)
{
	int last_digit = 0;
	char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
		'b', 'c', 'd', 'e', 'f' };

	last_digit = n & 0xF;
	if (n > 0xF)
		print_address_helper(n >> 4, len);

	*len += buffered_print(&hex[last_digit], 1);
}

/**
 * print_address - Print an address
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_address(va_list arg)
{
	int len = 0;
	void *str = va_arg(arg, void *);

	if (str == NULL)
		return (buffered_print("(nil)", 5));
	buffered_print("0x", 2);
	print_address_helper((unsigned long)str, &len);

	return (len);
}
