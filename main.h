#ifndef MAIN_H
#define MAIN_H

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

int _printf(const char *format, ...);

#endif
