#ifndef PRINT_HELPERS_H
#define PRINT_HELPERS_H

#include "main.h"

int buffered_print(const char *buffer, int sLen);
int print_space(unsigned int len);

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
