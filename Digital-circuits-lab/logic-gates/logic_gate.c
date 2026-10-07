#include "logic_gate.h"

Bit gat_and(Bit a, Bit b) {
    return a && b;
}

Bit gat_or(Bit a, Bit b) {
    return a || b;
}

Bit gat_not(Bit a) {
    return !a;
}

Bit gat_xor(Bit a, Bit b) {
    return (!a) != (!b);
}

Bit gat_nand(Bit a, Bit b) {
    return !(a && b);
}