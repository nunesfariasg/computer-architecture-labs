#include "memory.h"

#include <stddef.h>

void memory_init(Memory *memory) {
    if (memory == NULL) {
        return;
    }

    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory->instructions[i] = 0;
        memory->data[i] = 0;
    }
}

uint16_t memory_read_instruction(const Memory *memory, uint16_t address) {
    if (memory == NULL || address >= MEMORY_SIZE) {
        return 0;
    }

    return memory->instructions[address];
}

void memory_write_instruction(Memory *memory, uint16_t address, uint16_t instruction) {
    if (memory == NULL || address >= MEMORY_SIZE) {
        return;
    }

    memory->instructions[address] = instruction;
}

uint16_t memory_read_data(const Memory *memory, uint16_t address) {
    if (memory == NULL || address >= MEMORY_SIZE) {
        return 0;
    }

    return memory->data[address];
}

void memory_write_data(Memory *memory, uint16_t address, uint16_t value) {
    if (memory == NULL || address >= MEMORY_SIZE) {
        return;
    }

    memory->data[address] = value;
}