#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <stdint.h>

#define DIGITS_ARRAY_SIZE 64

int8_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, int8_t input_length);

#endif
