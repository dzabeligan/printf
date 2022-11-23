#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_all(const char *format, va_list args);
int buffered_print(const char *buffer, int sLen);

#endif
