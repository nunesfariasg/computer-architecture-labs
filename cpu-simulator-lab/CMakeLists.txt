cmake_minimum_required(VERSION 3.16)

project(SimpleCPUSimulator C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(simple_cpu_simulator
        main.c
        cpu/cpu.c
        memory/memory.c
        instruction/instruction.c
)