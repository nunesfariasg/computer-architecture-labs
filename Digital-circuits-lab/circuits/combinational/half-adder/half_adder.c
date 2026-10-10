#include "half_adder.h"

HalfAdderResult half_adder(Bit a, Bit b) {

    HalfAdderResult result;

    // It outputs 1 only when the inputs are different (0+1 or 1+0),
    // and 0 when they are the same (0+0 or 1+1).
    result.sum = gate_xor(a, b);

    // It outputs a 1 only when both inputs are 1 (1+1), indicating
    // a "carry" to the next binary position.
    result.carry = gate_and(a, b);

    return result;
}