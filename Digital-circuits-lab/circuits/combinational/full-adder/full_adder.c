#include "full_adder.h"
#include "../half-adder/half_adder.h"

FullAdderResult full_adder(Bit a, Bit b, Bit carry_in) {

    FullAdderResult result;

    // First half adder sums the two input bits (a and b).
    // It generates an intermediate sum and a partial carry.
    HalfAdderResult first = half_adder(a, b);

    // Second half adder takes the intermediate sum from the first step
    // and adds it to the incoming carry bit (carry_in).
    HalfAdderResult second = half_adder(first.sum, carry_in);

    // The final sum is the output sum from the second half adder.
    result.sum = second.sum;

    // It outputs a carry if either the first addition (a + b) generated a carry,
    // OR the second addition (intermediate sum + carry_in) generated a carry.
    result.carry = gate_or(first.carry, second.carry);

    return result;
}