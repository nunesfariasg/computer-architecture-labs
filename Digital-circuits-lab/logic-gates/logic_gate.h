#ifndef LOGIC_H
#define LOGIC_H

typedef int Bit;

Bit gate_and(Bit a, Bit b);
Bit gate_or(Bit a, Bit b);
Bit gate_not(Bit a);
Bit gate_xor(Bit a, Bit b);
Bit gate_nand(Bit a, Bit b);

#endif