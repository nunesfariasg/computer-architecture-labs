#ifndef FULL_ADDER_H
#define FULL_ADDER_H

#include "../../../logic-gates/logic_gate.h"

typedef struct {
    Bit sum;
    Bit carry;
} FullAdderResult;

FullAdderResult full_adder(Bit a, Bit b, Bit carry_in);

#endif