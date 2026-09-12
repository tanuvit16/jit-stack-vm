// // // #include "JITCompiler.h"

// // // #include <iostream>

// // // JITCompiler::JITCompiler()
// // //     : compiled(false),
// // //       compiledInstructionCount(0) {
// // // }


// // // void JITCompiler::compile(
// // //     const std::vector<Instruction>& instructions) {

// // //     compiledInstructionCount = instructions.size();

// // //     if (compiledInstructionCount == 0) {
// // //         compiled = false;
// // //         return;
// // //     }

// // //     compiled = true;

// // //     std::cout << "\n[JIT] Compilation started..." << std::endl;

// // //     std::cout << "[JIT] Compiling "
// // //               << compiledInstructionCount
// // //               << " hot instruction(s)..."
// // //               << std::endl;

// // //     std::cout << "[JIT] Compilation completed."
// // //               << std::endl;
// // // }


// // // void JITCompiler::printCompilationInfo() const {

// // //     std::cout << "\n========== JIT Compiler =========="
// // //               << std::endl;

// // //     if (!compiled) {

// // //         std::cout << "JIT Status: NOT COMPILED"
// // //                   << std::endl;

// // //         return;
// // //     }

// // //     std::cout << "JIT Status: COMPILED"
// // //               << std::endl;

// // //     std::cout << "Hot instructions compiled: "
// // //               << compiledInstructionCount
// // //               << std::endl;

// // //     std::cout << "Compiled code is ready for the next execution phase."
// // //               << std::endl;
// // // }


// // // bool JITCompiler::isCompiled() const {
// // //     return compiled;
// // // }




























// // #include "JITCompiler.h"

// // #include <iostream>
// // #include <stack>

// // JITCompiler::JITCompiler()
// //     : compiled(false),
// //       compiledExecutionCount(0) {
// // }


// // void JITCompiler::compile(
// //     const std::vector<Instruction>& instructions) {

// //     compiledCode.clear();
// //     compiledExecutionCount = 0;

// //     if (instructions.empty()) {
// //         compiled = false;
// //         return;
// //     }

// //     std::cout << "\n[JIT] Compilation started..."
// //               << std::endl;

// //     for (std::size_t i = 0; i < instructions.size(); ++i) {

// //         CompiledInstruction compiledInstruction;

// //         compiledInstruction.opcode =
// //             instructions[i].opcode;

// //         compiledInstruction.operand =
// //             instructions[i].operand;

// //         compiledCode.push_back(compiledInstruction);
// //     }

// //     compiled = true;

// //     std::cout << "[JIT] Compiling "
// //               << compiledCode.size()
// //               << " hot instruction(s)..."
// //               << std::endl;

// //     std::cout << "[JIT] Compilation completed."
// //               << std::endl;
// // }


// // void JITCompiler::execute() {

// //     if (!compiled) {

// //         std::cout << "[JIT] No compiled code available."
// //                   << std::endl;

// //         return;
// //     }

// //     std::cout << "\n========== JIT Execution =========="
// //               << std::endl;

// //     std::cout << "JIT Status: ACTIVE"
// //               << std::endl;

// //     std::cout << "Compiled instructions: "
// //               << compiledCode.size()
// //               << std::endl;

// //     std::cout << "Executing compiled code..."
// //               << std::endl;


// //     std::stack<long long> stack;


// //     for (std::size_t i = 0;
// //          i < compiledCode.size();
// //          ++i) {

// //         const CompiledInstruction& instruction =
// //             compiledCode[i];

// //         compiledExecutionCount++;


// //         switch (instruction.opcode) {

// //             case OpCode::PUSH:
// //                 stack.push(instruction.operand);
// //                 break;


// //             case OpCode::DUP:

// //                 if (!stack.empty()) {
// //                     stack.push(stack.top());
// //                 }

// //                 break;


// //             case OpCode::ADD:

// //                 if (stack.size() >= 2) {

// //                     long long a = stack.top();
// //                     stack.pop();

// //                     long long b = stack.top();
// //                     stack.pop();

// //                     stack.push(b + a);
// //                 }

// //                 break;


// //             case OpCode::SUB:

// //                 if (stack.size() >= 2) {

// //                     long long a = stack.top();
// //                     stack.pop();

// //                     long long b = stack.top();
// //                     stack.pop();

// //                     stack.push(b - a);
// //                 }

// //                 break;


// //             case OpCode::MUL:

// //                 if (stack.size() >= 2) {

// //                     long long a = stack.top();
// //                     stack.pop();

// //                     long long b = stack.top();
// //                     stack.pop();

// //                     stack.push(b * a);
// //                 }

// //                 break;


// //             case OpCode::DIV:

// //                 if (stack.size() >= 2) {

// //                     long long a = stack.top();
// //                     stack.pop();

// //                     long long b = stack.top();
// //                     stack.pop();

// //                     if (a != 0) {
// //                         stack.push(b / a);
// //                     }
// //                 }

// //                 break;


// //             default:
// //                 break;
// //         }
// //     }


// //     std::cout << "[JIT] Compiled execution completed."
// //               << std::endl;

// //     std::cout << "[JIT] Compiled operations executed: "
// //               << compiledExecutionCount
// //               << std::endl;
// // }


// // void JITCompiler::printCompilationInfo() const {

// //     std::cout << "\n========== JIT Compiler =========="
// //               << std::endl;

// //     if (!compiled) {

// //         std::cout << "JIT Status: NOT COMPILED"
// //                   << std::endl;

// //         return;
// //     }

// //     std::cout << "JIT Status: COMPILED"
// //               << std::endl;

// //     std::cout << "Compiled instructions: "
// //               << compiledCode.size()
// //               << std::endl;

// //     std::cout << "Compiled code representation created."
// //               << std::endl;
// // }


// // bool JITCompiler::isCompiled() const {
// //     return compiled;
// // }























// #include "JITCompiler.h"

// #include <iostream>
// #include <stack>
// #include <map>

// JITCompiler::JITCompiler()
//     : compiled(false),
//       compiledExecutionCount(0) {
// }


// void JITCompiler::compile(
//     const std::vector<std::pair<std::size_t, Instruction> >&
//     instructions) {

//     compiledCode.clear();

//     compiledExecutionCount = 0;

//     if (instructions.empty()) {

//         compiled = false;

//         return;
//     }


//     std::cout << "\n[JIT] Compilation started..."
//               << std::endl;


//     for (std::size_t i = 0;
//          i < instructions.size();
//          ++i) {

//         CompiledInstruction compiledInstruction;

//         compiledInstruction.originalIndex =
//             instructions[i].first;

//         compiledInstruction.opcode =
//             instructions[i].second.opcode;

//         compiledInstruction.operand =
//             instructions[i].second.operand;

//         compiledCode.push_back(
//             compiledInstruction
//         );
//     }


//     compiled = true;


//     std::cout << "[JIT] Compiling "
//               << compiledCode.size()
//               << " hot instruction(s)..."
//               << std::endl;


//     std::cout << "[JIT] Preserving original instruction indices."
//               << std::endl;


//     std::cout << "[JIT] Compilation completed."
//               << std::endl;
// }


// void JITCompiler::execute() {

//     if (!compiled) {

//         std::cout << "[JIT] No compiled code available."
//                   << std::endl;

//         return;
//     }


//     std::cout << "\n========== JIT Execution =========="
//               << std::endl;

//     std::cout << "JIT Status: ACTIVE"
//               << std::endl;

//     std::cout << "Compiled instructions: "
//               << compiledCode.size()
//               << std::endl;

//     std::cout << "Executing compiled hot region..."
//               << std::endl;


//     std::stack<long long> stack;


//     /*
//      * Map original instruction index
//      * to its position inside compiledCode.
//      */
//     std::map<std::size_t, std::size_t> indexMap;


//     for (std::size_t i = 0;
//          i < compiledCode.size();
//          ++i) {

//         indexMap[
//             compiledCode[i].originalIndex
//         ] = i;
//     }


//     std::size_t pc = 0;


//     /*
//      * Safety limit prevents an accidental
//      * infinite loop during the demonstration.
//      */
//     unsigned long long executionLimit = 1000;


//     while (pc < compiledCode.size() &&
//            compiledExecutionCount < executionLimit) {

//         const CompiledInstruction& instruction =
//             compiledCode[pc];


//         compiledExecutionCount++;


//         switch (instruction.opcode) {

//             case OpCode::PUSH:

//                 stack.push(
//                     instruction.operand
//                 );

//                 pc++;

//                 break;


//             case OpCode::DUP:

//                 if (!stack.empty()) {

//                     stack.push(
//                         stack.top()
//                     );
//                 }

//                 pc++;

//                 break;


//             case OpCode::ADD:

//                 if (stack.size() >= 2) {

//                     long long a =
//                         stack.top();

//                     stack.pop();

//                     long long b =
//                         stack.top();

//                     stack.pop();

//                     stack.push(b + a);
//                 }

//                 pc++;

//                 break;


//             case OpCode::SUB:

//                 if (stack.size() >= 2) {

//                     long long a =
//                         stack.top();

//                     stack.pop();

//                     long long b =
//                         stack.top();

//                     stack.pop();

//                     stack.push(b - a);
//                 }

//                 pc++;

//                 break;


//             case OpCode::MUL:

//                 if (stack.size() >= 2) {

//                     long long a =
//                         stack.top();

//                     stack.pop();

//                     long long b =
//                         stack.top();

//                     stack.pop();

//                     stack.push(b * a);
//                 }

//                 pc++;

//                 break;


//             case OpCode::DIV:

//                 if (stack.size() >= 2) {

//                     long long a =
//                         stack.top();

//                     stack.pop();

//                     long long b =
//                         stack.top();

//                     stack.pop();

//                     if (a != 0) {

//                         stack.push(b / a);
//                     }
//                 }

//                 pc++;

//                 break;


//             case OpCode::JUMP:

//             {
//                 std::size_t target =
//                     static_cast<std::size_t>(
//                         instruction.operand
//                     );


//                 std::map<std::size_t,
//                          std::size_t>::iterator it =
//                     indexMap.find(target);


//                 if (it != indexMap.end()) {

//                     pc = it->second;

//                 }
//                 else {

//                     /*
//                      * Target is outside the
//                      * compiled region.
//                      */
//                     pc = compiledCode.size();
//                 }

//                 break;
//             }


//             case OpCode::JUMP_IF_ZERO:

//             {
//                 bool shouldJump = false;


//                 if (!stack.empty()) {

//                     long long value =
//                         stack.top();

//                     stack.pop();

//                     if (value == 0) {

//                         shouldJump = true;
//                     }
//                 }


//                 if (shouldJump) {

//                     std::size_t target =
//                         static_cast<std::size_t>(
//                             instruction.operand
//                         );


//                     std::map<std::size_t,
//                              std::size_t>::iterator it =
//                         indexMap.find(target);


//                     if (it != indexMap.end()) {

//                         pc = it->second;

//                     }
//                     else {

//                         /*
//                          * Target is outside the
//                          * compiled region.
//                          */
//                         pc = compiledCode.size();
//                     }

//                 }
//                 else {

//                     pc++;
//                 }

//                 break;
//             }


//             default:

//                 pc++;

//                 break;
//         }
//     }


//     std::cout << "[JIT] Compiled execution completed."
//               << std::endl;

//     std::cout << "[JIT] Compiled operations executed: "
//               << compiledExecutionCount
//               << std::endl;
// }


// void JITCompiler::printCompilationInfo() const {

//     std::cout << "\n========== JIT Compiler =========="
//               << std::endl;


//     if (!compiled) {

//         std::cout << "JIT Status: NOT COMPILED"
//                   << std::endl;

//         return;
//     }


//     std::cout << "JIT Status: COMPILED"
//               << std::endl;


//     std::cout << "Compiled instructions: "
//               << compiledCode.size()
//               << std::endl;


//     std::cout << "Original instruction indices preserved."
//               << std::endl;


//     std::cout << "Compiled code representation created."
//               << std::endl;
// }


// bool JITCompiler::isCompiled() const {

//     return compiled;
// }




















#include "JITCompiler.h"

#include <iostream>
#include <stack>
#include <map>

JITCompiler::JITCompiler()
    : compiled(false),
      compiledExecutionCount(0),
      currentCacheKey(0) {
}


// ============================================================
// Phase 7: Check whether a hot region already exists in cache
// ============================================================

bool JITCompiler::isCached(
    const std::vector<
        std::pair<std::size_t, Instruction>
    >& instructions
) const {

    if (instructions.empty()) {
        return false;
    }

    std::size_t key = instructions[0].first;

    return codeCache.find(key) != codeCache.end();
}


// ============================================================
// Phase 6 + Phase 7: Compile or reuse compiled code
// ============================================================

void JITCompiler::compile(
    const std::vector<
        std::pair<std::size_t, Instruction>
    >& instructions
) {

    if (instructions.empty()) {

        compiled = false;

        return;
    }


    /*
     * Use the first original instruction index
     * as the cache key.
     */
    std::size_t cacheKey =
        instructions[0].first;

    currentCacheKey = cacheKey;


    // --------------------------------------------------------
    // Check Code Cache
    // --------------------------------------------------------

    std::map<
        std::size_t,
        std::vector<CompiledInstruction>
    >::iterator cached =
        codeCache.find(cacheKey);


    if (cached != codeCache.end()) {

        /*
         * CACHE HIT
         */
        std::cout << "\n[JIT] Code cache HIT."
                  << std::endl;

        std::cout << "[JIT] Reusing previously compiled code."
                  << std::endl;


        compiledCode =
            cached->second;

        compiled = true;

        return;
    }


    /*
     * CACHE MISS
     */
    std::cout << "\n[JIT] Code cache MISS."
              << std::endl;

    std::cout << "[JIT] No compiled version found."
              << std::endl;


    std::cout << "\n[JIT] Compilation started..."
              << std::endl;


    compiledCode.clear();

    compiledExecutionCount = 0;


    // --------------------------------------------------------
    // Compile instructions
    // --------------------------------------------------------

    for (std::size_t i = 0;
         i < instructions.size();
         ++i) {

        CompiledInstruction compiledInstruction;


        compiledInstruction.originalIndex =
            instructions[i].first;


        compiledInstruction.opcode =
            instructions[i].second.opcode;


        compiledInstruction.operand =
            instructions[i].second.operand;


        compiledCode.push_back(
            compiledInstruction
        );
    }


    compiled = true;


    std::cout << "[JIT] Compiling "
              << compiledCode.size()
              << " hot instruction(s)..."
              << std::endl;


    std::cout << "[JIT] Preserving original instruction indices."
              << std::endl;


    std::cout << "[JIT] Compilation completed."
              << std::endl;


    // --------------------------------------------------------
    // Store compiled code in cache
    // --------------------------------------------------------

    codeCache[cacheKey] =
        compiledCode;


    std::cout << "[JIT] Compiled code stored in code cache."
              << std::endl;
}


// ============================================================
// Phase 6: Execute compiled code
// ============================================================

void JITCompiler::execute() {

    if (!compiled) {

        std::cout << "[JIT] No compiled code available."
                  << std::endl;

        return;
    }


    std::cout << "\n========== JIT Execution =========="
              << std::endl;


    std::cout << "JIT Status: ACTIVE"
              << std::endl;


    std::cout << "Compiled instructions: "
              << compiledCode.size()
              << std::endl;


    std::cout << "Executing compiled hot region..."
              << std::endl;


    std::stack<long long> stack;


    /*
     * Map original bytecode index
     * to compiled-code index.
     */
    std::map<
        std::size_t,
        std::size_t
    > indexMap;


    for (std::size_t i = 0;
         i < compiledCode.size();
         ++i) {

        indexMap[
            compiledCode[i].originalIndex
        ] = i;
    }


    std::size_t pc = 0;


    unsigned long long executionLimit = 1000;


    while (
        pc < compiledCode.size() &&
        compiledExecutionCount < executionLimit
    ) {

        const CompiledInstruction& instruction =
            compiledCode[pc];


        compiledExecutionCount++;


        switch (instruction.opcode) {


            case OpCode::PUSH:

                stack.push(
                    instruction.operand
                );

                pc++;

                break;


            case OpCode::DUP:

                if (!stack.empty()) {

                    stack.push(
                        stack.top()
                    );
                }

                pc++;

                break;


            case OpCode::ADD:

                if (stack.size() >= 2) {

                    long long a =
                        stack.top();

                    stack.pop();


                    long long b =
                        stack.top();

                    stack.pop();


                    stack.push(b + a);
                }

                pc++;

                break;


            case OpCode::SUB:

                if (stack.size() >= 2) {

                    long long a =
                        stack.top();

                    stack.pop();


                    long long b =
                        stack.top();

                    stack.pop();


                    stack.push(b - a);
                }

                pc++;

                break;


            case OpCode::MUL:

                if (stack.size() >= 2) {

                    long long a =
                        stack.top();

                    stack.pop();


                    long long b =
                        stack.top();

                    stack.pop();


                    stack.push(b * a);
                }

                pc++;

                break;


            case OpCode::DIV:

                if (stack.size() >= 2) {

                    long long a =
                        stack.top();

                    stack.pop();


                    long long b =
                        stack.top();

                    stack.pop();


                    if (a != 0) {

                        stack.push(b / a);
                    }
                }

                pc++;

                break;


            case OpCode::JUMP:
            {
                std::size_t target =
                    static_cast<std::size_t>(
                        instruction.operand
                    );


                std::map<
                    std::size_t,
                    std::size_t
                >::iterator it =
                    indexMap.find(target);


                if (it != indexMap.end()) {

                    pc = it->second;

                }
                else {

                    pc =
                        compiledCode.size();
                }

                break;
            }


            case OpCode::JUMP_IF_ZERO:
            {
                bool shouldJump = false;


                if (!stack.empty()) {

                    long long value =
                        stack.top();

                    stack.pop();


                    if (value == 0) {

                        shouldJump = true;
                    }
                }


                if (shouldJump) {

                    std::size_t target =
                        static_cast<std::size_t>(
                            instruction.operand
                        );


                    std::map<
                        std::size_t,
                        std::size_t
                    >::iterator it =
                        indexMap.find(target);


                    if (it != indexMap.end()) {

                        pc = it->second;

                    }
                    else {

                        pc =
                            compiledCode.size();
                    }

                }
                else {

                    pc++;
                }

                break;
            }


            default:

                pc++;

                break;
        }
    }


    std::cout
        << "[JIT] Compiled execution completed."
        << std::endl;


    std::cout
        << "[JIT] Compiled operations executed: "
        << compiledExecutionCount
        << std::endl;
}


// ============================================================
// Display JIT information
// ============================================================

void JITCompiler::printCompilationInfo() const {

    std::cout
        << "\n========== JIT Compiler =========="
        << std::endl;


    if (!compiled) {

        std::cout
            << "JIT Status: NOT COMPILED"
            << std::endl;

        return;
    }


    std::cout
        << "JIT Status: COMPILED"
        << std::endl;


    std::cout
        << "Compiled instructions: "
        << compiledCode.size()
        << std::endl;


    std::cout
        << "Code cache entries: "
        << codeCache.size()
        << std::endl;


    std::cout
        << "Original instruction indices preserved."
        << std::endl;
}


// ============================================================
// Getters
// ============================================================

bool JITCompiler::isCompiled() const {

    return compiled;
}


std::size_t JITCompiler::getCacheSize() const {

    return codeCache.size();
}