#ifndef PRINT_HELPERS_H
#define PRINT_HELPERS_H

#include "main.h"
#include <stdarg.h>

/**
 * struct format_t - Format
 * @specifier: character
 * @print: print function for specifier
 *
 */
typedef struct format_t
{
	char specifier;
	int (*print)(va_list arg);
} format_t;

int print_char(va_list arg);
int print_percent(va_list arg);
int print_int(va_list arg);
int print_string(va_list arg);
int print_unsigned(va_list arg);
int print_address(va_list arg);
int print_hex(va_list arg);
int print_hex_cap(va_list arg);
int print_octal(va_list arg);

#endif
