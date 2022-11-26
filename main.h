#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * enum flag_t - flag types
 * @FLAG_SIGN: sign
 * @FLAG_SPACE: space
 * @FLAG_HEX: hex
 * @FLAG_LEFT: left
 * @FLAG_ZERO: zero
 * @FLAG_LENGTH: length
 * @FLAG_SHORT: short
 *
 */
typedef enum flag_t
{
	FLAG_SIGN = 1,
	FLAG_SPACE = 1 << 1,
	FLAG_HEX = 1 << 2,
	FLAG_LEFT = 1 << 3,
	FLAG_ZERO = 1 << 4,
	FLAG_LENGTH = 1 << 5,
	FLAG_SHORT = 1 << 6
} flag_t;

/**
 * struct specifier_t - contains specifiers for printf
 *
 * @width: width of field to print
 * @precision: precision of field to print
 * @precisionflag: tells whether precision is set
 * @flags: flags set
 * @specifier: the data type to print, c, s, d, x, etc.
 */
typedef struct specifier_t
{
	unsigned int width;
	unsigned int precision;
	char precisionflag;
	char specifier;
	unsigned int flags;
} specifier_t;

/**
 * struct format_t - Format
 * @specifier: character
 * @print: print function for specifier
 *
 */
typedef struct format_t
{
	char specifier;
	int (*print)(specifier_t *spec, va_list arg);
} format_t;

int _printf(const char *format, ...);

#endif
