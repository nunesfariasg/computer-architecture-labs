#include "instruction.h"

uint16_t instruction_encode(Opcode opcode, uint16_t operand) {
    return ((uint16_t)opcode << OPCODE_SHIFT)
           | (operand & OPERAND_MASK);
}

Opcode instruction_decode_opcode(uint16_t instruction) {
    return (Opcode)(instruction >> OPCODE_SHIFT);
}

uint16_t instruction_decode_operand(uint16_t instruction) {
    return instruction & OPERAND_MASK;
}