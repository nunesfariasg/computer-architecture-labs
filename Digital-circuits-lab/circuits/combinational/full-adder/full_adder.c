#include "full_adder.h"
#include "../half-adder/half_adder.h"

FullAdderResult full_adder(Bit a, Bit b, Bit carry_in) {

    FullAdderResult result;

    HalfAdderResult first = half_adder(a, b);
    HalfAdderResult second = half_adder(first.sum, carry_in);

    result.sum = second.sum;
    result.carry = gat_or(first.carry, second.carry);

    return result;
}