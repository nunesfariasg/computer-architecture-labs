#include "cpu.h"

#include <stddef.h>

// Instance cpu
void cpu_init(CPU *cpu) {
    if (cpu == NULL) {
        return;
    }

    cpu->PC = 0;
    cpu->IR = 0;
    cpu->ACC = 0;
    cpu->halted = 0;

    memory_init(&cpu->memory);
}

// Fetch the next instruction from memory.
void cpu_fetch(CPU *cpu) {
    if (cpu == NULL || cpu->halted) {
        return;
    }

    cpu->IR = memory_read_instruction(
        &cpu->memory,
        cpu->PC
    );

    cpu->PC++;
}

// Decode the instruction stored in the IR.
int cpu_decode(const CPU *cpu, DecodedInstruction *decoded) {
    if (cpu == NULL || decoded == NULL) {
        return 0;
    }

    decoded->opcode = instruction_decode_opcode(cpu->IR);
    decoded->operand = instruction_decode_operand(cpu->IR);

    return 1;
}