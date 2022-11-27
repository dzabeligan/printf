#ifndef PRINT_HELPERS_H
#define PRINT_HELPERS_H

#include "main.h"

int buffered_print(const char *buffer, unsigned int sLen);
int print_nchar(char c, unsigned int len);
int print_space(unsigned int len);
unsigned int num_len(
	unsigned long int n, unsigned long int (*updater)(unsigned long int num));

int get_specifier(specifier_t *spec, const char *format, va_list args);

int print_char(specifier_t *spec, va_list arg);
int print_percent(specifier_t *spec, va_list arg);
int print_int(specifier_t *spec, va_list arg);
int print_string(specifier_t *spec, va_list arg);
int print_unsigned(specifier_t *spec, va_list arg);
int print_address(specifier_t *spec, va_list arg);
int print_hex(specifier_t *spec, va_list arg);
int print_hex_cap(specifier_t *spec, va_list arg);
int print_octal(specifier_t *spec, va_list arg);
int print_reverse(specifier_t *spec, va_list arg);
int print_binary(specifier_t *spec, va_list arg);
int print_custom_S(specifier_t *spec, va_list arg);
int print_rot_13(specifier_t *spec, va_list arg);

#endif
