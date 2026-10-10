
#include "multiplexer.h"

Bit mux_2to1(Bit a, Bit b, Bit s) {

    // Invert the selection bit (s).
    // When s = 0, not_s = 1, enabling input a.
    Bit not_s = gate_not(s);

    // AND gate allows input a to pass when s = 0.
    // Otherwise, the output is 0.
    Bit a_selected = gate_and(a, not_s);

    // AND gate allows input b to pass when s = 1.
    // Otherwise, the output is 0.
    Bit b_selected = gate_and(b, s);

    return gate_or(a_selected, b_selected);
}