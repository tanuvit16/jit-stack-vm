// #ifndef BENCHMARK_H
// #define BENCHMARK_H

// #include <chrono>

// class Benchmark {
// public:

//     Benchmark();

//     void start();

//     long long stopMicroseconds();

// private:

//     std::chrono::high_resolution_clock::time_point startTime;
// };

// #endif







#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>

class Benchmark {
public:
    Benchmark();

    void start();

    // Returns elapsed time in microseconds, including fractions.
    double stopMicroseconds();

    // Returns elapsed time in nanoseconds.
    long long stopNanoseconds();

private:
    std::chrono::steady_clock::time_point startTime;
};

#endif
