#include "print_helpers.h"
#include <string.h>
#include <stdlib.h>

/**
 * print_rot_13 - Rotate character in string
 * @str: string
 *
 * Return: length of bytes written
 */
int print_rot_13(va_list arg)
{
	char *str_copy = NULL;
	int len = 0;
	const char arr[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char replacement[] =
	"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(arg, char *);

	if (str == NULL)
		return (buffered_print("(null)", 6));

	str_copy = (char *)malloc(strlen(str) + 1);
	if (str_copy == NULL)
		return 0;
	while (str[len])
	{
		int i = 0;

		for (i = 0; arr[i] != '\0'; i++)
		{
			if (str[len] == arr[i])
			{
				str_copy[len] = replacement[i];
				break;
			}
			else
			{
				str_copy[len] = str[len];
			}
		}
		len++;
	}
	str_copy[len] = '\0';
	len = buffered_print(str_copy, len);
	free(str_copy);
	return (len);
}
