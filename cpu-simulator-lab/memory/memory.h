#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define MEMORY_SIZE 256

typedef struct {
    uint16_t instructions[MEMORY_SIZE];
    uint16_t data[MEMORY_SIZE];
} Memory;

void memory_init(Memory *memory);

uint16_t memory_read_instruction(const Memory *memory, uint16_t address);
void memory_write_instruction(Memory *memory, uint16_t address, uint16_t instruction);

uint16_t memory_read_data(const Memory *memory, uint16_t address);
void memory_write_data(Memory *memory, uint16_t address, uint16_t value);

#endif