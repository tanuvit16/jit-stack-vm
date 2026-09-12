// // // // #ifndef JIT_COMPILER_H
// // // // #define JIT_COMPILER_H

// // // // #include <vector>
// // // // #include "../bytecode/Instruction.h"

// // // // class JITCompiler {
// // // // public:

// // // //     JITCompiler();

// // // //     // Compile a sequence of hot bytecode instructions
// // // //     void compile(const std::vector<Instruction>& instructions);

// // // //     // Display information about the compiled code
// // // //     void printCompilationInfo() const;

// // // //     // Check whether compilation has occurred
// // // //     bool isCompiled() const;

// // // // private:

// // // //     bool compiled;
// // // //     std::size_t compiledInstructionCount;
// // // // };

// // // // #endif


















// // // #ifndef JIT_COMPILER_H
// // // #define JIT_COMPILER_H

// // // #include <vector>
// // // #include "../bytecode/Instruction.h"

// // // class JITCompiler {
// // // public:
// // //     JITCompiler();

// // //     void compile(const std::vector<Instruction>& instructions);

// // //     void printCompilationInfo() const;

// // //     bool isCompiled() const;

// // // private:
// // //     bool compiled;
// // //     std::size_t compiledInstructionCount;
// // // };

// // // #endif





















// // #ifndef JIT_COMPILER_H
// // #define JIT_COMPILER_H

// // #include <vector>
// // #include "../bytecode/Instruction.h"

// // class JITCompiler {
// // public:

// //     JITCompiler();

// //     // Compile hot instructions
// //     void compile(const std::vector<Instruction>& instructions);

// //     // Execute the compiled representation
// //     void execute();

// //     // Display compilation information
// //     void printCompilationInfo() const;

// //     bool isCompiled() const;

// // private:

// //     struct CompiledInstruction {
// //         OpCode opcode;
// //         long long operand;
// //     };

// //     std::vector<CompiledInstruction> compiledCode;

// //     bool compiled;
// //     unsigned long long compiledExecutionCount;
// // };

// // #endif




















// #ifndef JIT_COMPILER_H
// #define JIT_COMPILER_H

// #include <vector>
// #include "../bytecode/Instruction.h"

// class JITCompiler {
// public:

//     JITCompiler();

//     // Compile hot instructions while preserving
//     // their original program indices.
//     void compile(
//         const std::vector<std::pair<std::size_t, Instruction> >&
//         instructions
//     );

//     // Execute the compiled hot region.
//     void execute();

//     // Display compilation information.
//     void printCompilationInfo() const;

//     bool isCompiled() const;

// private:

//     struct CompiledInstruction {

//         std::size_t originalIndex;

//         OpCode opcode;

//         long long operand;
//     };

//     std::vector<CompiledInstruction> compiledCode;

//     bool compiled;

//     unsigned long long compiledExecutionCount;
// };

// #endif






































#ifndef JIT_COMPILER_H
#define JIT_COMPILER_H

#include <vector>
#include <map>
#include <cstddef>

#include "../bytecode/Instruction.h"

class JITCompiler {
public:

    JITCompiler();

    void compile(
        const std::vector<
            std::pair<std::size_t, Instruction>
        >& instructions
    );

    void execute();

    void printCompilationInfo() const;

    bool isCompiled() const;

    // Phase 7: Code Cache
    bool isCached(
        const std::vector<
            std::pair<std::size_t, Instruction>
        >& instructions
    ) const;

    std::size_t getCacheSize() const;

private:

    struct CompiledInstruction {

        std::size_t originalIndex;

        OpCode opcode;

        long long operand;
    };


    /*
     * Stores compiled code.
     *
     * Key:
     *     original starting instruction index
     *
     * Value:
     *     compiled instruction sequence
     */
    std::map<
        std::size_t,
        std::vector<CompiledInstruction>
    > codeCache;


    std::vector<CompiledInstruction> compiledCode;

    bool compiled;

    unsigned long long compiledExecutionCount;

    std::size_t currentCacheKey;
};

#endif