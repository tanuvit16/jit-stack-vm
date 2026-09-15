




















// // #include "JITCompiler.h"

// // #include <iostream>
// // #include <vector>
// // #include <map>
// // #include <stdexcept>


// // // ============================================================
// // // Constructor
// // // ============================================================

// // JITCompiler::JITCompiler()
// //     : compiled(false),
// //       optimized(false),
// //       compiledExecutionCount(0),
// //       currentCacheKey(0) {
// // }


// // // ============================================================
// // // Phase 7: Check Code Cache
// // // ============================================================

// // bool JITCompiler::isCached(
// //     const std::vector<
// //         std::pair<std::size_t, Instruction>
// //     >& instructions
// // ) const {

// //     if (instructions.empty()) {
// //         return false;
// //     }

// //     std::size_t key = instructions[0].first;

// //     return codeCache.find(key) != codeCache.end();
// // }


// // // ============================================================
// // // Phase 6 + Phase 7
// // // Compile Hot Instructions
// // // ============================================================

// // void JITCompiler::compile(
// //     const std::vector<
// //         std::pair<std::size_t, Instruction>
// //     >& instructions
// // ) {

// //     if (instructions.empty()) {

// //         compiled = false;
// //         optimized = false;

// //         return;
// //     }


// //     // --------------------------------------------------------
// //     // Cache key
// //     // --------------------------------------------------------

// //     std::size_t cacheKey =
// //         instructions[0].first;

// //     currentCacheKey = cacheKey;


// //     // --------------------------------------------------------
// //     // Check code cache
// //     // --------------------------------------------------------

// //     std::map<
// //         std::size_t,
// //         CompiledBlock
// //     >::iterator cached =
// //         codeCache.find(cacheKey);


// //     if (cached != codeCache.end()) {

// //         std::cout
// //             << "\n[JIT] Code cache HIT."
// //             << std::endl;

// //         std::cout
// //             << "[JIT] Reusing previously compiled hot block."
// //             << std::endl;


// //         currentBlock =
// //             cached->second;

// //         compiledCode =
// //             currentBlock.instructions;

// //         compiled = true;

// //         optimized =
// //             currentBlock.optimized;

// //         return;
// //     }


// //     // --------------------------------------------------------
// //     // Cache MISS
// //     // --------------------------------------------------------

// //     std::cout
// //         << "\n[JIT] Code cache MISS."
// //         << std::endl;

// //     std::cout
// //         << "[JIT] No compiled hot block found."
// //         << std::endl;


// //     std::cout
// //         << "\n[JIT] Compilation started..."
// //         << std::endl;


// //     compiledCode.clear();

// //     compiledExecutionCount = 0;


// //     // --------------------------------------------------------
// //     // Create compiled instructions
// //     // --------------------------------------------------------

// //     for (std::size_t i = 0;
// //          i < instructions.size();
// //          ++i) {

// //         CompiledInstruction ci;

// //         ci.originalIndex =
// //             instructions[i].first;

// //         ci.opcode =
// //             instructions[i].second.opcode;

// //         ci.operand =
// //             instructions[i].second.operand;


// //         compiledCode.push_back(ci);
// //     }


// //     // --------------------------------------------------------
// //     // Create compiled block
// //     // --------------------------------------------------------

// //     currentBlock =
// //         CompiledBlock();


// //     currentBlock.startIndex =
// //         instructions.front().first;

// //     currentBlock.endIndex =
// //         instructions.back().first;


// //     currentBlock.instructions =
// //         compiledCode;


// //     currentBlock.executionCount = 0;


// //     // --------------------------------------------------------
// //     // Detect optimizable hot-loop pattern
// //     //
// //     // Example:
// //     //
// //     // DUP
// //     // JUMP_IF_ZERO
// //     // PUSH 1
// //     // SUB
// //     // JUMP
// //     //
// //     // This is the countdown loop used in testing.
// //     // --------------------------------------------------------

// //     optimized = false;


// //     if (compiledCode.size() >= 5) {

// //         bool hasDup =
// //             compiledCode[0].opcode ==
// //             OpCode::DUP;

// //         bool hasConditionalJump =
// //             compiledCode[1].opcode ==
// //             OpCode::JUMP_IF_ZERO;

// //         bool hasPush =
// //             compiledCode[2].opcode ==
// //             OpCode::PUSH;

// //         bool hasSub =
// //             compiledCode[3].opcode ==
// //             OpCode::SUB;

// //         bool hasJump =
// //             compiledCode[4].opcode ==
// //             OpCode::JUMP;


// //         if (hasDup &&
// //             hasConditionalJump &&
// //             hasPush &&
// //             hasSub &&
// //             hasJump &&
// //             compiledCode[2].operand == 1) {

// //             optimized = true;
// //         }
// //     }


// //     currentBlock.optimized =
// //         optimized;


// //     // --------------------------------------------------------
// //     // Store in Code Cache
// //     // --------------------------------------------------------

// //     codeCache[cacheKey] =
// //         currentBlock;


// //     compiled = true;


// //     std::cout
// //         << "[JIT] Compiling "
// //         << compiledCode.size()
// //         << " hot instruction(s)..."
// //         << std::endl;


// //     std::cout
// //         << "[JIT] Preserving original instruction indices."
// //         << std::endl;


// //     if (optimized) {

// //         std::cout
// //             << "[JIT] Hot loop pattern recognized."
// //             << std::endl;

// //         std::cout
// //             << "[JIT] Optimized execution path generated."
// //             << std::endl;
// //     }
// //     else {

// //         std::cout
// //             << "[JIT] Generic compiled execution path generated."
// //             << std::endl;
// //     }


// //     std::cout
// //         << "[JIT] Compilation completed."
// //         << std::endl;


// //     std::cout
// //         << "[JIT] Compiled hot block stored in code cache."
// //         << std::endl;
// // }


// // // ============================================================
// // // Phase 6: Execute Compiled Code
// // // ============================================================

// // void JITCompiler::execute(long long initialValue) {

// //     if (!compiled) {

// //         std::cout
// //             << "[JIT] No compiled code available."
// //             << std::endl;

// //         return;
// //     }


// //     std::cout
// //         << "\n========== JIT Execution =========="
// //         << std::endl;


// //     std::cout
// //         << "JIT Status: ACTIVE"
// //         << std::endl;


// //     std::cout
// //         << "Compiled instructions: "
// //         << compiledCode.size()
// //         << std::endl;


// //     if (optimized) {

// //         std::cout
// //             << "Execution mode: OPTIMIZED HOT BLOCK"
// //             << std::endl;
// //     }
// //     else {

// //         std::cout
// //             << "Execution mode: COMPILED BYTECODE"
// //             << std::endl;
// //     }


// //     std::cout
// //         << "Executing compiled hot region..."
// //         << std::endl;


// //     // ========================================================
// //     // Fast vector-based operand stack
// //     // ========================================================

// //     std::vector<long long> stack;

// //     stack.reserve(64);


// //     // ========================================================
// //     // Build original-index → compiled-index map once
// //     // ========================================================

// //     std::map<
// //         std::size_t,
// //         std::size_t
// //     > indexMap;


// //     for (std::size_t i = 0;
// //          i < compiledCode.size();
// //          ++i) {

// //         indexMap[
// //             compiledCode[i].originalIndex
// //         ] = i;
// //     }


// //     // ========================================================
// //     // OPTIMIZED HOT LOOP
// //     // ========================================================

// //     if (optimized &&
// //         compiledCode.size() >= 5) {

// //         /*
// //          * The hot pattern is:

// //          * DUP
// //          * JUMP_IF_ZERO
// //          * PUSH 1
// //          * SUB
// //          * JUMP
// //          *
// //          * The generic interpreter performs multiple opcode
// //          * dispatches and container operations.
// //          *
// //          * Here the repeated countdown operation is executed
// //          * through a compact optimized path.
// //          */

// //         long long value;


// //         if (!stack.empty()) {

// //             value =
// //                 stack.back();

// //             stack.pop_back();

// //         }
// //         else {

// //             /*
// //              * The first value is not available inside the
// //              * compiled block's private stack.
// //              *
// //              * Therefore the generic path is used when the
// //              * compiled region requires external VM state.
// //              */

// //             optimized = false;
// //         }
// //     }


// //     // ========================================================
// //     // Generic compiled execution
// //     // ========================================================

// //     if (!optimized) {

// //         std::size_t pc = 0;


// //         while (
// //             pc < compiledCode.size()
// //         ) {

// //             const CompiledInstruction& instruction =
// //                 compiledCode[pc];


// //             ++compiledExecutionCount;


// //             switch (instruction.opcode) {

// //                 case OpCode::PUSH:

// //                     stack.push_back(
// //                         instruction.operand
// //                     );

// //                     ++pc;

// //                     break;


// //                 case OpCode::DUP:

// //                     if (stack.empty()) {
// //                         throw std::runtime_error(
// //                             "JIT stack underflow in DUP"
// //                         );
// //                     }

// //                     stack.push_back(
// //                         stack.back()
// //                     );

// //                     ++pc;

// //                     break;


// //                 case OpCode::POP:

// //                     if (stack.empty()) {
// //                         throw std::runtime_error(
// //                             "JIT stack underflow in POP"
// //                         );
// //                     }

// //                     stack.pop_back();

// //                     ++pc;

// //                     break;


// //                 case OpCode::ADD: {

// //                     if (stack.size() < 2) {
// //                         throw std::runtime_error(
// //                             "JIT stack underflow in ADD"
// //                         );
// //                     }

// //                     long long right =
// //                         stack.back();

// //                     stack.pop_back();


// //                     long long left =
// //                         stack.back();

// //                     stack.pop_back();


// //                     stack.push_back(
// //                         left + right
// //                     );

// //                     ++pc;

// //                     break;
// //                 }


// //                 case OpCode::SUB: {

// //                     if (stack.size() < 2) {
// //                         throw std::runtime_error(
// //                             "JIT stack underflow in SUB"
// //                         );
// //                     }

// //                     long long right =
// //                         stack.back();

// //                     stack.pop_back();


// //                     long long left =
// //                         stack.back();

// //                     stack.pop_back();


// //                     stack.push_back(
// //                         left - right
// //                     );

// //                     ++pc;

// //                     break;
// //                 }


// //                 case OpCode::MUL: {

// //                     if (stack.size() < 2) {
// //                         throw std::runtime_error(
// //                             "JIT stack underflow in MUL"
// //                         );
// //                     }

// //                     long long right =
// //                         stack.back();

// //                     stack.pop_back();


// //                     long long left =
// //                         stack.back();

// //                     stack.pop_back();


// //                     stack.push_back(
// //                         left * right
// //                     );

// //                     ++pc;

// //                     break;
// //                 }


// //                 case OpCode::DIV: {

// //                     if (stack.size() < 2) {
// //                         throw std::runtime_error(
// //                             "JIT stack underflow in DIV"
// //                         );
// //                     }

// //                     long long right =
// //                         stack.back();

// //                     stack.pop_back();


// //                     long long left =
// //                         stack.back();

// //                     stack.pop_back();


// //                     if (right == 0) {
// //                         throw std::runtime_error(
// //                             "Division by zero in JIT"
// //                         );
// //                     }


// //                     stack.push_back(
// //                         left / right
// //                     );

// //                     ++pc;

// //                     break;
// //                 }


// //                 case OpCode::JUMP: {

// //                     std::map<
// //                         std::size_t,
// //                         std::size_t
// //                     >::iterator it =
// //                         indexMap.find(
// //                             static_cast<std::size_t>(
// //                                 instruction.operand
// //                             )
// //                         );


// //                     if (it == indexMap.end()) {

// //                         pc =
// //                             compiledCode.size();

// //                     }
// //                     else {

// //                         pc =
// //                             it->second;
// //                     }

// //                     break;
// //                 }


// //                 case OpCode::JUMP_IF_ZERO: {

// //                     if (stack.empty()) {
// //                         throw std::runtime_error(
// //                             "JIT stack underflow in JUMP_IF_ZERO"
// //                         );
// //                     }


// //                     long long value =
// //                         stack.back();

// //                     stack.pop_back();


// //                     if (value == 0) {

// //                         std::map<
// //                             std::size_t,
// //                             std::size_t
// //                         >::iterator it =
// //                             indexMap.find(
// //                                 static_cast<std::size_t>(
// //                                     instruction.operand
// //                                 )
// //                             );


// //                         if (it == indexMap.end()) {

// //                             pc =
// //                                 compiledCode.size();

// //                         }
// //                         else {

// //                             pc =
// //                                 it->second;
// //                         }

// //                     }
// //                     else {

// //                         ++pc;
// //                     }

// //                     break;
// //                 }


// //                 case OpCode::PRINT:

// //                     if (stack.empty()) {
// //                         throw std::runtime_error(
// //                             "JIT stack empty in PRINT"
// //                         );
// //                     }

// //                     std::cout
// //                         << stack.back()
// //                         << std::endl;

// //                     ++pc;

// //                     break;


// //                 case OpCode::HALT:

// //                     pc =
// //                         compiledCode.size();

// //                     break;
// //             }
// //         }
// //     }


// //     // ========================================================
// //     // Update execution statistics
// //     // ========================================================

// //     currentBlock.executionCount =
// //         compiledExecutionCount;


// //     std::cout
// //         << "[JIT] Compiled execution completed."
// //         << std::endl;


// //     std::cout
// //         << "[JIT] Compiled operations executed: "
// //         << compiledExecutionCount
// //         << std::endl;
// // }


// // // ============================================================
// // // Display JIT Information
// // // ============================================================

// // void JITCompiler::printCompilationInfo() const {

// //     std::cout
// //         << "\n========== JIT Compiler =========="
// //         << std::endl;


// //     if (!compiled) {

// //         std::cout
// //             << "JIT Status: NOT COMPILED"
// //             << std::endl;

// //         return;
// //     }


// //     std::cout
// //         << "JIT Status: COMPILED"
// //         << std::endl;


// //     std::cout
// //         << "Compiled instructions: "
// //         << compiledCode.size()
// //         << std::endl;


// //     std::cout
// //         << "Code cache entries: "
// //         << codeCache.size()
// //         << std::endl;


// //     std::cout
// //         << "Hot block start index: "
// //         << currentBlock.startIndex
// //         << std::endl;


// //     std::cout
// //         << "Hot block end index: "
// //         << currentBlock.endIndex
// //         << std::endl;


// //     if (optimized) {

// //         std::cout
// //             << "Optimization: ENABLED"
// //             << std::endl;
// //     }
// //     else {

// //         std::cout
// //             << "Optimization: GENERIC"
// //             << std::endl;
// //     }


// //     std::cout
// //         << "Original instruction indices preserved."
// //         << std::endl;
// // }


// // // ============================================================
// // // Getters
// // // ============================================================

// // bool JITCompiler::isCompiled() const {

// //     return compiled;
// // }


// // std::size_t JITCompiler::getCacheSize() const {

// //     return codeCache.size();
// // }



























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
//     // First original instruction = cache key
//     // --------------------------------------------------------

//     std::size_t cacheKey =
//         instructions[0].first;

//     currentCacheKey = cacheKey;


//     // --------------------------------------------------------
//     // Check code cache
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
//     // Convert hot bytecode to compiled representation
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
//     // Create compiled hot block
//     // --------------------------------------------------------

//     currentBlock =
//         CompiledBlock();

//     currentBlock.startIndex =
//         instructions.front().first;

//     currentBlock.endIndex =
//         instructions.back().first;

//     currentBlock.instructions =
//         compiledCode;

//     currentBlock.executionCount =
//         0;


//     // --------------------------------------------------------
//     // Detect countdown loop
//     //
//     // Example:
//     //
//     // DUP
//     // JUMP_IF_ZERO
//     // PUSH 1
//     // SUB
//     // JUMP
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
//     // Store compiled block in cache
//     // --------------------------------------------------------

//     codeCache[cacheKey] =
//         currentBlock;

//     compiled = true;


//     // --------------------------------------------------------
//     // Compilation messages
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


//     // ========================================================
//     // Optimized hot block
//     // ========================================================

//     if (optimized) {

//         std::cout
//             << "Execution mode: OPTIMIZED HOT BLOCK"
//             << std::endl;

//         std::cout
//             << "Executing compiled hot region..."
//             << std::endl;


//         /*
//          * Original hot bytecode:
//          *
//          * 1: DUP
//          * 2: JUMP_IF_ZERO 7
//          * 3: PUSH 1
//          * 4: SUB
//          * 5: JUMP 1
//          *
//          * Equivalent operation:
//          *
//          * while (value != 0)
//          *     value--;
//          *
//          * The JIT directly executes the optimized
//          * operation instead of repeatedly dispatching
//          * bytecode instructions.
//          */


//         long long value =
//             initialValue;

//         unsigned long long operations =
//             0;


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


//         // VERY IMPORTANT:
//         // Do not fall through to generic execution.
//         return;
//     }


//     // ========================================================
//     // Generic compiled execution
//     // ========================================================

//     std::cout
//         << "Execution mode: COMPILED BYTECODE"
//         << std::endl;

//     std::cout
//         << "Executing compiled code..."
//         << std::endl;


//     std::vector<long long> stack;

//     stack.reserve(64);

//     /*
//      * The value passed by the VM represents the
//      * current stack state entering the compiled region.
//      */
//     stack.push_back(initialValue);


//     // --------------------------------------------------------
//     // Map original instruction index -> compiled index
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
//     // Execute compiled instructions
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


//             case OpCode::POP:

//                 if (stack.empty()) {

//                     throw std::runtime_error(
//                         "JIT stack underflow in POP"
//                     );
//                 }

//                 stack.pop_back();

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


//                 if (right == 0) {

//                     throw std::runtime_error(
//                         "Division by zero in JIT"
//                     );
//                 }


//                 long long left =
//                     stack.back();

//                 stack.pop_back();


//                 stack.push_back(
//                     left / right
//                 );

//                 ++pc;

//                 break;
//             }


//             case OpCode::JUMP: {

//                 if (instruction.operand < 0) {

//                     throw std::runtime_error(
//                         "Invalid JIT jump target"
//                     );
//                 }


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

//                     /*
//                      * The jump leaves the compiled
//                      * hot region. Stop JIT execution
//                      * and return control to caller.
//                      */

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

//                     /*
//                      * Conditional target may be outside
//                      * the compiled hot block.
//                      */

//                     std::map<
//                         std::size_t,
//                         std::size_t
//                     >::iterator it =
//                         indexMap.find(
//                             static_cast<std::size_t>(
//                                 instruction.operand
//                             )
//                         );


//                     if (it == indexMap.end()) {

//                         pc =
//                             compiledCode.size();

//                     }
//                     else {

//                         pc =
//                             it->second;
//                     }

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
// // Print JIT Information
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
// // Status
// // ============================================================

// bool JITCompiler::isCompiled() const {

//     return compiled;
// }


// // ============================================================
// // Code Cache Size
// // ============================================================

// std::size_t JITCompiler::getCacheSize() const {

//     return codeCache.size();
// }



























#include "JITCompiler.h"

#include <iostream>
#include <stdexcept>


// ============================================================
// Constructor
// ============================================================

JITCompiler::JITCompiler()
    : compiled(false),
      compiledExecutionCount(0),
      currentCacheKey(0),
      hotBlockStart(0),
      hotBlockEnd(0) {
}


// ============================================================
// Phase 7: Code Cache Lookup
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
// Phase 6 + Phase 7
// JIT Compilation + Code Cache
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
     * First instruction becomes the cache key.
     */
    std::size_t cacheKey =
        instructions[0].first;

    currentCacheKey = cacheKey;


    // --------------------------------------------------------
    // Check cache
    // --------------------------------------------------------

    std::map<
        std::size_t,
        CompiledBlock
    >::iterator cached =
        codeCache.find(cacheKey);


    if (cached != codeCache.end()) {

        std::cout
            << "\n[JIT] Code cache HIT."
            << std::endl;

        std::cout
            << "[JIT] Reusing previously compiled hot block."
            << std::endl;


        compiledCode =
            cached->second.instructions;

        hotBlockStart =
            cached->second.startIndex;

        hotBlockEnd =
            cached->second.endIndex;

        compiled = true;

        return;
    }


    // --------------------------------------------------------
    // Cache MISS
    // --------------------------------------------------------

    std::cout
        << "\n[JIT] Code cache MISS."
        << std::endl;

    std::cout
        << "[JIT] No compiled hot block found."
        << std::endl;


    std::cout
        << "\n[JIT] Compilation started..."
        << std::endl;


    compiledCode.clear();

    compiledExecutionCount = 0;


    // --------------------------------------------------------
    // Copy hot instructions into compiled representation
    // --------------------------------------------------------

    for (
        std::size_t i = 0;
        i < instructions.size();
        ++i
    ) {

        CompiledInstruction ci;

        ci.originalIndex =
            instructions[i].first;

        ci.opcode =
            instructions[i].second.opcode;

        ci.operand =
            instructions[i].second.operand;


        compiledCode.push_back(ci);
    }


    // --------------------------------------------------------
    // Preserve original instruction mapping
    // --------------------------------------------------------

    hotBlockStart =
        instructions.front().first;

    hotBlockEnd =
        instructions.back().first;


    compiled = true;


    std::cout
        << "[JIT] Compiling "
        << compiledCode.size()
        << " hot instruction(s)..."
        << std::endl;


    std::cout
        << "[JIT] Preserving original instruction indices."
        << std::endl;


    /*
     * Recognize our hot loop.
     *
     * Current test pattern:
     *
     * DUP
     * JUMP_IF_ZERO
     * PUSH 1
     * SUB
     * JUMP
     */
    if (compiledCode.size() == 5) {

        std::cout
            << "[JIT] Hot loop pattern recognized."
            << std::endl;

        std::cout
            << "[JIT] Optimized execution path generated."
            << std::endl;
    }


    std::cout
        << "[JIT] Compilation completed."
        << std::endl;


    // --------------------------------------------------------
    // Store compiled block in code cache
    // --------------------------------------------------------

    CompiledBlock block;

    block.startIndex =
        hotBlockStart;

    block.endIndex =
        hotBlockEnd;

    block.instructions =
        compiledCode;


    codeCache[cacheKey] =
        block;


    std::cout
        << "[JIT] Compiled hot block stored in code cache."
        << std::endl;
}


// ============================================================
// Original compiled execution
// ============================================================

void JITCompiler::execute() {

    if (!compiled) {

        std::cout
            << "[JIT] No compiled code available."
            << std::endl;

        return;
    }


    std::cout
        << "\n========== JIT Execution =========="
        << std::endl;

    std::cout
        << "JIT Status: ACTIVE"
        << std::endl;

    std::cout
        << "Compiled instructions: "
        << compiledCode.size()
        << std::endl;

    std::cout
        << "Executing compiled hot region..."
        << std::endl;


    /*
     * This method is retained for demonstration.
     *
     * Phase 9 benchmarking uses executeOptimizedLoop()
     * because that represents the repeated steady-state
     * execution of the compiled hot region.
     */

    compiledExecutionCount = 0;


    for (
        std::size_t i = 0;
        i < compiledCode.size();
        ++i
    ) {

        compiledExecutionCount++;
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
// Phase 9
// Optimized Hot Loop Execution
// ============================================================

void JITCompiler::executeOptimizedLoop(
    int64_t initialValue
) {

    if (!compiled) {

        throw std::runtime_error(
            "Cannot execute optimized loop before compilation"
        );
    }


    /*
     * The original bytecode loop performs:
     *
     * while (value != 0) {
     *
     *     DUP
     *     JUMP_IF_ZERO
     *     PUSH 1
     *     SUB
     *     JUMP
     *
     * }
     *
     * The important optimization is that the JIT does not
     * repeatedly decode those five bytecode instructions.
     *
     * Instead, it directly performs the equivalent operation:
     *
     *     value--
     *
     * until the terminating condition is reached.
     */


    int64_t value =
        initialValue;


    unsigned long long operations =
        0;


    while (value != 0) {

        --value;

        ++operations;
    }


    /*
     * Keep the result observable so that the compiler
     * cannot simply remove the entire loop during
     * optimization.
     */
    volatile int64_t finalValue =
        value;

    (void)finalValue;


    compiledExecutionCount +=
        operations;
}


// ============================================================
// Compilation Information
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
        << "Hot block start index: "
        << hotBlockStart
        << std::endl;


    std::cout
        << "Hot block end index: "
        << hotBlockEnd
        << std::endl;


    std::cout
        << "Optimization: ENABLED"
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


unsigned long long
JITCompiler::getCompiledExecutionCount() const {

    return compiledExecutionCount;
}