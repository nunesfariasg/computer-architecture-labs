# Digital Circuits Lab

A hands-on C project for studying digital logic and fundamental computer architecture concepts through the implementation of logic gates, combinational circuits, and sequential circuits.

## Overview

The **Digital Circuits Lab** explores how basic digital components can be combined to build more complex circuits. Each implementation focuses on understanding the underlying logic, circuit behavior, and relationships between inputs and outputs.

The project follows an incremental approach, starting with fundamental logic gates and progressing toward arithmetic circuits, data selection, decoding, and sequential logic.

## Implemented Circuits

### 1. Logic Gates

Implementation of fundamental Boolean logic operations:

- AND
- OR
- NOT
- XOR
- NAND

Truth tables are used to verify the behavior of each gate for all possible input combinations.

### 2. Combinational Circuits

Combinational circuits produce outputs determined by their current inputs.

- **Half Adder** — Adds two single-bit binary values, producing a sum and a carry.
- **Full Adder** — Adds two single-bit values and a carry-in, producing a sum and a carry-out.
- **Four-Bit Adder** — Adds two four-bit binary numbers using interconnected full adders.
- **2-to-1 Multiplexer (MUX)** — Selects one of two input signals according to a selection bit.
- **2-to-4 Decoder** — Decodes a two-bit input into four output lines, activating the output corresponding to the input combination.

### 3. Sequential Circuits

Sequential circuits introduce the concept of state, allowing a circuit to retain information beyond its current inputs.

- **SR Latch** — Demonstrates basic state storage using set and reset inputs.
- **SR Flip-Flop** — Explores state storage and the role of clock-controlled operation.

These circuits help establish the distinction between combinational logic and stateful digital systems.

## Technologies

- **Language:** C
- **Build System:** CMake
- **Development Environment:** CLion / compatible C development environments

## Project Structure

```text
Digital-circuits-lab/
├── logic-gates/
├── circuits/
│   ├── combinational/
│   │   ├── half-adder/
│   │   ├── full-adder/
│   │   ├── four-bit-adder/
│   │   ├── multiplexer/
│   │   └── decoder/
│   └── sequential/
│       ├── sr-latch/
│       └── sr-flip-flop/
├── main.c
├── CMakeLists.txt
└── README.md
```

*The directory tree illustrates the project's logical organization; filenames and paths may vary according to the current implementation.*

## Building and Running

### Requirements

- A C compiler, such as GCC or Clang
- CMake

### Build

From the project root directory:

```bash
cmake -S . -B build
cmake --build build
```

### Run

On Linux:

```bash
./build/Digital_circuits_lab
```

The executable path may vary depending on the CMake target and build configuration.

## Learning Objectives

This project is intended to strengthen understanding of:

- Boolean algebra and logic gate operations.
- Truth tables and binary representations.
- Combinational circuit design.
- Binary arithmetic and carry propagation.
- Multiplexing and binary decoding.
- State storage and sequential logic.
- The relationship between digital circuits and higher-level computer architecture.

## References

The project is inspired by concepts studied in *Structured Computer Organization* by Andrew S. Tanenbaum, particularly the foundations of digital logic and computer organization.

## Project Status

Educational project in progress. New circuits and experiments will be added as the study of digital logic and computer architecture advances.