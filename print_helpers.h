#ifndef PRINT_HELPERS_H
#define PRINT_HELPERS_H

#include "main.h"

int buffered_print(const char *buffer, int sLen);

int print_char(va_list arg);
int print_percent(va_list arg);
int print_int(va_list arg);
int print_string(va_list arg);
int print_unsigned(va_list arg);
int print_address(va_list arg);
int print_hex(va_list arg);
int print_hex_cap(va_list arg);
int print_octal(va_list arg);
int print_reverse(va_list arg);
int print_binary(va_list arg);
int print_custom_S(va_list arg);
int print_rot_13(va_list arg);

#endif
