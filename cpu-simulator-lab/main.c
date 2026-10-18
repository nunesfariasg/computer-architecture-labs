#include <stdio.h>

#include "cpu/cpu.h"

int main(void) {
    CPU cpu;

    cpu_init(&cpu);

    memory_write_data(&cpu.memory, 10, 7);
    memory_write_data(&cpu.memory, 11, 5);

    memory_write_instruction(
        &cpu.memory, 0, instruction_encode(OP_LOAD, 10)
    );

    memory_write_instruction(
        &cpu.memory, 1, instruction_encode(OP_ADD, 11)
    );

    memory_write_instruction(
        &cpu.memory, 2, instruction_encode(OP_STORE, 12)
    );

    memory_write_instruction(
        &cpu.memory, 3, instruction_encode(OP_HALT, 0)
    );

    printf("Simple CPU Simulator\n");
    printf("--------------------\n");

    if (!cpu_run(&cpu, 100)) {
        printf("Execution failed or step limit reached.\n");
        printf("PC: %u | IR: 0x%04X | ACC: %u\n",
               cpu.PC, cpu.IR, cpu.ACC);
        return 1;
    }

    printf("Program halted successfully.\n");
    printf("Accumulator: %u\n", cpu.ACC);
    printf("Memory[12]: %u\n",
           memory_read_data(&cpu.memory, 12));

    return 0;
}