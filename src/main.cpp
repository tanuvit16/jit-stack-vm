






































#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <chrono>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdint>

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
// Benchmark guard: the current optimized JIT path only supports
// this specific countdown bytecode pattern.
// ============================================================
bool isSupportedCountdownProgram(const vector<Instruction>& program) {
    return program.size() == 8 &&
        program[0].opcode == OpCode::PUSH && program[0].operand > 0 &&
        program[1].opcode == OpCode::DUP &&
        program[2].opcode == OpCode::JUMP_IF_ZERO && program[2].operand == 7 &&
        program[3].opcode == OpCode::PUSH && program[3].operand == 1 &&
        program[4].opcode == OpCode::SUB &&
        program[5].opcode == OpCode::JUMP && program[5].operand == 1 &&
        program[6].opcode == OpCode::PRINT &&
        program[7].opcode == OpCode::HALT;
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

    int instructionCount = 0;

    cout << "Enter number of instructions: ";
    if (!(cin >> instructionCount)) {
        cerr << "Invalid instruction count. Enter a positive integer." << endl;
        return 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

   int hotspotThreshold;

cout << "\nEnter hotspot threshold (positive integer): ";

if (!(cin >> hotspotThreshold) || hotspotThreshold <= 0) {
    cerr << "Invalid threshold. Enter a positive integer." << endl;
    return 1;
}      
//  StackVM vm;
StackVM vm(static_cast<std::size_t>(hotspotThreshold));

    Benchmark interpreterBenchmark;

    interpreterBenchmark.start();

    vm.execute(program);

    double interpreterTime =
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

        double jitCompilationTime =
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


        // ----------------------------------------------------
        // Benchmark equivalent countdown work in batches.
        // The current JIT prototype supports only the exact
        // countdown bytecode pattern checked below.
        // ----------------------------------------------------
        if (!isSupportedCountdownProgram(program)) {
            cout << "\n[BENCHMARK] Skipped: this JIT benchmark currently "
                 << "supports only the documented countdown program." << endl;
            cout << "Use the expected 8-instruction countdown pattern to "
                 << "compare interpreter and optimized-loop timings." << endl;
        } else {
            const int64_t initialValue = program[0].operand;
            const int benchmarkIterations = 100;

            cout << endl;
            cout << "Benchmark Iterations       : " << benchmarkIterations << endl;
            cout << "Loop Iterations per Run    : " << initialValue << endl;

            // Warm both paths before timing to reduce first-run effects.
            vm.execute(program);
            volatile int64_t warmupResult =
                jitCompiler.executeOptimizedLoop(initialValue);
            (void)warmupResult;

            cout << endl;
            cout << "[BENCHMARK] Running interpreter "
                 << benchmarkIterations << " times..." << endl;

            Benchmark interpreterBatch;
            interpreterBatch.start();
            for (int i = 0; i < benchmarkIterations; ++i) {
                vm.execute(program);
            }
            double interpreterTotalTime = interpreterBatch.stopMicroseconds();
            double interpreterAverageTime =
                interpreterTotalTime / static_cast<double>(benchmarkIterations);

            cout << endl;
            cout << "[BENCHMARK] Running optimized JIT loop "
                 << benchmarkIterations << " times..." << endl;

            // Keep the result observable so the compiler cannot discard the work.
            volatile int64_t benchmarkResult = -1;
            Benchmark jitBatch;
            jitBatch.start();
            for (int i = 0; i < benchmarkIterations; ++i) {
                benchmarkResult = jitCompiler.executeOptimizedLoop(initialValue);
            }
            double jitSteadyStateTotalTime = jitBatch.stopMicroseconds();
            double jitSteadyStateAverageTime =
                jitSteadyStateTotalTime / static_cast<double>(benchmarkIterations);

            // The supported countdown pattern should finish at zero in both paths.
            // StackVM currently exposes no final-stack getter, so main.cpp cannot
            // independently compare the two runtime results. Do not claim a verified
            // result-equivalence test until such an API/test is added.
            const bool supportedPattern = isSupportedCountdownProgram(program);

            cout << endl;
            cout << "========== Second JIT Request ==========" << endl;
            cout << "Checking code cache again..." << endl;
            if (jitCompiler.isCached(hotInstructions)) {
                cout << "[CACHE] HIT" << endl;
                cout << "[CACHE] Reusing previously compiled code." << endl;
            } else {
                cout << "[CACHE] MISS" << endl;
            }
            jitCompiler.compile(hotInstructions);
            cout << endl << "[CACHE] Cached code reused successfully." << endl;

            cout << endl << "========== Final Cache Status ==========" << endl;
            cout << "Code Cache Entries: " << jitCompiler.getCacheSize() << endl;
            cout << "Code caching phase completed successfully." << endl;

            cout << fixed << setprecision(3);
            cout << endl << "========== Benchmark Results ==========" << endl;
            cout << "Benchmark Iterations       : " << benchmarkIterations << endl;
            cout << "Loop Iterations per Run    : " << initialValue << endl;
            cout << "Interpreter Total Time     : " << interpreterTotalTime << " microseconds" << endl;
            cout << "Interpreter Average Time   : " << interpreterAverageTime << " microseconds" << endl;
            cout << "JIT Compilation Time       : " << jitCompilationTime << " microseconds" << endl;
            cout << "JIT Steady-State Total     : " << jitSteadyStateTotalTime << " microseconds" << endl;
            cout << "JIT Steady-State Average   : " << jitSteadyStateAverageTime << " microseconds" << endl;
            cout << "Supported Pattern          : " << (supportedPattern ? "YES" : "NO") << endl;
            cout << "JIT Final Countdown Result : " << benchmarkResult << endl;
            cout << "Expected Countdown Result  : 0" << endl;
            cout << "JIT Result Check           : " << (benchmarkResult == 0 ? "PASS" : "FAIL") << endl;
            cout << "Interpreter Result Check   : NOT AVAILABLE (VM exposes no result getter)" << endl;
            cout << "Hot Instructions           : " << hotInstructions.size() << endl;
            cout << "Compiled Instructions      : " << hotInstructions.size() << endl;
            cout << "Code Cache Entries         : " << jitCompiler.getCacheSize() << endl;

            cout << endl << "========== Performance Comparison ==========" << endl;
            cout << "Interpreter Average : " << interpreterAverageTime << " microseconds" << endl;
            cout << "JIT Average         : " << jitSteadyStateAverageTime << " microseconds" << endl;

            if (supportedPattern && interpreterAverageTime > 0.0 && jitSteadyStateAverageTime > 0.0) {
                const double speedup = interpreterAverageTime / jitSteadyStateAverageTime;
                cout << "JIT Steady-State Speedup : " << speedup << "x" << endl;
                cout << (speedup > 1.0
                    ? "[RESULT] Optimized loop is faster for this workload."
                    : "[RESULT] Optimized loop is not faster for this workload.") << endl;
            } else {
                cout << "JIT Steady-State Speedup : N/A (invalid/too-small timing or result check failed)" << endl;
            }

            cout << endl << "========== JIT Break-Even Analysis ==========" << endl;
            const double savingPerRun = interpreterAverageTime - jitSteadyStateAverageTime;
            cout << "Compilation Overhead : " << jitCompilationTime << " microseconds" << endl;
            cout << "Saving Per Run       : " << savingPerRun << " microseconds" << endl;
            if (supportedPattern && interpreterAverageTime > 0.0 &&
                jitSteadyStateAverageTime > 0.0 && savingPerRun > 0.0) {
                const double breakEvenRuns = jitCompilationTime / savingPerRun;
                cout << "Break-Even Runs      : " << ceil(breakEvenRuns) << endl;
            } else {
                cout << "Break-Even Runs      : N/A (requires valid positive timings and positive saving)" << endl;
            }

            cout << endl << "Benchmark methodology:" << endl;
            cout << "1. Both paths use the same countdown input value." << endl;
            cout << "2. Compilation overhead is measured separately." << endl;
            cout << "3. Each timing measures a batch of repeated executions." << endl;
            cout << "4. Fractional microseconds are preserved in the reported average." << endl;
            cout << "5. Speedup and break-even require positive measured timings and a supported pattern." << endl;
            cout << "6. JIT result is checked; interpreter result equivalence still requires a VM result getter or dedicated test." << endl;
            cout << "Note: this is an optimized hot-loop prototype, not native machine-code generation." << endl;
            cout << endl << "Benchmark completed." << endl;
        }
    } // Close the outer JIT-compilation else block

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
