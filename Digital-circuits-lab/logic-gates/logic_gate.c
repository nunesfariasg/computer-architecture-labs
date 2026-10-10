#include "logic_gate.h"

/// It operates by producing a high logic level (1) output only
/// when all its inputs are simultaneously at a high level (1).
Bit gate_and(Bit a, Bit b) {
    return a && b;
}

/// It works by returning a true output (1) if at least one of
/// its inputs is true (1).
Bit gate_or(Bit a, Bit b) {
    return a || b;
}

/// Its only function is to invert the received signal.
Bit gate_not(Bit a) {
    return !a;
}

/// produces a logic high (1) output only when its inputs have
/// different values.
Bit gate_xor(Bit a, Bit b) {
    return (!a) != (!b);
}

/// It functions like a standard AND gate with an inverted output.
Bit gate_nand(Bit a, Bit b) {
    return !(a && b);
}