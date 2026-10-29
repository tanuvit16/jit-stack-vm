#ifndef STACK_VM_H
#define STACK_VM_H

#include "../bytecode/Instruction.h"
#include "../profiler/Profiler.h"

#include <vector>
#include <cstdint>
#include <cstddef>

class StackVM {
private:
    std::vector<int64_t> stack;
    std::size_t programCounter;

    Profiler profiler;

    void push(int64_t value);
    int64_t pop();
     std::size_t hotspotThreshold;

public:
    // StackVM();
    explicit StackVM(std::size_t hotspotThreshold = 3);

    void execute(
        const std::vector<Instruction>& program
    );

    const Profiler& getProfiler() const;
};

#endif