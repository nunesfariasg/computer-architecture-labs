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