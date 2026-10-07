#include "half_adder.h"

HalfAdderResult half_adder(Bit a, Bit b) {

    HalfAdderResult result;

    result.sum = gat_xor(a, b);
    result.carry = gat_and(a, b);

    return result;
}