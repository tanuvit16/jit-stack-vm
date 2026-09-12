#include "Benchmark.h"

Benchmark::Benchmark() {
}

void Benchmark::start() {

    startTime =
        std::chrono::high_resolution_clock::now();
}


long long Benchmark::stopMicroseconds() {

    std::chrono::high_resolution_clock::time_point endTime =
        std::chrono::high_resolution_clock::now();


    return std::chrono::duration_cast<
        std::chrono::microseconds
    >(
        endTime - startTime
    ).count();
}