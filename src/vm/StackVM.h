#ifndef STACK_VM_H
#define STACK_VM_H

#include "../bytecode/Instruction.h"
#include "../profiler/Profiler.h"

#include <vector>
#include <cstdint>

class StackVM {
private:
    std::vector<int64_t> stack;
    std::size_t programCounter;

    Profiler profiler;

    void push(int64_t value);
    int64_t pop();

public:
    StackVM();

    void execute(
        const std::vector<Instruction>& program
    );

    const Profiler& getProfiler() const;
};

#endif