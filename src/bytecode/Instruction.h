#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>

enum class OpCode {
    PUSH,
    POP,
    DUP,
    ADD,
    SUB,
    MUL,
    DIV,
    JUMP,
    JUMP_IF_ZERO,
    PRINT,
    HALT
};

struct Instruction {
    OpCode opcode;
    int64_t operand;

    Instruction(OpCode op, int64_t value = 0)
        : opcode(op), operand(value) {}
};

#endif