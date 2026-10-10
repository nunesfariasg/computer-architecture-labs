#ifndef HALF_ADDER_H
#define HALF_ADDER_H

#include "../../../logic-gates/logic_gate.h"

typedef struct {
    Bit sum;
    Bit carry;
} HalfAdderResult;

HalfAdderResult half_adder(Bit a, Bit b);

#endif