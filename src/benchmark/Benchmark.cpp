// #include "Benchmark.h"

// Benchmark::Benchmark() {
// }

// void Benchmark::start() {

//     startTime =
//         std::chrono::high_resolution_clock::now();
// }


// long long Benchmark::stopMicroseconds() {

//     std::chrono::high_resolution_clock::time_point endTime =
//         std::chrono::high_resolution_clock::now();


//     return std::chrono::duration_cast<
//         std::chrono::microseconds
//     >(
//         endTime - startTime
//     ).count();
// }


















#include "Benchmark.h"

Benchmark::Benchmark() {
    startTime = std::chrono::steady_clock::now();
}

void Benchmark::start() {
    startTime = std::chrono::steady_clock::now();
}

double Benchmark::stopMicroseconds() {
    const auto endTime = std::chrono::steady_clock::now();

    return std::chrono::duration<double, std::micro>(
        endTime - startTime
    ).count();
}

long long Benchmark::stopNanoseconds() {
    const auto endTime = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime
    ).count();
}
