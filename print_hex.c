#include "print_helpers.h"
#include <stdlib.h>

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
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_hex(va_list arg)
{
	int len = 0;
	unsigned int num = va_arg(arg, unsigned int);

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
 * @arg: pointer to arguments to be printed
 *
 *  Return: length of bytes written
 */
int print_hex_cap(va_list arg)
{
	int len = 0;
	unsigned int num = va_arg(arg, unsigned int);

	print_hex_helper_cap(num, &len);
	return (len);
}

/**
 * print_custom_S - Prints a string.
 * @arg: pointer to arguments to be printed
 *
 * Return: length of bytes written
 */
int print_custom_S(va_list arg)
{
	char *str = va_arg(arg, char *);
	int len = 0;
	char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
		'B', 'C', 'D', 'E', 'F' };

	if (str == NULL)
		return (buffered_print("(null)", 6));
	while (str && *str)
	{
		if (*str < 32 || *str > 126)
		{
			len += buffered_print("\\x", 2);
			len += buffered_print(&hex[(*str >> 4) & 0xF], 1);
			len += buffered_print(&hex[*str & 0xF], 1);
			str++;
			continue;
		}
		len += buffered_print(str, 1);
		str++;
	}

	return (len);
}
