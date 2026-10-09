#ifndef FOUR_BIT_ADDER_H
#define FOUR_BIT_ADDER_H

#include "../full-adder/full_adder.h"

typedef struct {
    Bit sum[4];
    Bit carry_out;
} FourBitAdderResult;

FourBitAdderResult four_bit_adder(
    const Bit a[4],
    const Bit b[4],
    Bit carry_in
);

#endif