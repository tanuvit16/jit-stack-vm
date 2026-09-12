#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>

class Benchmark {
public:

    Benchmark();

    void start();

    long long stopMicroseconds();

private:

    std::chrono::high_resolution_clock::time_point startTime;
};

#endif