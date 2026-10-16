#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#include "../memory/memory.h"

typedef struct {
    uint16_t PC;
    uint16_t IR;
    uint16_t ACC;

    int halted;

    Memory memory;
} CPU;

void cpu_init(CPU *cpu);
void cpu_fetch(CPU *cpu);

#endif