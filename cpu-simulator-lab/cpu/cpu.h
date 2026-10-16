#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#include "../memory/memory.h"
#include "../instruction/instruction.h"

typedef struct {
    uint16_t PC;
    uint16_t IR;
    uint16_t ACC;

    int halted;

    Memory memory;
} CPU;

typedef struct {
    Opcode opcode;
    uint16_t operand;
} DecodedInstruction;

void cpu_init(CPU *cpu);
void cpu_fetch(CPU *cpu);
int cpu_decode(const CPU *cpu, DecodedInstruction *decoded);

#endif