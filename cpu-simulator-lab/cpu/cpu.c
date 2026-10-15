#include "cpu.h"

#include <stddef.h>

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