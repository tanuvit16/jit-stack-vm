#include "Profiler.h"

#include <stdexcept>

Profiler::Profiler(std::size_t instructionCount,
                   unsigned long long threshold)
    : executionCounts(instructionCount, 0),
      hotspotThreshold(threshold) {
}

void Profiler::recordExecution(std::size_t instructionIndex) {

    if (instructionIndex >= executionCounts.size()) {
        throw std::out_of_range("Invalid instruction index");
    }

    executionCounts[instructionIndex]++;
}

unsigned long long Profiler::getExecutionCount(
    std::size_t instructionIndex) const {

    if (instructionIndex >= executionCounts.size()) {
        throw std::out_of_range("Invalid instruction index");
    }

    return executionCounts[instructionIndex];
}

bool Profiler::isHot(std::size_t instructionIndex) const {

    return getExecutionCount(instructionIndex)
           >= hotspotThreshold;
}

unsigned long long Profiler::getHotspotThreshold() const {
    return hotspotThreshold;
}