#ifndef PRINT_INT_HELPERS_H
#define PRINT_INT_HELPERS_H

#include "main.h"

int handle_print(
	specifier_t *spec, int num, short int nums, long int numl);
int handle_width(specifier_t *spec, int num, short int nums,
	long int numl, unsigned int width);
int handle_precision(specifier_t *spec, unsigned int width);
int handle_sign(specifier_t *spec, int num, short int nums, long int numl,
	unsigned int width);
int handle_left_align(specifier_t *spec, int num, short int nums, long int numl,
	unsigned int width);
void get_variables(specifier_t *spec, va_list arg, int *num, short int *nums,
	long int *numl, unsigned int *num_width);

#endif
