cmake_minimum_required(VERSION 3.10)
project(Digital_circuits_lab C)

set(CMAKE_C_STANDARD 99)

add_executable(Digital_circuits_lab
        logic-gates/logic_gate.c
        main.c
        logic-gates/logic_gate.h
        logic-gates/logic_gate.h
        logic-gates/logic_gate.h
        logic-gates/logic_gate.h
        circuits/combinational/half-adder/half_adder.h
        circuits/combinational/half-adder/half_adder.c
        circuits/combinational/full-adder/full_adder.h
        circuits/combinational/full-adder/full_adder.c
        circuits/combinational/four-bit-adder/four_bit_adder.h
        circuits/combinational/four-bit-adder/four_bit_adder.c
        circuits/combinational/multiplexer/multiplexer.h
        circuits/combinational/multiplexer/multiplexer.c
        circuits/combinational/decoder/decoder.h
        circuits/combinational/decoder/decoder.c
        circuits/sequential/latch/sr_latch.h
        circuits/sequential/latch/sr_latch.c
        circuits/sequential/flip-flop/sr_flip_flop.c
        circuits/sequential/flip-flop/sr_flip_flop.h
)
target_include_directories(Digital_circuits_lab PRIVATE interfaces)