#include <limits.h>
#include <string.h>
#include <unistd.h>

#include "print_helpers.h"

/**
 * buffered_print - puts constant format chars into buffer
 *
 * @str: string
 * @sLen: string length
 *
 * Return: number of printed
 */
int buffered_print(const char *str, unsigned int sLen)
{
	static int len;
	static char buffer[1024] = {'\0'};
	int writen = 0;
	int i = 0;

	if (str  == NULL && sLen == UINT_MAX)
	{
		writen = (write(1, buffer, len));
		len = 0;
		memset(buffer, 0, sizeof(buffer));
		return (writen);
	}
	while (str && (str + i) && sLen--)
	{
		buffer[len++] = *(str + i++);
		if (len == 1024)
		{
			writen = (write(1, buffer, len));
			len = 0;
			memset(buffer, 0, sizeof(buffer));
		}
	}

	return (writen);
}

/**
 * print_nchar - print spaces
 * @c: character
 * @len: number of spaces
 *
 *  Return: length of bytes written
 */
int print_nchar(char c, unsigned int len)
{
	int plen = 0;

	if (len == 0)
		return (plen);
	while (len--)
		plen += buffered_print(&c, 1);
	return (plen);
}

/**
 * print_space - print spaces
 * @len: number of spaces
 *
 *  Return: length of bytes written
 */
int print_space(unsigned int len)
{
	return (print_nchar(' ', len));
}

/**
 * num_len - length of number
 * @n: number
 * @updater: callback function
 *
 * Return: length of number
 */
unsigned int num_len(
	unsigned long int n, unsigned long int (*updater)(unsigned long int num))
{
	unsigned int num_width = 1;

	while (updater(n) > 0)
	{
		n = updater(n);
		num_width++;
	}
	return (num_width);
}
