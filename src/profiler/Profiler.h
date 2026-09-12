// #ifndef PROFILER_H
// #define PROFILER_H

// #include <vector>
// #include <cstddef>

// class Profiler {
// private:
//     std::vector<unsigned long long> executionCounts;
//     unsigned long long hotspotThreshold;

// public:
//     Profiler(std::size_t instructionCount,
//              unsigned long long threshold = 10);

//     void recordExecution(std::size_t instructionIndex);

//     unsigned long long getExecutionCount(
//         std::size_t instructionIndex) const;

//     bool isHot(std::size_t instructionIndex) const;

//     unsigned long long getHotspotThreshold() const;
// };

// #endif





















#ifndef PROFILER_H
#define PROFILER_H

#include <vector>
#include <cstddef>

class Profiler {
private:
    std::vector<unsigned long long> executionCounts;
    unsigned long long totalExecutions;
    unsigned long long hotspotThreshold;

public:
    Profiler();
    Profiler(std::size_t instructionCount,
             unsigned long long threshold);

    void recordExecution(std::size_t instructionIndex);

    unsigned long long getExecutionCount(
        std::size_t instructionIndex) const;

    unsigned long long getTotalExecutions() const;

    unsigned long long getHotspotThreshold() const;

    bool isHot(std::size_t instructionIndex) const;
};

#endif