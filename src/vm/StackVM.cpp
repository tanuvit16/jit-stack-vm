#include "StackVM.h"

#include <iostream>
#include <stdexcept>

StackVM::StackVM()
    : programCounter(0),
      profiler(0) {
}

void StackVM::push(int64_t value) {
    stack.push_back(value);
}

int64_t StackVM::pop() {

    if (stack.empty()) {
        throw std::runtime_error("Stack underflow");
    }

    int64_t value = stack.back();
    stack.pop_back();

    return value;
}

void StackVM::execute(
    const std::vector<Instruction>& program) {

    programCounter = 0;
    stack.clear();

    profiler = Profiler(program.size(), 10);

    while (programCounter < program.size()) {

        profiler.recordExecution(programCounter);

        const Instruction& instruction =
            program[programCounter];

        switch (instruction.opcode) {

            case OpCode::PUSH:
                push(instruction.operand);
                break;

            case OpCode::POP:
                pop();
                break;

            case OpCode::DUP: {

                if (stack.empty()) {
                    throw std::runtime_error(
                        "Stack is empty"
                    );
                }

                push(stack.back());
                break;
            }

            case OpCode::ADD: {

                int64_t right = pop();
                int64_t left = pop();

                push(left + right);
                break;
            }

            case OpCode::SUB: {

                int64_t right = pop();
                int64_t left = pop();

                push(left - right);
                break;
            }

            case OpCode::MUL: {

                int64_t right = pop();
                int64_t left = pop();

                push(left * right);
                break;
            }

            case OpCode::DIV: {

                int64_t right = pop();
                int64_t left = pop();

                if (right == 0) {
                    throw std::runtime_error(
                        "Division by zero"
                    );
                }

                push(left / right);
                break;
            }

            case OpCode::JUMP: {

                if (instruction.operand < 0 ||
                    static_cast<std::size_t>(
                        instruction.operand
                    ) >= program.size()) {

                    throw std::runtime_error(
                        "Invalid jump target"
                    );
                }

                programCounter =
                    static_cast<std::size_t>(
                        instruction.operand
                    );

                continue;
            }

            case OpCode::JUMP_IF_ZERO: {

                if (stack.empty()) {
                    throw std::runtime_error(
                        "Stack underflow in JUMP_IF_ZERO"
                    );
                }

                int64_t value = pop();

                if (value == 0) {

                    if (instruction.operand < 0 ||
                        static_cast<std::size_t>(
                            instruction.operand
                        ) >= program.size()) {

                        throw std::runtime_error(
                            "Invalid conditional jump target"
                        );
                    }

                    programCounter =
                        static_cast<std::size_t>(
                            instruction.operand
                        );

                    continue;
                }

                break;
            }

            case OpCode::PRINT: {

                if (stack.empty()) {
                    throw std::runtime_error(
                        "Stack is empty"
                    );
                }

                std::cout << stack.back()
                          << std::endl;

                break;
            }

            case OpCode::HALT:
                return;
        }

        programCounter++;
    }
}

const Profiler& StackVM::getProfiler() const {
    return profiler;
}