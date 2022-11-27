#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * enum flag_t - flag types
 * @FLAG_SIGN: sign
 * @FLAG_BLANK: space
 * @FLAG_ALT: hex
 * @FLAG_LEFT: left
 * @FLAG_ZERO: zero
 * @FLAG_LONG: length
 * @FLAG_SHORT: short
 * @FLAG_PRECISION: precision
 *
 */
typedef enum flag_t
{
	FLAG_SIGN = 1,
	FLAG_BLANK = 1 << 1,
	FLAG_ALT = 1 << 2,
	FLAG_LEFT = 1 << 3,
	FLAG_ZERO = 1 << 4,
	FLAG_LONG = 1 << 5,
	FLAG_SHORT = 1 << 6,
	FLAG_PRECISION = 1 << 7
} flag_t;

/**
 * struct specifier_t - contains specifiers for printf
 *
 * @width: width of field to print
 * @precision: precision of field to print
 * @flags: flags set
 * @specifier: the data type to print, c, s, d, x, etc.
 */
typedef struct specifier_t
{
	unsigned int width;
	unsigned int precision;
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
