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
    cpu->faulted = 0;

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

// Execute one fetch-decode-execute cycle.
int cpu_step(CPU *cpu) {
    if (cpu == NULL || cpu->halted || cpu->faulted) {
        return 0;
    }

    // Prevent instruction memory out-of-bounds access.
    if (cpu->PC >= MEMORY_SIZE) {
        cpu->faulted = 1;
        return 0;
    }

    cpu_fetch(cpu);

    DecodedInstruction decoded;

    if (!cpu_decode(cpu, &decoded)) {
        cpu->faulted = 1;
        return 0;
    }

    if (!cpu_execute(cpu, &decoded)) {
        cpu->faulted = 1;
        return 0;
    }

    return 1;
}

// Run the program until HALT, a fault, or the step limit.
int cpu_run(CPU *cpu, uint32_t max_steps) {
    if (cpu == NULL || cpu->faulted) {
        return 0;
    }

    uint32_t steps = 0;

    while (!cpu->halted && !cpu->faulted) {
        if (steps >= max_steps) {
            return 0;
        }

        if (!cpu_step(cpu)) {
            break;
        }

        steps++;
    }

    return cpu->halted && !cpu->faulted;
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

// Execute the decoded instruction.
int cpu_execute(CPU *cpu, const DecodedInstruction *decoded) {
    if (cpu == NULL || decoded == NULL || cpu->halted) {
        return 0;
    }

    uint16_t operand = decoded->operand;

    switch (decoded->opcode) {
        case OP_NOP:
            // Do nothing.
            break;

        case OP_LOAD:
            if (operand >= MEMORY_SIZE) {
                return 0;
            }

            cpu->ACC = memory_read_data(&cpu->memory, operand);
            break;

        case OP_STORE:
            if (operand >= MEMORY_SIZE) {
                return 0;
            }

            memory_write_data(&cpu->memory, operand, cpu->ACC);
            break;

        case OP_ADD:
            if (operand >= MEMORY_SIZE) {
                return 0;
            }

            cpu->ACC += memory_read_data(&cpu->memory, operand);
            break;

        case OP_SUB:
            if (operand >= MEMORY_SIZE) {
                return 0;
            }

            cpu->ACC -= memory_read_data(&cpu->memory, operand);
            break;

        case OP_JMP:
            if (operand >= MEMORY_SIZE) {
                return 0;
            }

            cpu->PC = operand;
            break;

        case OP_JZ:
            if (cpu->ACC == 0) {
                if (operand >= MEMORY_SIZE) {
                    return 0;
                }

                cpu->PC = operand;
            }
            break;

        case OP_HALT:
            cpu->halted = 1;
            break;

        default:
            // Reject unsupported opcodes.
            return 0;
    }

    return 1;
}
