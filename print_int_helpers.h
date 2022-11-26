#ifndef PRINT_INT_HELPERS_H
#define PRINT_INT_HELPERS_H

#include "main.h"

int handle_width(specifier_t *spec, int num, short int nums,
	long int numl, unsigned int width);
int handle_precision(specifier_t *spec, unsigned int width);
int handle_sign(
	specifier_t *spec, int num, short int nums, long int numl);
void get_variables(specifier_t *spec, va_list arg, int *num, short int *nums,
	long int *numl, unsigned int *num_width);

#endif
