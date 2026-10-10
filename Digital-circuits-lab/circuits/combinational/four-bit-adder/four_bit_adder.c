#include "four_bit_adder.h"

FourBitAdderResult four_bit_adder(
    const Bit a[4],
    const Bit b[4],
    Bit carry_in
) {
    FourBitAdderResult result;

    // Initialize the carry chain with the initial
    // incoming carry bit.
    Bit carry = carry_in;

    // Loop through each bit position from least
    // significant to most significant (0 to 3).
    for (int i = 0; i < 4; i++) {
        // Sum the current pair of bits along with the
        // carry generated from the previous bit addition.
        FullAdderResult current = full_adder(
            a[i],
            b[i],
            carry
        );

        // Store the resulting sum bit into the current
        // position of the output array.
        result.sum[i] = current.sum;

        // Update the carry variable to be passed into
        // the next bit addition.
        carry = current.carry;
    }

    // The final carry out from the last addition becomes
    // the overall carry out of the 4-bit adder.
    result.carry_out = carry;

    return result;
}