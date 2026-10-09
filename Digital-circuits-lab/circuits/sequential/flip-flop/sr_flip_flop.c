
#include "sr_flip_flop.h"

SRFlipFlopResult sr_flip_flop(
    Bit s,
    Bit r,
    Bit clk,
    Bit previous_clk,
    Bit previous_q
) {
    SRFlipFlopResult result;

    // Detect the rising edge of the clock.
    Bit rising_edge = (!previous_clk) & clk;

    // Update the stored state only on the rising edge.
    if (rising_edge) {
        if (s && !r) {
            previous_q = 1;
        } else if (!s && r) {
            previous_q = 0;
        }
        // S = 0, R = 0: keep the previous state.
        // S = 1, R = 1: invalid input combination.
    }

    result.q = previous_q;
    result.q_not = !previous_q;

    return result;
}
