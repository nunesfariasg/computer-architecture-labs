# Simple CPU Simulator

A simple CPU simulator written in C to explore the fundamental concepts of computer architecture and instruction execution.

This project implements a fictional processor capable of executing a small instruction set through the fetch-decode-execute cycle.

## Features

- **Registers:** Program Counter (PC), Instruction Register (IR), and Accumulator (ACC).
- **Memory:** Separate instruction and data memories, each containing 256 16-bit words.
- **Instruction Set:** Basic data transfer, arithmetic, branching, and control instructions.
- **Instruction Encoding:** 16-bit instructions divided into an opcode and an operand.
- **Execution Cycle:** Instruction fetching, decoding, and execution.
- **Execution Control:** Halt and fault states, with a configurable instruction step limit.

## Instruction Set

| Instruction | Description |
|---|---|
| `NOP` | Performs no operation. |
| `LOAD` | Loads a value from memory into the accumulator. |
| `STORE` | Stores the accumulator value in memory. |
| `ADD` | Adds a memory value to the accumulator. |
| `SUB` | Subtracts a memory value from the accumulator. |
| `JMP` | Jumps to a specified instruction address. |
| `JZ` | Jumps if the accumulator is zero. |
| `HALT` | Stops execution. |

## Architecture

The simulator is organized into three main components:

- **CPU:** Manages registers, instruction execution, and the fetch-decode-execute cycle.
- **Memory:** Stores instructions and data in separate arrays.
- **Instruction:** Defines the instruction opcodes and handles encoding and decoding.

The `main.c` file initializes the CPU, loads a sample program into memory, and executes it.

## Project Structure

```text
Simple-CPU-Simulator/
├── cpu/
│   ├── cpu.c
│   └── cpu.h
├── instruction/
│   ├── instruction.c
│   └── instruction.h
├── memory/
│   ├── memory.c
│   └── memory.h
├── main.c
└── CMakeLists.txt
```

## Requirements

- C compiler with C11 support
- CMake 3.16 or later

## Build and Run

Configure the project:

```bash
cmake -S . -B build
```

Build the executable:

```bash
cmake --build build
```

Run the simulator:

```bash
./build/simple_cpu_simulator
```

## Example Program

The sample program performs the following operations:

1. Loads the value at memory address `10` into the accumulator.
2. Adds the value at memory address `11`.
3. Stores the result at memory address `12`.
4. Halts execution.

With the initial values `memory[10] = 7` and `memory[11] = 5`, the expected result is:

```text
Simple CPU Simulator
--------------------
Program halted successfully.
Accumulator: 12
Memory[12]: 12
```

## Learning Objectives

- Understand the basic structure of a CPU.
- Explore the role of registers and memory.
- Understand instruction encoding and decoding.
- Implement a basic instruction set.
- Simulate the fetch-decode-execute cycle.
- Explore program flow through conditional and unconditional jumps.

## Limitations

This project is an educational simulation of a simplified processor. It does not model real hardware timing, clock signals, pipelining, interrupts, or a physical control unit.

## License

This project is intended for educational purposes.
