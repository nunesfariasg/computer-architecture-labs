
#include "multiplexer.h"

Bit mux_2to1(Bit a, Bit b, Bit s) {
    Bit not_s = gate_not(s);

    Bit a_selected = gate_and(a, not_s);
    Bit b_selected = gate_and(b, s);

    return gate_or(a_selected, b_selected);
}