// // // // // // // #ifndef JIT_COMPILER_H
// // // // // // // #define JIT_COMPILER_H

// // // // // // // #include <vector>
// // // // // // // #include "../bytecode/Instruction.h"

// // // // // // // class JITCompiler {
// // // // // // // public:

// // // // // // //     JITCompiler();

// // // // // // //     // Compile a sequence of hot bytecode instructions
// // // // // // //     void compile(const std::vector<Instruction>& instructions);

// // // // // // //     // Display information about the compiled code
// // // // // // //     void printCompilationInfo() const;

// // // // // // //     // Check whether compilation has occurred
// // // // // // //     bool isCompiled() const;

// // // // // // // private:

// // // // // // //     bool compiled;
// // // // // // //     std::size_t compiledInstructionCount;
// // // // // // // };

// // // // // // // #endif


















// // // // // // #ifndef JIT_COMPILER_H
// // // // // // #define JIT_COMPILER_H

// // // // // // #include <vector>
// // // // // // #include "../bytecode/Instruction.h"

// // // // // // class JITCompiler {
// // // // // // public:
// // // // // //     JITCompiler();

// // // // // //     void compile(const std::vector<Instruction>& instructions);

// // // // // //     void printCompilationInfo() const;

// // // // // //     bool isCompiled() const;

// // // // // // private:
// // // // // //     bool compiled;
// // // // // //     std::size_t compiledInstructionCount;
// // // // // // };

// // // // // // #endif





















// // // // // #ifndef JIT_COMPILER_H
// // // // // #define JIT_COMPILER_H

// // // // // #include <vector>
// // // // // #include "../bytecode/Instruction.h"

// // // // // class JITCompiler {
// // // // // public:

// // // // //     JITCompiler();

// // // // //     // Compile hot instructions
// // // // //     void compile(const std::vector<Instruction>& instructions);

// // // // //     // Execute the compiled representation
// // // // //     void execute();

// // // // //     // Display compilation information
// // // // //     void printCompilationInfo() const;

// // // // //     bool isCompiled() const;

// // // // // private:

// // // // //     struct CompiledInstruction {
// // // // //         OpCode opcode;
// // // // //         long long operand;
// // // // //     };

// // // // //     std::vector<CompiledInstruction> compiledCode;

// // // // //     bool compiled;
// // // // //     unsigned long long compiledExecutionCount;
// // // // // };

// // // // // #endif




















// // // // #ifndef JIT_COMPILER_H
// // // // #define JIT_COMPILER_H

// // // // #include <vector>
// // // // #include "../bytecode/Instruction.h"

// // // // class JITCompiler {
// // // // public:

// // // //     JITCompiler();

// // // //     // Compile hot instructions while preserving
// // // //     // their original program indices.
// // // //     void compile(
// // // //         const std::vector<std::pair<std::size_t, Instruction> >&
// // // //         instructions
// // // //     );

// // // //     // Execute the compiled hot region.
// // // //     void execute();

// // // //     // Display compilation information.
// // // //     void printCompilationInfo() const;

// // // //     bool isCompiled() const;

// // // // private:

// // // //     struct CompiledInstruction {

// // // //         std::size_t originalIndex;

// // // //         OpCode opcode;

// // // //         long long operand;
// // // //     };

// // // //     std::vector<CompiledInstruction> compiledCode;

// // // //     bool compiled;

// // // //     unsigned long long compiledExecutionCount;
// // // // };

// // // // #endif






































// // // #ifndef JIT_COMPILER_H
// // // #define JIT_COMPILER_H

// // // #include <vector>
// // // #include <map>
// // // #include <cstddef>

// // // #include "../bytecode/Instruction.h"

// // // class JITCompiler {
// // // public:

// // //     JITCompiler();

// // //     void compile(
// // //         const std::vector<
// // //             std::pair<std::size_t, Instruction>
// // //         >& instructions
// // //     );

// // //     void execute();

// // //     void printCompilationInfo() const;

// // //     bool isCompiled() const;

// // //     // Phase 7: Code Cache
// // //     bool isCached(
// // //         const std::vector<
// // //             std::pair<std::size_t, Instruction>
// // //         >& instructions
// // //     ) const;

// // //     std::size_t getCacheSize() const;

// // // private:

// // //     struct CompiledInstruction {

// // //         std::size_t originalIndex;

// // //         OpCode opcode;

// // //         long long operand;
// // //     };


// // //     /*
// // //      * Stores compiled code.
// // //      *
// // //      * Key:
// // //      *     original starting instruction index
// // //      *
// // //      * Value:
// // //      *     compiled instruction sequence
// // //      */
// // //     std::map<
// // //         std::size_t,
// // //         std::vector<CompiledInstruction>
// // //     > codeCache;


// // //     std::vector<CompiledInstruction> compiledCode;

// // //     bool compiled;

// // //     unsigned long long compiledExecutionCount;

// // //     std::size_t currentCacheKey;
// // // };

// // // #endif















// // #ifndef JIT_COMPILER_H
// // #define JIT_COMPILER_H

// // #include <vector>
// // #include <map>
// // #include <cstddef>
// // #include <cstdint>

// // #include "../bytecode/Instruction.h"


// // class JITCompiler {

// // public:

// //     JITCompiler();


// //     // ========================================================
// //     // Phase 6 — JIT Compilation
// //     // ========================================================

// //     void compile(
// //         const std::vector<
// //             std::pair<std::size_t, Instruction>
// //         >& instructions
// //     );


// //     // ========================================================
// //     // Phase 6 — JIT Execution
// //     // ========================================================

// //  void execute(long long initialValue);


// //     // ========================================================
// //     // Information
// //     // ========================================================

// //     void printCompilationInfo() const;

// //     bool isCompiled() const;


// //     // ========================================================
// //     // Phase 7 — Code Cache
// //     // ========================================================

// //     bool isCached(
// //         const std::vector<
// //             std::pair<std::size_t, Instruction>
// //         >& instructions
// //     ) const;


// //     std::size_t getCacheSize() const;


// // private:

// //     // ========================================================
// //     // Compiled Instruction
// //     // ========================================================

// //     struct CompiledInstruction {

// //         std::size_t originalIndex;

// //         OpCode opcode;

// //         long long operand;
// //     };


// //     // ========================================================
// //     // Compiled Hot Block
// //     //
// //     // Represents a contiguous region selected for JIT
// //     // compilation.
// //     // ========================================================

// //     struct CompiledBlock {

// //         std::size_t startIndex;

// //         std::size_t endIndex;

// //         std::vector<CompiledInstruction> instructions;

// //         bool optimized;

// //         unsigned long long executionCount;


// //         CompiledBlock()
// //             : startIndex(0),
// //               endIndex(0),
// //               optimized(false),
// //               executionCount(0) {
// //         }
// //     };


// //     // ========================================================
// //     // Phase 7 — Code Cache
// //     //
// //     // Key:
// //     //     Original starting instruction index
// //     //
// //     // Value:
// //     //     Compiled hot block
// //     // ========================================================

// //     std::map<
// //         std::size_t,
// //         CompiledBlock
// //     > codeCache;


// //     // ========================================================
// //     // Currently selected compiled block
// //     // ========================================================

// //     CompiledBlock currentBlock;


// //     std::vector<CompiledInstruction> compiledCode;


// //     // ========================================================
// //     // JIT State
// //     // ========================================================

// //     bool compiled;

// //     bool optimized;


// //     unsigned long long compiledExecutionCount;


// //     std::size_t currentCacheKey;
// // };

// // #endif











































// #include "JITCompiler.h"

// #include <iostream>
// #include <vector>
// #include <map>
// #include <stdexcept>


// // ============================================================
// // Constructor
// // ============================================================

// JITCompiler::JITCompiler()
//     : compiled(false),
//       optimized(false),
//       compiledExecutionCount(0),
//       currentCacheKey(0) {
// }


// // ============================================================
// // Phase 7: Code Cache Check
// // ============================================================

// bool JITCompiler::isCached(
//     const std::vector<
//         std::pair<std::size_t, Instruction>
//     >& instructions
// ) const {

//     if (instructions.empty()) {
//         return false;
//     }

//     std::size_t key = instructions[0].first;

//     return codeCache.find(key) != codeCache.end();
// }


// // ============================================================
// // Phase 6 + Phase 7: JIT Compilation
// // ============================================================

// void JITCompiler::compile(
//     const std::vector<
//         std::pair<std::size_t, Instruction>
//     >& instructions
// ) {

//     if (instructions.empty()) {

//         compiled = false;
//         optimized = false;

//         return;
//     }


//     // --------------------------------------------------------
//     // Use the first original instruction as cache key
//     // --------------------------------------------------------

//     std::size_t cacheKey =
//         instructions[0].first;

//     currentCacheKey = cacheKey;


//     // --------------------------------------------------------
//     // Check Code Cache
//     // --------------------------------------------------------

//     std::map<
//         std::size_t,
//         CompiledBlock
//     >::iterator cached =
//         codeCache.find(cacheKey);


//     if (cached != codeCache.end()) {

//         std::cout
//             << "\n[JIT] Code cache HIT."
//             << std::endl;

//         std::cout
//             << "[JIT] Reusing previously compiled hot block."
//             << std::endl;

//         currentBlock =
//             cached->second;

//         compiledCode =
//             currentBlock.instructions;

//         compiled = true;

//         optimized =
//             currentBlock.optimized;

//         return;
//     }


//     // --------------------------------------------------------
//     // Cache MISS
//     // --------------------------------------------------------

//     std::cout
//         << "\n[JIT] Code cache MISS."
//         << std::endl;

//     std::cout
//         << "[JIT] No compiled hot block found."
//         << std::endl;


//     std::cout
//         << "\n[JIT] Compilation started..."
//         << std::endl;


//     compiledCode.clear();

//     compiledExecutionCount = 0;


//     // --------------------------------------------------------
//     // Convert hot instructions into compiled representation
//     // --------------------------------------------------------

//     for (std::size_t i = 0;
//          i < instructions.size();
//          ++i) {

//         CompiledInstruction ci;

//         ci.originalIndex =
//             instructions[i].first;

//         ci.opcode =
//             instructions[i].second.opcode;

//         ci.operand =
//             instructions[i].second.operand;

//         compiledCode.push_back(ci);
//     }


//     // --------------------------------------------------------
//     // Create Compiled Block
//     // --------------------------------------------------------

//     currentBlock =
//         CompiledBlock();


//     currentBlock.startIndex =
//         instructions.front().first;

//     currentBlock.endIndex =
//         instructions.back().first;

//     currentBlock.instructions =
//         compiledCode;

//     currentBlock.executionCount = 0;


//     // --------------------------------------------------------
//     // Detect the countdown hot-loop pattern
//     //
//     // Example:
//     //
//     // DUP
//     // JUMP_IF_ZERO 7
//     // PUSH 1
//     // SUB
//     // JUMP 1
//     //
//     // --------------------------------------------------------

//     optimized = false;


//     if (compiledCode.size() >= 5) {

//         bool hasDup =
//             compiledCode[0].opcode ==
//             OpCode::DUP;

//         bool hasConditionalJump =
//             compiledCode[1].opcode ==
//             OpCode::JUMP_IF_ZERO;

//         bool hasPush =
//             compiledCode[2].opcode ==
//             OpCode::PUSH;

//         bool hasSub =
//             compiledCode[3].opcode ==
//             OpCode::SUB;

//         bool hasJump =
//             compiledCode[4].opcode ==
//             OpCode::JUMP;


//         if (hasDup &&
//             hasConditionalJump &&
//             hasPush &&
//             hasSub &&
//             hasJump &&
//             compiledCode[2].operand == 1) {

//             optimized = true;
//         }
//     }


//     currentBlock.optimized =
//         optimized;


//     // --------------------------------------------------------
//     // Store compiled block in code cache
//     // --------------------------------------------------------

//     codeCache[cacheKey] =
//         currentBlock;

//     compiled = true;


//     // --------------------------------------------------------
//     // Compilation information
//     // --------------------------------------------------------

//     std::cout
//         << "[JIT] Compiling "
//         << compiledCode.size()
//         << " hot instruction(s)..."
//         << std::endl;


//     std::cout
//         << "[JIT] Preserving original instruction indices."
//         << std::endl;


//     if (optimized) {

//         std::cout
//             << "[JIT] Hot loop pattern recognized."
//             << std::endl;

//         std::cout
//             << "[JIT] Optimized execution path generated."
//             << std::endl;
//     }
//     else {

//         std::cout
//             << "[JIT] Generic compiled execution path generated."
//             << std::endl;
//     }


//     std::cout
//         << "[JIT] Compilation completed."
//         << std::endl;


//     std::cout
//         << "[JIT] Compiled hot block stored in code cache."
//         << std::endl;
// }


// // ============================================================
// // Phase 6: Execute Compiled Code
// // ============================================================

// void JITCompiler::execute(long long initialValue) {

//     if (!compiled) {

//         std::cout
//             << "[JIT] No compiled code available."
//             << std::endl;

//         return;
//     }


//     std::cout
//         << "\n========== JIT Execution =========="
//         << std::endl;


//     std::cout
//         << "JIT Status: ACTIVE"
//         << std::endl;


//     std::cout
//         << "Compiled instructions: "
//         << compiledCode.size()
//         << std::endl;


//     if (optimized) {

//         std::cout
//             << "Execution mode: OPTIMIZED HOT BLOCK"
//             << std::endl;
//     }
//     else {

//         std::cout
//             << "Execution mode: COMPILED BYTECODE"
//             << std::endl;
//     }


//     std::cout
//         << "Executing compiled hot region..."
//         << std::endl;


//     // ========================================================
//     // Optimized countdown loop
//     // ========================================================

//     if (optimized) {

//         long long value =
//             initialValue;

//         unsigned long long operations = 0;


//         /*
//          * Original bytecode:
//          *
//          * DUP
//          * JUMP_IF_ZERO
//          * PUSH 1
//          * SUB
//          * JUMP
//          *
//          * Optimized equivalent:
//          *
//          * while (value != 0)
//          *     value--;
//          *
//          * This eliminates repeated opcode dispatch.
//          */

//         while (value != 0) {

//             --value;

//             ++operations;
//         }


//         compiledExecutionCount +=
//             operations;


//         currentBlock.executionCount +=
//             operations;


//         std::cout
//             << "[JIT] Optimized hot loop executed."
//             << std::endl;


//         std::cout
//             << "[JIT] Final optimized value: "
//             << value
//             << std::endl;


//         std::cout
//             << "[JIT] Optimized operations executed: "
//             << operations
//             << std::endl;


//         std::cout
//             << "[JIT] Compiled execution completed."
//             << std::endl;


//         return;
//     }


//     // ========================================================
//     // Generic compiled execution
//     // ========================================================

//     std::vector<long long> stack;

//     stack.reserve(64);

//     stack.push_back(initialValue);


//     // --------------------------------------------------------
//     // Original instruction index → compiled index
//     // --------------------------------------------------------

//     std::map<
//         std::size_t,
//         std::size_t
//     > indexMap;


//     for (std::size_t i = 0;
//          i < compiledCode.size();
//          ++i) {

//         indexMap[
//             compiledCode[i].originalIndex
//         ] = i;
//     }


//     std::size_t pc = 0;


//     // --------------------------------------------------------
//     // Execute compiled representation
//     // --------------------------------------------------------

//     while (pc < compiledCode.size()) {

//         const CompiledInstruction& instruction =
//             compiledCode[pc];


//         ++compiledExecutionCount;


//         switch (instruction.opcode) {

//             case OpCode::PUSH:

//                 stack.push_back(
//                     instruction.operand
//                 );

//                 ++pc;

//                 break;


//             case OpCode::DUP:

//                 if (stack.empty()) {

//                     throw std::runtime_error(
//                         "JIT stack underflow in DUP"
//                     );
//                 }

//                 stack.push_back(
//                     stack.back()
//                 );

//                 ++pc;

//                 break;


//             case OpCode::POP:

//                 if (stack.empty()) {

//                     throw std::runtime_error(
//                         "JIT stack underflow in POP"
//                     );
//                 }

//                 stack.pop_back();

//                 ++pc;

//                 break;


//             case OpCode::ADD: {

//                 if (stack.size() < 2) {

//                     throw std::runtime_error(
//                         "JIT stack underflow in ADD"
//                     );
//                 }

//                 long long right =
//                     stack.back();

//                 stack.pop_back();


//                 long long left =
//                     stack.back();

//                 stack.pop_back();


//                 stack.push_back(
//                     left + right
//                 );

//                 ++pc;

//                 break;
//             }


//             case OpCode::SUB: {

//                 if (stack.size() < 2) {

//                     throw std::runtime_error(
//                         "JIT stack underflow in SUB"
//                     );
//                 }

//                 long long right =
//                     stack.back();

//                 stack.pop_back();


//                 long long left =
//                     stack.back();

//                 stack.pop_back();


//                 stack.push_back(
//                     left - right
//                 );

//                 ++pc;

//                 break;
//             }


//             case OpCode::MUL: {

//                 if (stack.size() < 2) {

//                     throw std::runtime_error(
//                         "JIT stack underflow in MUL"
//                     );
//                 }

//                 long long right =
//                     stack.back();

//                 stack.pop_back();


//                 long long left =
//                     stack.back();

//                 stack.pop_back();


//                 stack.push_back(
//                     left * right
//                 );

//                 ++pc;

//                 break;
//             }


//             case OpCode::DIV: {

//                 if (stack.size() < 2) {

//                     throw std::runtime_error(
//                         "JIT stack underflow in DIV"
//                     );
//                 }

//                 long long right =
//                     stack.back();

//                 stack.pop_back();


//                 long long left =
//                     stack.back();

//                 stack.pop_back();


//                 if (right == 0) {

//                     throw std::runtime_error(
//                         "Division by zero in JIT"
//                     );
//                 }


//                 stack.push_back(
//                     left / right
//                 );

//                 ++pc;

//                 break;
//             }


//             case OpCode::JUMP: {

//                 std::map<
//                     std::size_t,
//                     std::size_t
//                 >::iterator it =
//                     indexMap.find(
//                         static_cast<std::size_t>(
//                             instruction.operand
//                         )
//                     );


//                 if (it == indexMap.end()) {

//                     pc =
//                         compiledCode.size();
//                 }
//                 else {

//                     pc =
//                         it->second;
//                 }

//                 break;
//             }


//             case OpCode::JUMP_IF_ZERO: {

//                 if (stack.empty()) {

//                     throw std::runtime_error(
//                         "JIT stack underflow in JUMP_IF_ZERO"
//                     );
//                 }


//                 long long value =
//                     stack.back();

//                 stack.pop_back();


//                 if (value == 0) {

//                     pc =
//                         compiledCode.size();
//                 }
//                 else {

//                     ++pc;
//                 }

//                 break;
//             }


//             case OpCode::PRINT:

//                 if (stack.empty()) {

//                     throw std::runtime_error(
//                         "JIT stack empty in PRINT"
//                     );
//                 }

//                 std::cout
//                     << stack.back()
//                     << std::endl;

//                 ++pc;

//                 break;


//             case OpCode::HALT:

//                 pc =
//                     compiledCode.size();

//                 break;
//         }
//     }


//     currentBlock.executionCount =
//         compiledExecutionCount;


//     std::cout
//         << "[JIT] Compiled execution completed."
//         << std::endl;


//     std::cout
//         << "[JIT] Compiled operations executed: "
//         << compiledExecutionCount
//         << std::endl;
// }


// // ============================================================
// // Print Compilation Information
// // ============================================================

// void JITCompiler::printCompilationInfo() const {

//     std::cout
//         << "\n========== JIT Compiler =========="
//         << std::endl;


//     if (!compiled) {

//         std::cout
//             << "JIT Status: NOT COMPILED"
//             << std::endl;

//         return;
//     }


//     std::cout
//         << "JIT Status: COMPILED"
//         << std::endl;


//     std::cout
//         << "Compiled instructions: "
//         << compiledCode.size()
//         << std::endl;


//     std::cout
//         << "Code cache entries: "
//         << codeCache.size()
//         << std::endl;


//     std::cout
//         << "Hot block start index: "
//         << currentBlock.startIndex
//         << std::endl;


//     std::cout
//         << "Hot block end index: "
//         << currentBlock.endIndex
//         << std::endl;


//     if (optimized) {

//         std::cout
//             << "Optimization: ENABLED"
//             << std::endl;
//     }
//     else {

//         std::cout
//             << "Optimization: GENERIC"
//             << std::endl;
//     }


//     std::cout
//         << "Original instruction indices preserved."
//         << std::endl;
// }


// // ============================================================
// // Getters
// // ============================================================

// bool JITCompiler::isCompiled() const {

//     return compiled;
// }


// std::size_t JITCompiler::getCacheSize() const {

//     return codeCache.size();
// }




















// #ifndef JIT_COMPILER_H
// #define JIT_COMPILER_H

// #include <vector>
// #include <map>
// #include <cstddef>
// #include <cstdint>

// #include "../bytecode/Instruction.h"

// class JITCompiler {

// public:

//     JITCompiler();

//     // Phase 6: JIT compilation
//     void compile(
//         const std::vector<
//             std::pair<std::size_t, Instruction>
//         >& instructions
//     );

//     // Phase 6/8: Execute compiled code
//     void execute(long long initialValue);

//     // Display compilation information
//     void printCompilationInfo() const;

//     // Check compilation status
//     bool isCompiled() const;

//     // Phase 7: Code Cache
//     bool isCached(
//         const std::vector<
//             std::pair<std::size_t, Instruction>
//         >& instructions
//     ) const;

//     std::size_t getCacheSize() const;


// private:

//     // ========================================================
//     // Compiled Instruction
//     // ========================================================

//     struct CompiledInstruction {

//         std::size_t originalIndex;

//         OpCode opcode;

//         long long operand;
//     };


//     // ========================================================
//     // Compiled Hot Block
//     // ========================================================

//     struct CompiledBlock {

//         std::size_t startIndex;

//         std::size_t endIndex;

//         std::vector<CompiledInstruction> instructions;

//         bool optimized;

//         unsigned long long executionCount;

//         CompiledBlock()
//             : startIndex(0),
//               endIndex(0),
//               optimized(false),
//               executionCount(0) {
//         }
//     };


//     // ========================================================
//     // Code Cache
//     // ========================================================

//     /*
//      * Key:
//      *     Original starting instruction index
//      *
//      * Value:
//      *     Compiled hot block
//      */

//     std::map<
//         std::size_t,
//         CompiledBlock
//     > codeCache;


//     // ========================================================
//     // Current Compiled Code
//     // ========================================================

//     std::vector<CompiledInstruction> compiledCode;

//     CompiledBlock currentBlock;


//     // ========================================================
//     // JIT State
//     // ========================================================

//     bool compiled;

//     bool optimized;

//     unsigned long long compiledExecutionCount;

//     std::size_t currentCacheKey;
// };

// #endif















#ifndef JIT_COMPILER_H
#define JIT_COMPILER_H

#include <vector>
#include <map>
#include <cstddef>
#include <cstdint>

#include "../bytecode/Instruction.h"

class JITCompiler {

public:

    JITCompiler();

    void compile(
        const std::vector<
            std::pair<std::size_t, Instruction>
        >& instructions
    );

    // Original JIT execution
    void execute();

    // Phase 9:
    // Execute an already compiled hot loop repeatedly.
    //
    // The loop represented by our current test program is:
    //
    // DUP
    // JUMP_IF_ZERO
    // PUSH 1
    // SUB
    // JUMP
    //
    // This method executes its equivalent optimized operation
    // directly without repeatedly decoding bytecode.
    void executeOptimizedLoop(
        int64_t initialValue
    );

    void printCompilationInfo() const;

    bool isCompiled() const;

    // Phase 7: Code Cache
    bool isCached(
        const std::vector<
            std::pair<std::size_t, Instruction>
        >& instructions
    ) const;

    std::size_t getCacheSize() const;

    // Phase 9 statistics
    unsigned long long getCompiledExecutionCount() const;

private:

    struct CompiledInstruction {

        std::size_t originalIndex;

        OpCode opcode;

        long long operand;
    };


    /*
     * Compiled hot block.
     *
     * startIndex:
     *     Original bytecode index where hot block begins.
     *
     * endIndex:
     *     Original bytecode index where hot block ends.
     */
    struct CompiledBlock {

        std::size_t startIndex;

        std::size_t endIndex;

        std::vector<CompiledInstruction> instructions;
    };


    /*
     * Code Cache
     *
     * Key:
     *     Original starting instruction index
     *
     * Value:
     *     Compiled hot block
     */
    std::map<
        std::size_t,
        CompiledBlock
    > codeCache;


    std::vector<CompiledInstruction> compiledCode;

    bool compiled;

    unsigned long long compiledExecutionCount;

    std::size_t currentCacheKey;

    std::size_t hotBlockStart;

    std::size_t hotBlockEnd;
};

#endif