#ifndef HALF_ADDER_H
#define HALF_ADDER_H

#include "logic_gat.h"

typedef struct {
    Bit sum;
    Bit carry;
} HalfAdderResult;

HalfAdderResult half_adder(Bit a, Bit b);

#endif