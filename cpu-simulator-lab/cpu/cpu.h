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
    int faulted;

    Memory memory;
} CPU;

typedef struct {
    Opcode opcode;
    uint16_t operand;
} DecodedInstruction;

void cpu_init(CPU *cpu);
int cpu_run(CPU *cpu, uint32_t max_steps);
int cpu_step(CPU *cpu);
void cpu_fetch(CPU *cpu);
int cpu_decode(const CPU *cpu, DecodedInstruction *decoded);
int cpu_execute(CPU *cpu, const DecodedInstruction *decoded);

#endif