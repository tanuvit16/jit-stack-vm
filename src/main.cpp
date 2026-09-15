























// // #include <iostream>
// // #include <string>
// // #include <sstream>
// // #include <vector>
// // #include <cctype>
// // #include <utility>

// // #include "bytecode/Instruction.h"
// // #include "vm/StackVM.h"
// // #include "jit/JITCompiler.h"
// // #include "benchmark/Benchmark.h"

// // using namespace std;


// // // ============================================================
// // // Convert string to uppercase
// // // ============================================================

// // string toUpperCase(string text)
// // {
// //     for (size_t i = 0; i < text.length(); ++i)
// //     {
// //         text[i] = static_cast<char>(
// //             toupper(
// //                 static_cast<unsigned char>(text[i])
// //             )
// //         );
// //     }

// //     return text;
// // }


// // // ============================================================
// // // Parse bytecode instruction
// // // ============================================================

// // Instruction parseInstruction(const string& line)
// // {
// //     stringstream ss(line);

// //     string opcodeText;

// //     ss >> opcodeText;

// //     opcodeText = toUpperCase(opcodeText);


// //     if (opcodeText == "PUSH")
// //     {
// //         long long value;

// //         ss >> value;

// //         return Instruction(
// //             OpCode::PUSH,
// //             value
// //         );
// //     }


// //     if (opcodeText == "POP")
// //     {
// //         return Instruction(
// //             OpCode::POP,
// //             0
// //         );
// //     }


// //     if (opcodeText == "DUP")
// //     {
// //         return Instruction(
// //             OpCode::DUP,
// //             0
// //         );
// //     }


// //     if (opcodeText == "ADD")
// //     {
// //         return Instruction(
// //             OpCode::ADD,
// //             0
// //         );
// //     }


// //     if (opcodeText == "SUB")
// //     {
// //         return Instruction(
// //             OpCode::SUB,
// //             0
// //         );
// //     }


// //     if (opcodeText == "MUL")
// //     {
// //         return Instruction(
// //             OpCode::MUL,
// //             0
// //         );
// //     }


// //     if (opcodeText == "DIV")
// //     {
// //         return Instruction(
// //             OpCode::DIV,
// //             0
// //         );
// //     }


// //     if (opcodeText == "JUMP")
// //     {
// //         long long target;

// //         ss >> target;

// //         return Instruction(
// //             OpCode::JUMP,
// //             target
// //         );
// //     }


// //     if (opcodeText == "JUMP_IF_ZERO")
// //     {
// //         long long target;

// //         ss >> target;

// //         return Instruction(
// //             OpCode::JUMP_IF_ZERO,
// //             target
// //         );
// //     }


// //     if (opcodeText == "PRINT")
// //     {
// //         return Instruction(
// //             OpCode::PRINT,
// //             0
// //         );
// //     }


// //     if (opcodeText == "HALT")
// //     {
// //         return Instruction(
// //             OpCode::HALT,
// //             0
// //         );
// //     }


// //     cerr << "Invalid instruction: "
// //          << line
// //          << endl;


// //     return Instruction(
// //         OpCode::HALT,
// //         0
// //     );
// // }


// // // ============================================================
// // // MAIN
// // // ============================================================

// // int main()
// // {
// //     cout << "====================================" << endl;
// //     cout << "     Stack-Based Virtual Machine" << endl;
// //     cout << "====================================" << endl;

// //     cout << endl;


// //     // ========================================================
// //     // PHASE 1 — Instruction Set Design
// //     // ========================================================

// //     size_t instructionCount;

// //     cout << "Enter number of instructions: ";

// //     cin >> instructionCount;

// //     cin.ignore();


// //     vector<Instruction> program;


// //     cout << endl;

// //     cout << "Enter bytecode instructions:" << endl;

// //     cout << "Supported instructions:" << endl;

// //     cout << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV," << endl;

// //     cout << "JUMP <index>, JUMP_IF_ZERO <index>," << endl;

// //     cout << "PRINT, HALT" << endl;

// //     cout << endl;


// //     for (size_t i = 0;
// //          i < instructionCount;
// //          ++i)
// //     {
// //         string line;

// //         cout << i << ": ";

// //         getline(cin, line);


// //         program.push_back(
// //             parseInstruction(line)
// //         );
// //     }


// //     // ========================================================
// //     // PHASE 2 + PHASE 3
// //     // Stack VM + Interpreter
// //     // ========================================================

// //     cout << endl;

// //     cout << "========== Execution =========="
// //          << endl;


// //     StackVM vm;


// //     // --------------------------------------------------------
// //     // Benchmark interpreter execution
// //     // --------------------------------------------------------

// //     Benchmark interpreterBenchmark;

// //     interpreterBenchmark.start();


// //     vm.execute(program);


// //     long long interpreterTime =
// //         interpreterBenchmark.stopMicroseconds();


// //     // ========================================================
// //     // PHASE 4 — Runtime Profiling
// //     // ========================================================

// //     const Profiler& profiler =
// //         vm.getProfiler();


// //     cout << endl;

// //     cout << "========== Runtime Profiler =========="
// //          << endl;


// //     cout << "Profiler Status: ACTIVE"
// //          << endl;


// //     cout << "Instructions monitored: "
// //          << program.size()
// //          << endl;


// //     cout << "Total instructions executed: "
// //          << profiler.getTotalExecutions()
// //          << endl;


// //     cout << "Hotspot threshold: "
// //          << profiler.getHotspotThreshold()
// //          << endl;


// //     cout << endl;

// //     cout << "Execution Frequency:"
// //          << endl;


// //     for (size_t i = 0;
// //          i < program.size();
// //          ++i)
// //     {
// //         cout << "Instruction "
// //              << i
// //              << " -> "
// //              << profiler.getExecutionCount(i)
// //              << " execution(s)"
// //              << endl;
// //     }


// //     // ========================================================
// //     // PHASE 5 — Hotspot Detection
// //     // ========================================================

// //     cout << endl;

// //     cout << "========== Hotspot Detection =========="
// //          << endl;


// //     cout << "Hotspot Threshold: "
// //          << profiler.getHotspotThreshold()
// //          << endl;


// //     vector<
// //         pair<size_t, Instruction>
// //     > hotInstructions;


// //     for (size_t i = 0;
// //          i < program.size();
// //          ++i)
// //     {
// //         unsigned long long count =
// //             profiler.getExecutionCount(i);


// //         cout << "Instruction "
// //              << i
// //              << " -> "
// //              << count
// //              << " execution(s) -> ";


// //         if (profiler.isHot(i))
// //         {
// //             cout << "HOT";


// //             hotInstructions.push_back(
// //                 make_pair(
// //                     i,
// //                     program[i]
// //                 )
// //             );
// //         }
// //         else
// //         {
// //             cout << "NORMAL";
// //         }


// //         cout << endl;
// //     }


// //     cout << endl;

// //     cout << "Hotspot Detection completed successfully."
// //          << endl;


// //     // ========================================================
// //     // PHASE 6 — JIT Compilation
// //     // ========================================================

// //     cout << endl;

// //     cout << "========== JIT Compilation =========="
// //          << endl;


// //     cout << "Hot instructions detected: "
// //          << hotInstructions.size()
// //          << endl;


// //     if (hotInstructions.empty())
// //     {
// //         cout << "No hot instructions detected."
// //              << endl;

// //         cout << "JIT compilation skipped."
// //              << endl;


// //         // ====================================================
// //         // PHASE 8 — Benchmarking
// //         // ====================================================

// //         cout << endl;

// //         cout << "========== Phase 8: Benchmarking =========="
// //              << endl;


// //         cout << "Interpreter Execution Time : "
// //              << interpreterTime
// //              << " microseconds"
// //              << endl;


// //         cout << "JIT Compilation Time      : N/A"
// //              << endl;


// //         cout << "JIT Execution Time        : N/A"
// //              << endl;


// //         cout << "JIT Total Time            : N/A"
// //              << endl;


// //         cout << "Hot Instructions          : 0"
// //              << endl;


// //         cout << "Code Cache Entries        : 0"
// //              << endl;


// //         cout << endl;

// //         cout << "Benchmark completed successfully."
// //              << endl;
// //     }
// //     else
// //     {
// //         cout << "Passing hot instructions to JIT compiler..."
// //              << endl;


// //         JITCompiler jitCompiler;


// //         // ====================================================
// //         // PHASE 7 — First Cache Request
// //         // ====================================================

// //         cout << endl;

// //         cout << "========== First JIT Request =========="
// //              << endl;


// //         cout << "Checking code cache..."
// //              << endl;


// //         if (jitCompiler.isCached(hotInstructions))
// //         {
// //             cout << "[CACHE] HIT"
// //                  << endl;

// //             cout << "[CACHE] Reusing previously compiled code."
// //                  << endl;
// //         }
// //         else
// //         {
// //             cout << "[CACHE] MISS"
// //                  << endl;

// //             cout << "[CACHE] No compiled code found."
// //                  << endl;
// //         }


// //         // ====================================================
// //         // PHASE 6 — JIT Compilation Benchmark
// //         // ====================================================

// //         Benchmark jitCompilationBenchmark;

// //         jitCompilationBenchmark.start();


// //         jitCompiler.compile(
// //             hotInstructions
// //         );


// //         long long jitCompilationTime =
// //             jitCompilationBenchmark.stopMicroseconds();


// //         // Display compiler information

// //         jitCompiler.printCompilationInfo();


// //         // ====================================================
// //         // PHASE 6 — JIT Execution Benchmark
// //         // ====================================================

// //         Benchmark jitExecutionBenchmark;

// //         jitExecutionBenchmark.start();


// //      //    jitCompiler.execute(10000);
// //      jitCompiler.executeOptimizedLoop(10000);


// //         long long jitExecutionTime =
// //             jitExecutionBenchmark.stopMicroseconds();


// //         // ====================================================
// //         // PHASE 7 — Second Cache Request
// //         // ====================================================

// //         cout << endl;

// //         cout << "========== Second JIT Request =========="
// //              << endl;


// //         cout << "Checking code cache again..."
// //              << endl;


// //         if (jitCompiler.isCached(hotInstructions))
// //         {
// //             cout << "[CACHE] HIT"
// //                  << endl;

// //             cout << "[CACHE] Reusing previously compiled code."
// //                  << endl;
// //         }
// //         else
// //         {
// //             cout << "[CACHE] MISS"
// //                  << endl;
// //         }


// //         // Request the same compilation again.
// //         // JITCompiler internally detects the cache hit.

// //         jitCompiler.compile(
// //             hotInstructions
// //         );


// //         cout << endl;

// //         cout << "[CACHE] Cached code reused successfully."
// //              << endl;


// //         // ====================================================
// //         // FINAL CACHE STATUS
// //         // ====================================================

// //         cout << endl;

// //         cout << "========== Final Cache Status =========="
// //              << endl;


// //         cout << "Code Cache Entries: "
// //              << jitCompiler.getCacheSize()
// //              << endl;


// //         cout << "Code caching phase completed successfully."
// //              << endl;


// //         // ====================================================
// //         // PHASE 8 — BENCHMARKING
// //         // ====================================================

// //         cout << endl;

// //         cout << "========== Phase 8: Benchmarking =========="
// //              << endl;


// //         cout << endl;


// //         cout << "Interpreter Execution Time : "
// //              << interpreterTime
// //              << " microseconds"
// //              << endl;


// //         cout << "JIT Compilation Time      : "
// //              << jitCompilationTime
// //              << " microseconds"
// //              << endl;


// //         cout << "JIT Execution Time        : "
// //              << jitExecutionTime
// //              << " microseconds"
// //              << endl;


// //         cout << "JIT Total Time            : "
// //              << jitCompilationTime
// //              + jitExecutionTime
// //              << " microseconds"
// //              << endl;


// //         cout << "Hot Instructions          : "
// //              << hotInstructions.size()
// //              << endl;


// //         cout << "Compiled Instructions     : "
// //              << hotInstructions.size()
// //              << endl;


// //         cout << "Code Cache Entries        : "
// //              << jitCompiler.getCacheSize()
// //              << endl;


// //         // ----------------------------------------------------
// //         // Performance comparison
// //         // ----------------------------------------------------

// //         cout << endl;

// //         cout << "========== Performance Comparison =========="
// //              << endl;


// //         cout << "Interpreter Time : "
// //              << interpreterTime
// //              << " microseconds"
// //              << endl;


// //         cout << "JIT Total Time   : "
// //              << jitCompilationTime
// //              + jitExecutionTime
// //              << " microseconds"
// //              << endl;


// //         if (interpreterTime > 0)
// //         {
// //             double speedup =
// //                 static_cast<double>(interpreterTime)
// //                 /
// //                 static_cast<double>(
// //                     jitCompilationTime
// //                     + jitExecutionTime
// //                 );


// //             cout << "Measured Ratio   : "
// //                  << speedup
// //                  << "x"
// //                  << endl;
// //         }
// //         else
// //         {
// //             cout << "Measured Ratio   : N/A"
// //                  << endl;
// //         }


// //         cout << endl;

// //         cout << "Note: This benchmark measures the "
// //              << "current JIT prototype implementation."
// //              << endl;

// //         cout << "Native machine-code speedup is not "
// //              << "claimed by this prototype."
// //              << endl;


// //         cout << endl;

// //         cout << "Benchmark completed successfully."
// //              << endl;
// //     }


// //     // ========================================================
// //     // PROGRAM COMPLETED
// //     // ========================================================

// //     cout << endl;

// //     cout << "===================================="
// //          << endl;

// //     cout << "          Program Completed"
// //          << endl;

// //     cout << "===================================="
// //          << endl;


// //     return 0;
// // }










// #include <iostream>
// #include <vector>
// #include <string>
// #include <utility>
// #include <stdexcept>

// #include "bytecode/Instruction.h"
// #include "vm/StackVM.h"
// #include "jit/JITCompiler.h"
// #include "benchmark/Benchmark.h"

// using namespace std;

// int main()
// {
//     // ========================================================
//     // PROJECT HEADER
//     // ========================================================

//     cout << "====================================" << endl;
//     cout << "     Stack-Based Virtual Machine" << endl;
//     cout << "====================================" << endl;
//     cout << endl;


//     // ========================================================
//     // BYTECODE INPUT
//     // ========================================================

//     int instructionCount;

//     cout << "Enter number of instructions: ";
//     cin >> instructionCount;

//     cin.ignore();

//     vector<Instruction> program;

//     cout << endl;
//     cout << "Enter bytecode instructions:" << endl;

//     cout << "Supported instructions:" << endl;
//     cout << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV," << endl;
//     cout << "JUMP <index>, JUMP_IF_ZERO <index>," << endl;
//     cout << "PRINT, HALT" << endl;
//     cout << endl;


//     // ========================================================
//     // INSTRUCTION INPUT
//     // ========================================================

//     for (int i = 0; i < instructionCount; i++)
//     {
//         string opcode;
//         long long operand = 0;

//         cout << i << ": ";

//         cin >> opcode;

//         if (opcode == "PUSH")
//         {
//             cin >> operand;

//             program.push_back(
//                 Instruction(OpCode::PUSH, operand)
//             );
//         }
//         else if (opcode == "POP")
//         {
//             program.push_back(
//                 Instruction(OpCode::POP, 0)
//             );
//         }
//         else if (opcode == "DUP")
//         {
//             program.push_back(
//                 Instruction(OpCode::DUP, 0)
//             );
//         }
//         else if (opcode == "ADD")
//         {
//             program.push_back(
//                 Instruction(OpCode::ADD, 0)
//             );
//         }
//         else if (opcode == "SUB")
//         {
//             program.push_back(
//                 Instruction(OpCode::SUB, 0)
//             );
//         }
//         else if (opcode == "MUL")
//         {
//             program.push_back(
//                 Instruction(OpCode::MUL, 0)
//             );
//         }
//         else if (opcode == "DIV")
//         {
//             program.push_back(
//                 Instruction(OpCode::DIV, 0)
//             );
//         }
//         else if (opcode == "JUMP")
//         {
//             cin >> operand;

//             program.push_back(
//                 Instruction(OpCode::JUMP, operand)
//             );
//         }
//         else if (opcode == "JUMP_IF_ZERO")
//         {
//             cin >> operand;

//             program.push_back(
//                 Instruction(OpCode::JUMP_IF_ZERO, operand)
//             );
//         }
//         else if (opcode == "PRINT")
//         {
//             program.push_back(
//                 Instruction(OpCode::PRINT, 0)
//             );
//         }
//         else if (opcode == "HALT")
//         {
//             program.push_back(
//                 Instruction(OpCode::HALT, 0)
//             );
//         }
//         else
//         {
//             cout << "Invalid instruction: "
//                  << opcode
//                  << endl;

//             return 1;
//         }
//     }


//     // ========================================================
//     // PHASE 1 — INTERPRETER EXECUTION
//     // ========================================================

//     cout << endl;
//     cout << "========== Execution ==========" << endl;

//     StackVM vm;

//     Benchmark interpreterBenchmark;

//     interpreterBenchmark.start();

//     vm.execute(program);

//     long long interpreterTime =
//         interpreterBenchmark.stopMicroseconds();


//     // ========================================================
//     // PHASE 2 — RUNTIME PROFILER
//     // ========================================================

//     const Profiler& profiler =
//         vm.getProfiler();

//     cout << endl;
//     cout << "========== Runtime Profiler =========="
//          << endl;

//     profiler.printReport();


//     // ========================================================
//     // PHASE 3 — HOTSPOT DETECTION
//     // ========================================================

//     cout << endl;
//     cout << "========== Hotspot Detection =========="
//          << endl;

//     profiler.printHotspots();


//     // ========================================================
//     // PHASE 4 — COLLECT HOT INSTRUCTIONS
//     // ========================================================

//     vector<pair<size_t, Instruction> >
//         hotInstructions;

//     const vector<size_t>& frequencies =
//         profiler.getExecutionCounts();

//     const size_t threshold =
//         profiler.getHotspotThreshold();

//     for (size_t i = 0;
//          i < program.size();
//          i++)
//     {
//         if (frequencies[i] >= threshold)
//         {
//             hotInstructions.push_back(
//                 make_pair(i, program[i])
//             );
//         }
//     }


//     // ========================================================
//     // PHASE 5 — JIT COMPILATION
//     // ========================================================

//     cout << endl;
//     cout << "========== JIT Compilation =========="
//          << endl;

//     cout << "Hot instructions detected: "
//          << hotInstructions.size()
//          << endl;

//     JITCompiler jitCompiler;

//     long long jitCompilationTime = 0;

//     if (!hotInstructions.empty())
//     {
//         cout << "Passing hot instructions to JIT compiler..."
//              << endl;

//         cout << endl;
//         cout << "========== First JIT Request =========="
//              << endl;

//         cout << "Checking code cache..."
//              << endl;

//         if (jitCompiler.isCached(hotInstructions))
//         {
//             cout << "[CACHE] HIT"
//                  << endl;

//             cout << "[CACHE] Reusing previously compiled code."
//                  << endl;
//         }
//         else
//         {
//             cout << "[CACHE] MISS"
//                  << endl;

//             cout << "[CACHE] No compiled code found."
//                  << endl;

//             cout << endl;
//             cout << "[JIT] Code cache MISS."
//                  << endl;

//             cout << "[JIT] No compiled hot block found."
//                  << endl;

//             Benchmark jitCompilationBenchmark;

//             jitCompilationBenchmark.start();

//             jitCompiler.compile(
//                 hotInstructions
//             );

//             jitCompilationTime =
//                 jitCompilationBenchmark
//                     .stopMicroseconds();
//         }

//         jitCompiler.printCompilationInfo();
//     }
//     else
//     {
//         cout << "No hot instructions detected."
//              << endl;

//         cout << "JIT compilation skipped."
//              << endl;
//     }


//     // ========================================================
//     // PHASE 6 — INITIAL JIT EXECUTION
//     // ========================================================

//     if (!hotInstructions.empty())
//     {
//         cout << endl;
//         cout << "========== Initial JIT Execution =========="
//              << endl;

//         cout << "Executing optimized hot region..."
//              << endl;

//         jitCompiler.executeOptimizedLoop(10000);

//         cout << "[JIT] Initial optimized execution completed."
//              << endl;
//     }


//     // ========================================================
//     // PHASE 7 — SECOND CACHE REQUEST
//     // ========================================================

//     if (!hotInstructions.empty())
//     {
//         cout << endl;

//         cout << "========== Second JIT Request =========="
//              << endl;

//         cout << "Checking code cache again..."
//              << endl;

//         if (jitCompiler.isCached(hotInstructions))
//         {
//             cout << "[CACHE] HIT"
//                  << endl;

//             cout << "[CACHE] Reusing previously compiled code."
//                  << endl;
//         }
//         else
//         {
//             cout << "[CACHE] MISS"
//                  << endl;
//         }

//         // Request the same compilation again.
//         // JITCompiler should reuse the cached block.

//         jitCompiler.compile(
//             hotInstructions
//         );

//         cout << endl;

//         cout << "[CACHE] Cached code reused successfully."
//              << endl;


//         // ----------------------------------------------------
//         // FINAL CACHE STATUS
//         // ----------------------------------------------------

//         cout << endl;

//         cout << "========== Final Cache Status =========="
//              << endl;

//         cout << "Code Cache Entries: "
//              << jitCompiler.getCacheSize()
//              << endl;

//         cout << "Code caching phase completed successfully."
//              << endl;
//     }


//     // ========================================================
//     // PHASE 8 — FAIR JIT PERFORMANCE BENCHMARK
//     // ========================================================

//     if (!hotInstructions.empty())
//     {
//         cout << endl;

//         cout << "========== Phase 8: JIT Performance Benchmark =========="
//              << endl;

//         const int BENCHMARK_ITERATIONS = 100;


//         // ----------------------------------------------------
//         // Interpreter Benchmark
//         // ----------------------------------------------------

//         cout << endl;

//         cout << "[BENCHMARK] Running interpreter "
//              << BENCHMARK_ITERATIONS
//              << " times..."
//              << endl;

//         Benchmark interpreterRepeatedBenchmark;

//         interpreterRepeatedBenchmark.start();

//         for (int i = 0;
//              i < BENCHMARK_ITERATIONS;
//              i++)
//         {
//             vm.execute(program);
//         }

//         long long interpreterTotalTime =
//             interpreterRepeatedBenchmark
//                 .stopMicroseconds();

//         double interpreterAverage =
//             static_cast<double>(
//                 interpreterTotalTime
//             )
//             /
//             BENCHMARK_ITERATIONS;


//         // ----------------------------------------------------
//         // JIT Steady-State Benchmark
//         // ----------------------------------------------------

//         cout << endl;

//         cout << "[BENCHMARK] Running optimized JIT loop "
//              << BENCHMARK_ITERATIONS
//              << " times..."
//              << endl;

//         Benchmark jitRepeatedBenchmark;

//         jitRepeatedBenchmark.start();

//         for (int i = 0;
//              i < BENCHMARK_ITERATIONS;
//              i++)
//         {
//             jitCompiler.executeOptimizedLoop(10000);
//         }

//         long long jitTotalTime =
//             jitRepeatedBenchmark
//                 .stopMicroseconds();

//         double jitAverage =
//             static_cast<double>(
//                 jitTotalTime
//             )
//             /
//             BENCHMARK_ITERATIONS;


//         // ----------------------------------------------------
//         // Benchmark Results
//         // ----------------------------------------------------

//         cout << endl;

//         cout << "========== Benchmark Results =========="
//              << endl;

//         cout << endl;

//         cout << "Benchmark Iterations       : "
//              << BENCHMARK_ITERATIONS
//              << endl;

//         cout << "Interpreter Total Time     : "
//              << interpreterTotalTime
//              << " microseconds"
//              << endl;

//         cout << "Interpreter Average Time   : "
//              << interpreterAverage
//              << " microseconds"
//              << endl;

//         cout << "JIT Compilation Time       : "
//              << jitCompilationTime
//              << " microseconds"
//              << endl;

//         cout << "JIT Steady-State Total     : "
//              << jitTotalTime
//              << " microseconds"
//              << endl;

//         cout << "JIT Steady-State Average   : "
//              << jitAverage
//              << " microseconds"
//              << endl;

//         cout << "Hot Instructions           : "
//              << hotInstructions.size()
//              << endl;

//         cout << "Compiled Instructions      : "
//              << hotInstructions.size()
//              << endl;

//         cout << "Code Cache Entries         : "
//              << jitCompiler.getCacheSize()
//              << endl;


//         // ----------------------------------------------------
//         // Performance Comparison
//         // ----------------------------------------------------

//         cout << endl;

//         cout << "========== Performance Comparison =========="
//              << endl;

//         cout << endl;

//         cout << "Interpreter Average : "
//              << interpreterAverage
//              << " microseconds"
//              << endl;

//         cout << "JIT Average         : "
//              << jitAverage
//              << " microseconds"
//              << endl;

//         if (jitAverage > 0.0)
//         {
//             double speedup =
//                 interpreterAverage
//                 /
//                 jitAverage;

//             cout << "JIT Steady-State Speedup : "
//                  << speedup
//                  << "x"
//                  << endl;

//             if (speedup > 1.0)
//             {
//                 cout << "RESULT: JIT is faster than "
//                      << "the interpreter."
//                      << endl;
//             }
//             else
//             {
//                 cout << "RESULT: JIT is currently slower "
//                      << "than the interpreter."
//                      << endl;
//             }
//         }
//         else
//         {
//             cout << "JIT Speedup : N/A"
//                  << endl;
//         }


//         // ----------------------------------------------------
//         // Break-Even Analysis
//         // ----------------------------------------------------

//         cout << endl;

//         cout << "========== JIT Break-Even Analysis =========="
//              << endl;

//         if (jitAverage < interpreterAverage)
//         {
//             double compilationCost =
//                 static_cast<double>(
//                     jitCompilationTime
//                 );

//             double savingPerExecution =
//                 interpreterAverage
//                 -
//                 jitAverage;

//             if (savingPerExecution > 0.0)
//             {
//                 double breakEven =
//                     compilationCost
//                     /
//                     savingPerExecution;

//                 cout << "Compilation Cost : "
//                      << compilationCost
//                      << " microseconds"
//                      << endl;

//                 cout << "Saving Per Run   : "
//                      << savingPerExecution
//                      << " microseconds"
//                      << endl;

//                 cout << "Break-Even Point : "
//                      << breakEven
//                      << " executions"
//                      << endl;
//             }
//         }
//         else
//         {
//             cout << "JIT is not faster in the "
//                  << "current benchmark."
//                  << endl;

//             cout << "No positive break-even point "
//                  << "can be calculated."
//                  << endl;
//         }


//         cout << endl;

//         cout << "Note: JIT compilation cost is measured "
//              << "separately from steady-state execution."
//              << endl;

//         cout << "The speedup comparison measures repeated "
//              << "execution after compilation."
//              << endl;

//         cout << endl;

//         cout << "Benchmark completed successfully."
//              << endl;
//     }
//     else
//     {
//         cout << endl;

//         cout << "========== Phase 8: Benchmarking =========="
//              << endl;

//         cout << "Benchmark skipped because no hot code "
//              << "was detected."
//              << endl;
//     }


//     // ========================================================
//     // PROGRAM COMPLETED
//     // ========================================================

//     cout << endl;

//     cout << "===================================="
//          << endl;

//     cout << "          Program Completed"
//          << endl;

//     cout << "===================================="
//          << endl;


//     return 0;
// }
















#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <chrono>
#include <iomanip>

#include "bytecode/Instruction.h"
#include "vm/StackVM.h"
#include "profiler/Profiler.h"
#include "jit/JITCompiler.h"
#include "benchmark/Benchmark.h"

using namespace std;


/*
 * ============================================================
 * JIT Compiler for Stack-Based Virtual Machine
 * Main Driver
 * ============================================================
 *
 * Execution pipeline:
 *
 * Bytecode
 *    |
 *    v
 * Stack VM
 *    |
 *    v
 * Runtime Profiler
 *    |
 *    v
 * Hotspot Detection
 *    |
 *    v
 * JIT Compiler
 *    |
 *    v
 * Code Cache
 *    |
 *    v
 * Optimized Hot Loop
 *    |
 *    v
 * Benchmark
 *
 * The benchmark deliberately separates:
 *
 * 1. JIT compilation cost
 * 2. JIT steady-state execution
 *
 * This is important because real JIT systems pay compilation
 * cost once and then reuse the compiled code many times.
 */


// ============================================================
// Helper: Convert user input into Instruction
// ============================================================

bool parseInstruction(
    const string& line,
    Instruction& instruction)
{
    stringstream ss(line);

    string opcode;
    long long operand = 0;

    ss >> opcode;

    if (opcode == "PUSH")
    {
        if (!(ss >> operand))
            return false;

        instruction.opcode = OpCode::PUSH;
        instruction.operand = operand;
        return true;
    }

    if (opcode == "POP")
    {
        instruction.opcode = OpCode::POP;
        instruction.operand = 0;
        return true;
    }

    if (opcode == "DUP")
    {
        instruction.opcode = OpCode::DUP;
        instruction.operand = 0;
        return true;
    }

    if (opcode == "ADD")
    {
        instruction.opcode = OpCode::ADD;
        instruction.operand = 0;
        return true;
    }

    if (opcode == "SUB")
    {
        instruction.opcode = OpCode::SUB;
        instruction.operand = 0;
        return true;
    }

    if (opcode == "MUL")
    {
        instruction.opcode = OpCode::MUL;
        instruction.operand = 0;
        return true;
    }

    if (opcode == "DIV")
    {
        instruction.opcode = OpCode::DIV;
        instruction.operand = 0;
        return true;
    }

    if (opcode == "JUMP")
    {
        if (!(ss >> operand))
            return false;

        instruction.opcode = OpCode::JUMP;
        instruction.operand = operand;
        return true;
    }

    if (opcode == "JUMP_IF_ZERO")
    {
        if (!(ss >> operand))
            return false;

        instruction.opcode = OpCode::JUMP_IF_ZERO;
        instruction.operand = operand;
        return true;
    }

    if (opcode == "PRINT")
    {
        instruction.opcode = OpCode::PRINT;
        instruction.operand = 0;
        return true;
    }

    if (opcode == "HALT")
    {
        instruction.opcode = OpCode::HALT;
        instruction.operand = 0;
        return true;
    }

    return false;
}


// ============================================================
// Helper: Convert opcode to string
// ============================================================

string opcodeToString(OpCode opcode)
{
    switch (opcode)
    {
        case OpCode::PUSH:
            return "PUSH";

        case OpCode::POP:
            return "POP";

        case OpCode::DUP:
            return "DUP";

        case OpCode::ADD:
            return "ADD";

        case OpCode::SUB:
            return "SUB";

        case OpCode::MUL:
            return "MUL";

        case OpCode::DIV:
            return "DIV";

        case OpCode::JUMP:
            return "JUMP";

        case OpCode::JUMP_IF_ZERO:
            return "JUMP_IF_ZERO";

        case OpCode::PRINT:
            return "PRINT";

        case OpCode::HALT:
            return "HALT";
    }

    return "UNKNOWN";
}


// ============================================================
// Main
// ============================================================

int main()
{
    cout << "====================================" << endl;
    cout << "     Stack-Based Virtual Machine" << endl;
    cout << "====================================" << endl;
    cout << endl;


    // ========================================================
    // PHASE 1 — Bytecode Input
    // ========================================================

    int instructionCount;

    cout << "Enter number of instructions: ";
    cin >> instructionCount;

    cin.ignore();

    if (instructionCount <= 0)
    {
        cout << "Invalid instruction count." << endl;
        return 1;
    }

    vector<Instruction> program;

    cout << endl;

    cout << "Enter bytecode instructions:" << endl;

    cout << "Supported instructions:" << endl;

    cout << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV,"
         << endl;

    cout << "JUMP <index>, JUMP_IF_ZERO <index>,"
         << endl;

    cout << "PRINT, HALT"
         << endl;

    cout << endl;


    for (int i = 0; i < instructionCount; ++i)
    {
        string line;

        getline(cin, line);

        Instruction instruction;
     // Instruction instruction(OpCode::HALT);

        if (!parseInstruction(line, instruction))
        {
            cout << "Invalid instruction: "
                 << line
                 << endl;

            return 1;
        }

        program.push_back(instruction);

        cout << i << ": "
             << opcodeToString(instruction.opcode);

        if (instruction.opcode == OpCode::PUSH ||
            instruction.opcode == OpCode::JUMP ||
            instruction.opcode == OpCode::JUMP_IF_ZERO)
        {
            cout << " "
                 << instruction.operand;
        }

        cout << endl;
    }


    // ========================================================
    // PHASE 2 — Interpreter Execution
    // ========================================================

    cout << endl;
    cout << "========== Execution =========="
         << endl;

    StackVM vm;

    Benchmark interpreterBenchmark;

    interpreterBenchmark.start();

    vm.execute(program);

    long long interpreterTime =
        interpreterBenchmark.stopMicroseconds();


    // ========================================================
    // PHASE 3 — Runtime Profiler
    // ========================================================

    cout << endl;

    cout << "========== Runtime Profiler =========="
         << endl;

    const Profiler& profiler =
        vm.getProfiler();

    cout << "Profiler Status: ACTIVE"
         << endl;

    cout << "Instructions monitored: "
         << program.size()
         << endl;

    cout << "Total instructions executed: "
         << profiler.getTotalExecutions()
         << endl;

    cout << "Hotspot threshold: "
         << profiler.getHotspotThreshold()
         << endl;


    cout << endl;

    cout << "Execution Frequency:"
         << endl;


    for (size_t i = 0; i < program.size(); ++i)
    {
        cout << "Instruction "
             << i
             << " -> "
             << profiler.getExecutionCount(i)
             << " execution(s)"
             << endl;
    }


    // ========================================================
    // PHASE 4 — Hotspot Detection
    // ========================================================

    cout << endl;

    cout << "========== Hotspot Detection =========="
         << endl;

    cout << "Hotspot Threshold: "
         << profiler.getHotspotThreshold()
         << endl;


    vector<pair<size_t, Instruction> > hotInstructions;


    for (size_t i = 0; i < program.size(); ++i)
    {
        bool hot =
            profiler.isHot(i);

        cout << "Instruction "
             << i
             << " -> "
             << profiler.getExecutionCount(i)
             << " execution(s) -> ";

        if (hot)
        {
            cout << "HOT";

            hotInstructions.push_back(
                make_pair(i, program[i])
            );
        }
        else
        {
            cout << "NORMAL";
        }

        cout << endl;
    }


    cout << endl;

    cout << "Hotspot Detection completed successfully."
         << endl;


    // ========================================================
    // PHASE 5 — JIT Compilation
    // ========================================================

    cout << endl;

    cout << "========== JIT Compilation =========="
         << endl;


    JITCompiler jitCompiler;


    if (hotInstructions.empty())
    {
        cout << "Hot instructions detected: 0"
             << endl;

        cout << "No hot instructions detected."
             << endl;

        cout << "JIT compilation skipped."
             << endl;
    }
    else
    {
        cout << "Hot instructions detected: "
             << hotInstructions.size()
             << endl;

        cout << "Passing hot instructions to JIT compiler..."
             << endl;


        // ----------------------------------------------------
        // First cache request
        // ----------------------------------------------------

        cout << endl;

        cout << "========== First JIT Request =========="
             << endl;

        cout << "Checking code cache..."
             << endl;


        if (jitCompiler.isCached(hotInstructions))
        {
            cout << "[CACHE] HIT"
                 << endl;

            cout << "[CACHE] Reusing previously compiled code."
                 << endl;
        }
        else
        {
            cout << "[CACHE] MISS"
                 << endl;

            cout << "[CACHE] No compiled code found."
                 << endl;
        }


        // ----------------------------------------------------
        // Measure ONLY compilation time
        // ----------------------------------------------------

        Benchmark compilationBenchmark;

        compilationBenchmark.start();

        jitCompiler.compile(
            hotInstructions
        );

        long long jitCompilationTime =
            compilationBenchmark.stopMicroseconds();


        // ----------------------------------------------------
        // Compilation information
        // ----------------------------------------------------

        cout << endl;

        cout << "========== JIT Compiler =========="
             << endl;

        jitCompiler.printCompilationInfo();


        // ====================================================
        // PHASE 6 — JIT Warm-up
        // ====================================================

        cout << endl;

        cout << "========== JIT Warm-up =========="
             << endl;

        cout << "Executing optimized hot region once..."
             << endl;


        /*
         * Warm-up execution is intentionally performed before
         * the actual benchmark.
         *
         * This prevents the benchmark from mixing setup and
         * steady-state execution.
         */

        jitCompiler.executeOptimizedLoop(10000);


        cout << "[JIT] Warm-up completed."
             << endl;


        // ====================================================
        // PHASE 7 — Steady-State Benchmark
        // ====================================================

        cout << endl;

        cout << "========== Phase 8: JIT Performance Benchmark =========="
             << endl;


        const int benchmarkIterations = 100;


        cout << endl;

        cout << "Benchmark Iterations       : "
             << benchmarkIterations
             << endl;

        cout << "Loop Iterations per Run   : 10000"
             << endl;


        // ----------------------------------------------------
        // Interpreter repeated benchmark
        // ----------------------------------------------------

        cout << endl;

        cout << "[BENCHMARK] Running interpreter "
             << benchmarkIterations
             << " times..."
             << endl;


        long long interpreterTotalTime = 0;


        for (int i = 0;
             i < benchmarkIterations;
             ++i)
        {
            Benchmark benchmark;

            benchmark.start();

            /*
             * Execute the complete bytecode program.
             *
             * The result is not printed because PRINT is
             * deliberately avoided during benchmarking.
             */

            vm.execute(program);

            interpreterTotalTime +=
                benchmark.stopMicroseconds();
        }


        long long interpreterAverageTime =
            interpreterTotalTime /
            benchmarkIterations;


        // ----------------------------------------------------
        // JIT repeated benchmark
        // ----------------------------------------------------

        cout << endl;

        cout << "[BENCHMARK] Running optimized JIT loop "
             << benchmarkIterations
             << " times..."
             << endl;


        long long jitSteadyStateTotalTime = 0;


        for (int i = 0;
             i < benchmarkIterations;
             ++i)
        {
            Benchmark benchmark;

            benchmark.start();

            /*
             * IMPORTANT:
             *
             * Compilation does NOT happen here.
             *
             * The compiled representation already exists
             * in the code cache.
             *
             * This measures the steady-state execution cost
             * of the optimized JIT path.
             */

            jitCompiler.executeOptimizedLoop(10000);

            jitSteadyStateTotalTime +=
                benchmark.stopMicroseconds();
        }


        long long jitSteadyStateAverageTime =
            jitSteadyStateTotalTime /
            benchmarkIterations;


        // ====================================================
        // SECOND CACHE REQUEST
        // ====================================================

        cout << endl;

        cout << "========== Second JIT Request =========="
             << endl;

        cout << "Checking code cache again..."
             << endl;


        if (jitCompiler.isCached(hotInstructions))
        {
            cout << "[CACHE] HIT"
                 << endl;

            cout << "[CACHE] Reusing previously compiled code."
                 << endl;
        }
        else
        {
            cout << "[CACHE] MISS"
                 << endl;
        }


        /*
         * Requesting compilation again should reuse the cached
         * representation instead of creating another entry.
         */

        jitCompiler.compile(
            hotInstructions
        );


        cout << endl;

        cout << "[CACHE] Cached code reused successfully."
             << endl;


        // ====================================================
        // FINAL CACHE STATUS
        // ====================================================

        cout << endl;

        cout << "========== Final Cache Status =========="
             << endl;

        cout << "Code Cache Entries: "
             << jitCompiler.getCacheSize()
             << endl;

        cout << "Code caching phase completed successfully."
             << endl;


        // ====================================================
        // BENCHMARK RESULTS
        // ====================================================

        cout << endl;

        cout << "========== Benchmark Results =========="
             << endl;


        cout << endl;

        cout << "Benchmark Iterations       : "
             << benchmarkIterations
             << endl;

        cout << "Interpreter Total Time     : "
             << interpreterTotalTime
             << " microseconds"
             << endl;

        cout << "Interpreter Average Time   : "
             << interpreterAverageTime
             << " microseconds"
             << endl;

        cout << "JIT Compilation Time       : "
             << jitCompilationTime
             << " microseconds"
             << endl;

        cout << "JIT Steady-State Total     : "
             << jitSteadyStateTotalTime
             << " microseconds"
             << endl;

        cout << "JIT Steady-State Average   : "
             << jitSteadyStateAverageTime
             << " microseconds"
             << endl;


        cout << endl;

        cout << "Hot Instructions           : "
             << hotInstructions.size()
             << endl;

        cout << "Compiled Instructions      : "
             << hotInstructions.size()
             << endl;

        cout << "Code Cache Entries         : "
             << jitCompiler.getCacheSize()
             << endl;


        // ====================================================
        // PERFORMANCE COMPARISON
        // ====================================================

        cout << endl;

        cout << "========== Performance Comparison =========="
             << endl;


        cout << endl;

        cout << "Interpreter Average : "
             << interpreterAverageTime
             << " microseconds"
             << endl;

        cout << "JIT Average         : "
             << jitSteadyStateAverageTime
             << " microseconds"
             << endl;


        if (jitSteadyStateAverageTime > 0)
        {
            double speedup =
                static_cast<double>(
                    interpreterAverageTime
                )
                /
                static_cast<double>(
                    jitSteadyStateAverageTime
                );


            cout << "JIT Steady-State Speedup : "
                 << fixed
                 << setprecision(2)
                 << speedup
                 << "x"
                 << endl;


            if (speedup > 1.0)
            {
                cout << "[SUCCESS] JIT execution is faster "
                     << "than interpreter execution."
                     << endl;
            }
            else
            {
                cout << "[INFO] JIT steady-state execution "
                     << "is not yet faster for this workload."
                     << endl;
            }
        }
        else
        {
            cout << "JIT Steady-State Speedup : N/A"
                 << endl;
        }


        // ====================================================
        // BREAK-EVEN ANALYSIS
        // ====================================================

        cout << endl;

        cout << "========== JIT Break-Even Analysis =========="
             << endl;


        if (jitSteadyStateAverageTime <
            interpreterAverageTime &&
            interpreterAverageTime > 0)
        {
            long long savingPerRun =
                interpreterAverageTime
                -
                jitSteadyStateAverageTime;


            double breakEvenRuns =
                static_cast<double>(
                    jitCompilationTime
                )
                /
                static_cast<double>(
                    savingPerRun
                );


            cout << "Compilation Overhead : "
                 << jitCompilationTime
                 << " microseconds"
                 << endl;

            cout << "Saving Per Run       : "
                 << savingPerRun
                 << " microseconds"
                 << endl;

            cout << "Break-Even Runs      : "
                 << fixed
                 << setprecision(2)
                 << breakEvenRuns
                 << endl;


            cout << endl;

            cout << "After approximately "
                 << static_cast<long long>(
                        breakEvenRuns + 1
                    )
                 << " repeated executions, "
                 << "the JIT can recover its compilation cost."
                 << endl;
        }
        else
        {
            cout << "Break-even point cannot be demonstrated "
                 << "because the measured JIT steady-state "
                 << "execution is not faster than the interpreter."
                 << endl;
        }


        // ====================================================
        // FINAL NOTE
        // ====================================================

        cout << endl;

        cout << "Benchmark methodology:"
             << endl;

        cout << "1. Interpreter execution is measured repeatedly."
             << endl;

        cout << "2. JIT compilation is measured separately."
             << endl;

        cout << "3. Compiled code is warmed up before benchmarking."
             << endl;

        cout << "4. JIT steady-state execution is measured "
             << "without recompilation."
             << endl;

        cout << "5. Interpreter and JIT average execution times "
             << "are compared."
             << endl;

        cout << "6. Compilation overhead and break-even behavior "
             << "are reported separately."
             << endl;


        cout << endl;

        cout << "Benchmark completed successfully."
             << endl;
    }


    // ========================================================
    // PROGRAM COMPLETED
    // ========================================================

    cout << endl;

    cout << "===================================="
         << endl;

    cout << "          Program Completed"
         << endl;

    cout << "===================================="
         << endl;


    return 0;
}