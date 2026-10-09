#include "four_bit_adder.h"

FourBitAdderResult four_bit_adder(
    const Bit a[4],
    const Bit b[4],
    Bit carry_in
) {
    FourBitAdderResult result;

    Bit carry = carry_in;

    for (int i = 0; i < 4; i++) {
        FullAdderResult current = full_adder(
            a[i],
            b[i],
            carry
        );

        result.sum[i] = current.sum;
        carry = current.carry;
    }

    result.carry_out = carry;

    return result;
}