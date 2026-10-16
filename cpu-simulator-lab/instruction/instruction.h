#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>

#define OPCODE_SHIFT 12
#define OPERAND_MASK 0x0FFF

typedef enum {
    OP_NOP   = 0x0,
    OP_LOAD  = 0x1,
    OP_STORE = 0x2,
    OP_ADD   = 0x3,
    OP_SUB   = 0x4,
    OP_JMP   = 0x5,
    OP_JZ    = 0x6,
    OP_HALT  = 0xF
} Opcode;

uint16_t instruction_encode(Opcode opcode, uint16_t operand);

Opcode instruction_decode_opcode(uint16_t instruction);

uint16_t instruction_decode_operand(uint16_t instruction);

#endif