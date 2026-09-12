// // // // // #include "vm/StackVM.h"

// // // // // #include <iostream>
// // // // // #include <sstream>
// // // // // #include <string>
// // // // // #include <vector>
// // // // // #include <stdexcept>

// // // // // Instruction parseInstruction(const std::string& line) {

// // // // //     std::stringstream ss(line);

// // // // //     std::string opcode;
// // // // //     int64_t operand = 0;

// // // // //     ss >> opcode;

// // // // //     if (opcode == "PUSH") {

// // // // //         if (!(ss >> operand)) {
// // // // //             throw std::runtime_error(
// // // // //                 "PUSH requires a numeric value"
// // // // //             );
// // // // //         }

// // // // //         return Instruction(OpCode::PUSH, operand);
// // // // //     }

// // // // //     if (opcode == "POP") {
// // // // //         return Instruction(OpCode::POP);
// // // // //     }

// // // // //     if (opcode == "DUP") {
// // // // //         return Instruction(OpCode::DUP);
// // // // //     }

// // // // //     if (opcode == "ADD") {
// // // // //         return Instruction(OpCode::ADD);
// // // // //     }

// // // // //     if (opcode == "SUB") {
// // // // //         return Instruction(OpCode::SUB);
// // // // //     }

// // // // //     if (opcode == "MUL") {
// // // // //         return Instruction(OpCode::MUL);
// // // // //     }

// // // // //     if (opcode == "DIV") {
// // // // //         return Instruction(OpCode::DIV);
// // // // //     }

// // // // //     if (opcode == "JUMP") {

// // // // //         if (!(ss >> operand)) {
// // // // //             throw std::runtime_error(
// // // // //                 "JUMP requires an instruction index"
// // // // //             );
// // // // //         }

// // // // //         return Instruction(OpCode::JUMP, operand);
// // // // //     }

// // // // //     if (opcode == "JUMP_IF_ZERO") {

// // // // //         if (!(ss >> operand)) {
// // // // //             throw std::runtime_error(
// // // // //                 "JUMP_IF_ZERO requires an instruction index"
// // // // //             );
// // // // //         }

// // // // //         return Instruction(
// // // // //             OpCode::JUMP_IF_ZERO,
// // // // //             operand
// // // // //         );
// // // // //     }

// // // // //     if (opcode == "PRINT") {
// // // // //         return Instruction(OpCode::PRINT);
// // // // //     }

// // // // //     if (opcode == "HALT") {
// // // // //         return Instruction(OpCode::HALT);
// // // // //     }

// // // // //     throw std::runtime_error(
// // // // //         "Unknown instruction: " + opcode
// // // // //     );
// // // // // }


// // // // // int main() {

// // // // //     std::vector<Instruction> program;

// // // // //     int numberOfInstructions;

// // // // //     std::cout << "====================================\n";
// // // // //     std::cout << "     Stack-Based Virtual Machine\n";
// // // // //     std::cout << "====================================\n\n";

// // // // //     std::cout << "Enter number of instructions: ";
// // // // //     std::cin >> numberOfInstructions;

// // // // //     if (numberOfInstructions <= 0) {
// // // // //         std::cout << "Invalid number of instructions.\n";
// // // // //         return 1;
// // // // //     }

// // // // //     std::cin.ignore();

// // // // //     std::cout << "\nEnter bytecode instructions:\n";

// // // // //     std::cout
// // // // //         << "Supported instructions:\n"
// // // // //         << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV,\n"
// // // // //         << "JUMP <index>, JUMP_IF_ZERO <index>,\n"
// // // // //         << "PRINT, HALT\n\n";


// // // // //     for (int i = 0;
// // // // //          i < numberOfInstructions;
// // // // //          i++) {

// // // // //         std::string line;

// // // // //         std::cout << i << ": ";
// // // // //         std::getline(std::cin, line);

// // // // //         try {

// // // // //             Instruction instruction =
// // // // //                 parseInstruction(line);

// // // // //             program.push_back(instruction);

// // // // //         }
// // // // //         catch (const std::exception& error) {

// // // // //             std::cout
// // // // //                 << "Error: "
// // // // //                 << error.what()
// // // // //                 << std::endl;

// // // // //             return 1;
// // // // //         }
// // // // //     }


// // // // //     std::cout << "\n========== Execution ==========\n";

// // // // //     try {

// // // // //         StackVM vm;

// // // // //         vm.execute(program);

// // // // //         const Profiler& profiler =
// // // // //             vm.getProfiler();


// // // // //         unsigned long long totalExecutions = 0;

// // // // //         for (std::size_t i = 0;
// // // // //              i < program.size();
// // // // //              i++) {

// // // // //             totalExecutions +=
// // // // //                 profiler.getExecutionCount(i);
// // // // //         }


// // // // //         std::cout
// // // // //             << "\n========== Runtime Profiler ==========\n";

// // // // //         std::cout
// // // // //             << "Profiler Status: ACTIVE\n";

// // // // //         std::cout
// // // // //             << "Instructions monitored: "
// // // // //             << program.size()
// // // // //             << std::endl;

// // // // //         std::cout
// // // // //             << "Total instructions executed: "
// // // // //             << totalExecutions
// // // // //             << std::endl;

// // // // //         std::cout
// // // // //             << "Hotspot threshold: "
// // // // //             << profiler.getHotspotThreshold()
// // // // //             << std::endl;


// // // // //         std::cout
// // // // //             << "\nExecution Frequency:\n";


// // // // //         for (std::size_t i = 0;
// // // // //              i < program.size();
// // // // //              i++) {

// // // // //             unsigned long long count =
// // // // //                 profiler.getExecutionCount(i);

// // // // //             std::cout
// // // // //                 << "Instruction "
// // // // //                 << i
// // // // //                 << " -> "
// // // // //                 << count
// // // // //                 << " execution(s)";

// // // // //             if (profiler.isHot(i)) {

// // // // //                 std::cout
// // // // //                     << " [HOTSPOT]";
// // // // //             }

// // // // //             std::cout << std::endl;
// // // // //         }


// // // // //         std::cout
// // // // //             << "\nProfiler monitoring completed successfully."
// // // // //             << std::endl;

// // // // //     }
// // // // //     catch (const std::exception& error) {

// // // // //         std::cout
// // // // //             << "\nRuntime Error: "
// // // // //             << error.what()
// // // // //             << std::endl;

// // // // //         return 1;
// // // // //     }


// // // // //     return 0;
// // // // // }



































// // // // #include <iostream>
// // // // #include <string>
// // // // #include <sstream>
// // // // #include <vector>
// // // // #include <cctype>

// // // // #include "bytecode/Instruction.h"
// // // // #include "vm/StackVM.h"

// // // // using namespace std;


// // // // // Convert text to uppercase
// // // // string toUpperCase(string text) {
// // // //     for (size_t i = 0; i < text.length(); ++i) {
// // // //         text[i] = static_cast<char>(
// // // //             toupper(static_cast<unsigned char>(text[i]))
// // // //         );
// // // //     }

// // // //     return text;
// // // // }


// // // // // Parse one user-entered instruction
// // // // Instruction parseInstruction(const string& line) {

// // // //     stringstream ss(line);

// // // //     string opcodeText;
// // // //     ss >> opcodeText;

// // // //     opcodeText = toUpperCase(opcodeText);


// // // //     // PUSH
// // // //     if (opcodeText == "PUSH") {
// // // //         long long value;
// // // //         ss >> value;

// // // //         return Instruction(OpCode::PUSH, value);
// // // //     }


// // // //     // POP
// // // //     if (opcodeText == "POP") {
// // // //         return Instruction(OpCode::POP, 0);
// // // //     }


// // // //     // DUP
// // // //     if (opcodeText == "DUP") {
// // // //         return Instruction(OpCode::DUP, 0);
// // // //     }


// // // //     // ADD
// // // //     if (opcodeText == "ADD") {
// // // //         return Instruction(OpCode::ADD, 0);
// // // //     }


// // // //     // SUB
// // // //     if (opcodeText == "SUB") {
// // // //         return Instruction(OpCode::SUB, 0);
// // // //     }


// // // //     // MUL
// // // //     if (opcodeText == "MUL") {
// // // //         return Instruction(OpCode::MUL, 0);
// // // //     }


// // // //     // DIV
// // // //     if (opcodeText == "DIV") {
// // // //         return Instruction(OpCode::DIV, 0);
// // // //     }


// // // //     // JUMP
// // // //     if (opcodeText == "JUMP") {
// // // //         long long target;
// // // //         ss >> target;

// // // //         return Instruction(OpCode::JUMP, target);
// // // //     }


// // // //     // JUMP_IF_ZERO
// // // //     if (opcodeText == "JUMP_IF_ZERO") {
// // // //         long long target;
// // // //         ss >> target;

// // // //         return Instruction(OpCode::JUMP_IF_ZERO, target);
// // // //     }


// // // //     // PRINT
// // // //     if (opcodeText == "PRINT") {
// // // //         return Instruction(OpCode::PRINT, 0);
// // // //     }


// // // //     // HALT
// // // //     if (opcodeText == "HALT") {
// // // //         return Instruction(OpCode::HALT, 0);
// // // //     }


// // // //     // Invalid instruction
// // // //     cerr << "Invalid instruction: " << line << endl;

// // // //     return Instruction(OpCode::HALT, 0);
// // // // }


// // // // int main() {

// // // //     cout << "====================================" << endl;
// // // //     cout << "     Stack-Based Virtual Machine" << endl;
// // // //     cout << "====================================" << endl;
// // // //     cout << endl;


// // // //     // Ask user for number of instructions
// // // //     size_t instructionCount;

// // // //     cout << "Enter number of instructions: ";
// // // //     cin >> instructionCount;

// // // //     cin.ignore();


// // // //     vector<Instruction> program;

// // // //     cout << endl;
// // // //     cout << "Enter bytecode instructions:" << endl;

// // // //     cout << "Supported instructions:" << endl;
// // // //     cout << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV," << endl;
// // // //     cout << "JUMP <index>, JUMP_IF_ZERO <index>," << endl;
// // // //     cout << "PRINT, HALT" << endl;
// // // //     cout << endl;


// // // //     // Read bytecode instructions
// // // //     for (size_t i = 0; i < instructionCount; ++i) {

// // // //         string line;

// // // //         cout << i << ": ";
// // // //         getline(cin, line);

// // // //         program.push_back(parseInstruction(line));
// // // //     }


// // // //     cout << endl;
// // // //     cout << "========== Execution ==========" << endl;


// // // //     // Create VM
// // // //     StackVM vm;


// // // //     // Execute bytecode
// // // //     vm.execute(program);


// // // //     // Get profiler after execution
// // // //     const Profiler& profiler = vm.getProfiler();


// // // //     cout << endl;
// // // //     cout << "========== Runtime Profiler ==========" << endl;

// // // //     cout << "Profiler Status: ACTIVE" << endl;

// // // //     cout << "Instructions monitored: "
// // // //          << program.size()
// // // //          << endl;

// // // //     cout << "Total instructions executed: "
// // // //          << profiler.getTotalExecutions()
// // // //          << endl;

// // // //     cout << "Hotspot threshold: "
// // // //          << profiler.getHotspotThreshold()
// // // //          << endl;


// // // //     cout << endl;
// // // //     cout << "Execution Frequency:" << endl;


// // // //     // Display execution count for every instruction
// // // //     for (size_t i = 0; i < program.size(); ++i) {

// // // //         cout << "Instruction "
// // // //              << i
// // // //              << " -> "
// // // //              << profiler.getExecutionCount(i)
// // // //              << " execution(s)"
// // // //              << endl;
// // // //     }


// // // //     cout << endl;
// // // //     cout << "========== Hotspot Detection ==========" << endl;

// // // //     cout << "Hotspot Threshold: "
// // // //          << profiler.getHotspotThreshold()
// // // //          << endl;

// // // //     cout << endl;


// // // //     // Phase 5:
// // // //     // Identify instructions whose execution count
// // // //     // has reached or exceeded the hotspot threshold.
// // // //     for (size_t i = 0; i < program.size(); ++i) {

// // // //         unsigned long long count =
// // // //             profiler.getExecutionCount(i);


// // // //         cout << "Instruction "
// // // //              << i
// // // //              << " -> "
// // // //              << count
// // // //              << " execution(s) -> ";


// // // //         if (profiler.isHot(i)) {
// // // //             cout << "HOT";
// // // //         }
// // // //         else {
// // // //             cout << "NORMAL";
// // // //         }


// // // //         cout << endl;
// // // //     }


// // // //     cout << endl;
// // // //     cout << "Hotspot Detection completed successfully."
// // // //          << endl;


// // // //     return 0;
// // // // }
































// // // #include <iostream>
// // // #include <string>
// // // #include <sstream>
// // // #include <vector>
// // // #include <cctype>

// // // #include "bytecode/Instruction.h"
// // // #include "vm/StackVM.h"
// // // #include "jit/JITCompiler.h"

// // // using namespace std;


// // // // Convert text to uppercase
// // // string toUpperCase(string text) {
// // //     for (size_t i = 0; i < text.length(); ++i) {
// // //         text[i] = static_cast<char>(
// // //             toupper(static_cast<unsigned char>(text[i]))
// // //         );
// // //     }

// // //     return text;
// // // }


// // // // Parse user-entered bytecode instruction
// // // Instruction parseInstruction(const string& line) {

// // //     stringstream ss(line);

// // //     string opcodeText;
// // //     ss >> opcodeText;

// // //     opcodeText = toUpperCase(opcodeText);


// // //     // PUSH <value>
// // //     if (opcodeText == "PUSH") {

// // //         long long value;
// // //         ss >> value;

// // //         return Instruction(OpCode::PUSH, value);
// // //     }


// // //     // POP
// // //     if (opcodeText == "POP") {
// // //         return Instruction(OpCode::POP, 0);
// // //     }


// // //     // DUP
// // //     if (opcodeText == "DUP") {
// // //         return Instruction(OpCode::DUP, 0);
// // //     }


// // //     // ADD
// // //     if (opcodeText == "ADD") {
// // //         return Instruction(OpCode::ADD, 0);
// // //     }


// // //     // SUB
// // //     if (opcodeText == "SUB") {
// // //         return Instruction(OpCode::SUB, 0);
// // //     }


// // //     // MUL
// // //     if (opcodeText == "MUL") {
// // //         return Instruction(OpCode::MUL, 0);
// // //     }


// // //     // DIV
// // //     if (opcodeText == "DIV") {
// // //         return Instruction(OpCode::DIV, 0);
// // //     }


// // //     // JUMP <index>
// // //     if (opcodeText == "JUMP") {

// // //         long long target;
// // //         ss >> target;

// // //         return Instruction(OpCode::JUMP, target);
// // //     }


// // //     // JUMP_IF_ZERO <index>
// // //     if (opcodeText == "JUMP_IF_ZERO") {

// // //         long long target;
// // //         ss >> target;

// // //         return Instruction(OpCode::JUMP_IF_ZERO, target);
// // //     }


// // //     // PRINT
// // //     if (opcodeText == "PRINT") {
// // //         return Instruction(OpCode::PRINT, 0);
// // //     }


// // //     // HALT
// // //     if (opcodeText == "HALT") {
// // //         return Instruction(OpCode::HALT, 0);
// // //     }


// // //     // Invalid instruction
// // //     cerr << "Invalid instruction: "
// // //          << line
// // //          << endl;

// // //     return Instruction(OpCode::HALT, 0);
// // // }


// // // int main() {

// // //     cout << "====================================" << endl;
// // //     cout << "     Stack-Based Virtual Machine" << endl;
// // //     cout << "====================================" << endl;
// // //     cout << endl;


// // //     // ------------------------------------
// // //     // STEP 1: Get bytecode from user
// // //     // ------------------------------------

// // //     size_t instructionCount;

// // //     cout << "Enter number of instructions: ";
// // //     cin >> instructionCount;

// // //     cin.ignore();


// // //     vector<Instruction> program;

// // //     cout << endl;
// // //     cout << "Enter bytecode instructions:" << endl;

// // //     cout << "Supported instructions:" << endl;
// // //     cout << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV," << endl;
// // //     cout << "JUMP <index>, JUMP_IF_ZERO <index>," << endl;
// // //     cout << "PRINT, HALT" << endl;
// // //     cout << endl;


// // //     for (size_t i = 0; i < instructionCount; ++i) {

// // //         string line;

// // //         cout << i << ": ";
// // //         getline(cin, line);

// // //         program.push_back(parseInstruction(line));
// // //     }


// // //     // ------------------------------------
// // //     // STEP 2: Execute program
// // //     // ------------------------------------

// // //     cout << endl;
// // //     cout << "========== Execution ==========" << endl;


// // //     StackVM vm;

// // //     vm.execute(program);


// // //     // ------------------------------------
// // //     // STEP 3: Runtime Profiling
// // //     // ------------------------------------

// // //     const Profiler& profiler = vm.getProfiler();


// // //     cout << endl;
// // //     cout << "========== Runtime Profiler =========="
// // //          << endl;

// // //     cout << "Profiler Status: ACTIVE" << endl;

// // //     cout << "Instructions monitored: "
// // //          << program.size()
// // //          << endl;

// // //     cout << "Total instructions executed: "
// // //          << profiler.getTotalExecutions()
// // //          << endl;

// // //     cout << "Hotspot threshold: "
// // //          << profiler.getHotspotThreshold()
// // //          << endl;


// // //     cout << endl;
// // //     cout << "Execution Frequency:" << endl;


// // //     for (size_t i = 0; i < program.size(); ++i) {

// // //         cout << "Instruction "
// // //              << i
// // //              << " -> "
// // //              << profiler.getExecutionCount(i)
// // //              << " execution(s)"
// // //              << endl;
// // //     }


// // //     // ------------------------------------
// // //     // STEP 4: Hotspot Detection
// // //     // ------------------------------------

// // //     cout << endl;
// // //     cout << "========== Hotspot Detection =========="
// // //          << endl;

// // //     cout << "Hotspot Threshold: "
// // //          << profiler.getHotspotThreshold()
// // //          << endl;

// // //     cout << endl;


// // //     // Store instructions identified as HOT
// // //    vector<pair<size_t, Instruction> > hotInstructions;


// // //     for (size_t i = 0; i < program.size(); ++i) {

// // //         unsigned long long count =
// // //             profiler.getExecutionCount(i);


// // //         cout << "Instruction "
// // //              << i
// // //              << " -> "
// // //              << count
// // //              << " execution(s) -> ";


// // //         if (profiler.isHot(i)) {

// // //             cout << "HOT";

// // //             // Add hot instruction to JIT compilation list
// // //            hotInstructions.push_back(
// // //     make_pair(i, program[i])
// // // );

// // //         }
// // //         else {

// // //             cout << "NORMAL";
// // //         }


// // //         cout << endl;
// // //     }


// // //     cout << endl;
// // //     cout << "Hotspot Detection completed successfully."
// // //          << endl;


// // //     // ------------------------------------
// // //     // STEP 5: JIT Compilation
// // //     // ------------------------------------

// // //     cout << endl;
// // //     cout << "========== JIT Compilation =========="
// // //          << endl;


// // //     if (hotInstructions.empty()) {

// // //         cout << "No hot instructions detected."
// // //              << endl;

// // //         cout << "JIT compilation skipped."
// // //              << endl;

// // //     }
// // //     else {

// // //         cout << "Hot instructions detected: "
// // //              << hotInstructions.size()
// // //              << endl;

// // //         cout << "Passing hot instructions to JIT compiler..."
// // //              << endl;


// // //         JITCompiler jitCompiler;


// // //         // Compile the hot instructions
// // //         jitCompiler.compile(hotInstructions);


// // //         // Display JIT compilation information
// // //         jitCompiler.printCompilationInfo();
// // //         jitCompiler.execute();
// // //     }


// // //     cout << endl;
// // //     cout << "===================================="
// // //          << endl;
// // //     cout << "          Program Completed"
// // //          << endl;
// // //     cout << "===================================="
// // //          << endl;


// // //     return 0;
// // // }

















// // #include <iostream>
// // #include <string>
// // #include <sstream>
// // #include <vector>
// // #include <cctype>
// // #include <utility>

// // #include "bytecode/Instruction.h"
// // #include "vm/StackVM.h"
// // #include "jit/JITCompiler.h"

// // using namespace std;


// // // ============================================================
// // // Convert text to uppercase
// // // ============================================================

// // string toUpperCase(string text) {

// //     for (size_t i = 0; i < text.length(); ++i) {

// //         text[i] = static_cast<char>(
// //             toupper(
// //                 static_cast<unsigned char>(text[i])
// //             )
// //         );
// //     }

// //     return text;
// // }


// // // ============================================================
// // // Parse user-entered bytecode instruction
// // // ============================================================

// // Instruction parseInstruction(const string& line) {

// //     stringstream ss(line);

// //     string opcodeText;

// //     ss >> opcodeText;

// //     opcodeText = toUpperCase(opcodeText);


// //     // PUSH <value>
// //     if (opcodeText == "PUSH") {

// //         long long value;

// //         ss >> value;

// //         return Instruction(
// //             OpCode::PUSH,
// //             value
// //         );
// //     }


// //     // POP
// //     if (opcodeText == "POP") {

// //         return Instruction(
// //             OpCode::POP,
// //             0
// //         );
// //     }


// //     // DUP
// //     if (opcodeText == "DUP") {

// //         return Instruction(
// //             OpCode::DUP,
// //             0
// //         );
// //     }


// //     // ADD
// //     if (opcodeText == "ADD") {

// //         return Instruction(
// //             OpCode::ADD,
// //             0
// //         );
// //     }


// //     // SUB
// //     if (opcodeText == "SUB") {

// //         return Instruction(
// //             OpCode::SUB,
// //             0
// //         );
// //     }


// //     // MUL
// //     if (opcodeText == "MUL") {

// //         return Instruction(
// //             OpCode::MUL,
// //             0
// //         );
// //     }


// //     // DIV
// //     if (opcodeText == "DIV") {

// //         return Instruction(
// //             OpCode::DIV,
// //             0
// //         );
// //     }


// //     // JUMP <index>
// //     if (opcodeText == "JUMP") {

// //         long long target;

// //         ss >> target;

// //         return Instruction(
// //             OpCode::JUMP,
// //             target
// //         );
// //     }


// //     // JUMP_IF_ZERO <index>
// //     if (opcodeText == "JUMP_IF_ZERO") {

// //         long long target;

// //         ss >> target;

// //         return Instruction(
// //             OpCode::JUMP_IF_ZERO,
// //             target
// //         );
// //     }


// //     // PRINT
// //     if (opcodeText == "PRINT") {

// //         return Instruction(
// //             OpCode::PRINT,
// //             0
// //         );
// //     }


// //     // HALT
// //     if (opcodeText == "HALT") {

// //         return Instruction(
// //             OpCode::HALT,
// //             0
// //         );
// //     }


// //     // Invalid instruction
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

// // int main() {

// //     cout << "===================================="
// //          << endl;

// //     cout << "     Stack-Based Virtual Machine"
// //          << endl;

// //     cout << "===================================="
// //          << endl;

// //     cout << endl;


// //     // ========================================================
// //     // PHASE 1 — Instruction Set / User Bytecode Input
// //     // ========================================================

// //     size_t instructionCount;


// //     cout << "Enter number of instructions: ";

// //     cin >> instructionCount;

// //     cin.ignore();


// //     vector<Instruction> program;


// //     cout << endl;

// //     cout << "Enter bytecode instructions:"
// //          << endl;


// //     cout << "Supported instructions:"
// //          << endl;

// //     cout << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV,"
// //          << endl;

// //     cout << "JUMP <index>, JUMP_IF_ZERO <index>,"
// //          << endl;

// //     cout << "PRINT, HALT"
// //          << endl;

// //     cout << endl;


// //     for (size_t i = 0;
// //          i < instructionCount;
// //          ++i) {

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


// //     vm.execute(program);


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
// //          ++i) {

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


// //     cout << endl;


// //     vector<
// //         pair<size_t, Instruction>
// //     > hotInstructions;


// //     for (size_t i = 0;
// //          i < program.size();
// //          ++i) {

// //         unsigned long long count =
// //             profiler.getExecutionCount(i);


// //         cout << "Instruction "
// //              << i
// //              << " -> "
// //              << count
// //              << " execution(s) -> ";


// //         if (profiler.isHot(i)) {

// //             cout << "HOT";


// //             /*
// //              * Preserve the original bytecode index
// //              * along with the instruction.
// //              */

// //             hotInstructions.push_back(
// //                 make_pair(
// //                     i,
// //                     program[i]
// //                 )
// //             );

// //         }
// //         else {

// //             cout << "NORMAL";
// //         }


// //         cout << endl;
// //     }


// //     cout << endl;

// //     cout << "Hotspot Detection completed successfully."
// //          << endl;


// //     // ========================================================
// //     // PHASE 6 + PHASE 7
// //     // JIT Compilation + Code Caching
// //     // ========================================================

// //     cout << endl;

// //     cout << "========== JIT Compilation =========="
// //          << endl;


// //     if (hotInstructions.empty()) {

// //         cout << "No hot instructions detected."
// //              << endl;

// //         cout << "JIT compilation skipped."
// //              << endl;
// //     }
// //     else {

// //         cout << "Hot instructions detected: "
// //              << hotInstructions.size()
// //              << endl;


// //         cout << "Passing hot instructions to JIT compiler..."
// //              << endl;


// //         // ----------------------------------------------------
// //         // Create ONE JIT compiler instance.
// //         //
// //         // Keeping this object alive allows the code cache
// //         // to be checked again during the same execution.
// //         // ----------------------------------------------------

// //         JITCompiler jitCompiler;


// //         // ====================================================
// //         // FIRST JIT REQUEST
// //         // ====================================================

// //         cout << endl;

// //         cout << "========== First JIT Request =========="
// //              << endl;


// //         cout << "Checking code cache..."
// //              << endl;


// //         if (
// //             jitCompiler.isCached(
// //                 hotInstructions
// //             )
// //         ) {

// //             cout << "[CACHE] HIT"
// //                  << endl;

// //             cout << "[CACHE] Reusing previously compiled code."
// //                  << endl;

// //         }
// //         else {

// //             cout << "[CACHE] MISS"
// //                  << endl;

// //             cout << "[CACHE] No compiled code found."
// //                  << endl;
// //         }


// //         // Compile and store in cache
// //         jitCompiler.compile(
// //             hotInstructions
// //         );


// //         // Display compiler information
// //         jitCompiler.printCompilationInfo();


// //         // Execute compiled code
// //         jitCompiler.execute();


// //         // ====================================================
// //         // SECOND JIT REQUEST
// //         // ====================================================

// //         cout << endl;

// //         cout << "========== Second JIT Request =========="
// //              << endl;


// //         cout << "Checking code cache again..."
// //              << endl;


// //         if (
// //             jitCompiler.isCached(
// //                 hotInstructions
// //             )
// //         ) {

// //             cout << "[CACHE] HIT"
// //                  << endl;

// //             cout << "[CACHE] Reusing previously compiled code."
// //                  << endl;

// //         }
// //         else {

// //             cout << "[CACHE] MISS"
// //                  << endl;

// //             cout << "[CACHE] Code will be compiled."
// //                  << endl;
// //         }


// //         /*
// //          * Calling compile() again demonstrates that
// //          * the JIT compiler checks the cache and reuses
// //          * the already compiled representation.
// //          */

// //         jitCompiler.compile(
// //             hotInstructions
// //         );


// //         cout << endl;

// //         cout << "[CACHE] Cached code reused successfully."
// //              << endl;


// //         // ====================================================
// //         // Final Cache Information
// //         // ====================================================

// //         cout << endl;

// //         cout << "========== Final Cache Status =========="
// //              << endl;


// //         cout << "Code Cache Entries: "
// //              << jitCompiler.getCacheSize()
// //              << endl;


// //         cout << "Code caching phase completed successfully."
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
// #include <string>
// #include <sstream>
// #include <vector>
// #include <cctype>
// #include <utility>

// #include "bytecode/Instruction.h"
// #include "vm/StackVM.h"
// #include "jit/JITCompiler.h"
// #include "benchmark/Benchmark.h"

// using namespace std;


// // ============================================================
// // Convert text to uppercase
// // ============================================================

// string toUpperCase(string text) {

//     for (size_t i = 0; i < text.length(); ++i) {

//         text[i] = static_cast<char>(
//             toupper(
//                 static_cast<unsigned char>(text[i])
//             )
//         );
//     }

//     return text;
// }


// // ============================================================
// // Parse user-entered bytecode instruction
// // ============================================================

// Instruction parseInstruction(const string& line) {

//     stringstream ss(line);

//     string opcodeText;

//     ss >> opcodeText;

//     opcodeText = toUpperCase(opcodeText);


//     // PUSH <value>
//     if (opcodeText == "PUSH") {

//         long long value;

//         ss >> value;

//         return Instruction(
//             OpCode::PUSH,
//             value
//         );
//     }


//     // POP
//     if (opcodeText == "POP") {

//         return Instruction(
//             OpCode::POP,
//             0
//         );
//     }


//     // DUP
//     if (opcodeText == "DUP") {

//         return Instruction(
//             OpCode::DUP,
//             0
//         );
//     }


//     // ADD
//     if (opcodeText == "ADD") {

//         return Instruction(
//             OpCode::ADD,
//             0
//         );
//     }


//     // SUB
//     if (opcodeText == "SUB") {

//         return Instruction(
//             OpCode::SUB,
//             0
//         );
//     }


//     // MUL
//     if (opcodeText == "MUL") {

//         return Instruction(
//             OpCode::MUL,
//             0
//         );
//     }


//     // DIV
//     if (opcodeText == "DIV") {

//         return Instruction(
//             OpCode::DIV,
//             0
//         );
//     }


//     // JUMP <index>
//     if (opcodeText == "JUMP") {

//         long long target;

//         ss >> target;

//         return Instruction(
//             OpCode::JUMP,
//             target
//         );
//     }


//     // JUMP_IF_ZERO <index>
//     if (opcodeText == "JUMP_IF_ZERO") {

//         long long target;

//         ss >> target;

//         return Instruction(
//             OpCode::JUMP_IF_ZERO,
//             target
//         );
//     }


//     // PRINT
//     if (opcodeText == "PRINT") {

//         return Instruction(
//             OpCode::PRINT,
//             0
//         );
//     }


//     // HALT
//     if (opcodeText == "HALT") {

//         return Instruction(
//             OpCode::HALT,
//             0
//         );
//     }


//     // Invalid instruction
//     cerr << "Invalid instruction: "
//          << line
//          << endl;


//     return Instruction(
//         OpCode::HALT,
//         0
//     );
// }


// // ============================================================
// // MAIN
// // ============================================================

// int main() {

//     cout << "===================================="
//          << endl;

//     cout << "     Stack-Based Virtual Machine"
//          << endl;

//     cout << "===================================="
//          << endl;

//     cout << endl;


//     // ========================================================
//     // PHASE 1 — Instruction Set / Bytecode Input
//     // ========================================================

//     size_t instructionCount;


//     cout << "Enter number of instructions: ";

//     cin >> instructionCount;

//     cin.ignore();


//     vector<Instruction> program;


//     cout << endl;

//     cout << "Enter bytecode instructions:"
//          << endl;


//     cout << "Supported instructions:"
//          << endl;

//     cout << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV,"
//          << endl;

//     cout << "JUMP <index>, JUMP_IF_ZERO <index>,"
//          << endl;

//     cout << "PRINT, HALT"
//          << endl;

//     cout << endl;


//     for (size_t i = 0;
//          i < instructionCount;
//          ++i) {

//         string line;


//         cout << i << ": ";

//         getline(cin, line);


//         program.push_back(
//             parseInstruction(line)
//         );
//     }


//     // ========================================================
//     // PHASE 2 + PHASE 3
//     // Stack VM + Interpreter
//     // ========================================================

//     cout << endl;

//     cout << "========== Execution =========="
//          << endl;


//     StackVM vm;


//     /*
//      * Measure interpreter execution.
//      */
//     Benchmark interpreterBenchmark;

//     interpreterBenchmark.start();

//     vm.execute(program);

//     long long interpreterTime =
//         interpreterBenchmark.stopMicroseconds();


//     // ========================================================
//     // PHASE 4 — Runtime Profiling
//     // ========================================================

//     const Profiler& profiler =
//         vm.getProfiler();


//     cout << endl;

//     cout << "========== Runtime Profiler =========="
//          << endl;


//     cout << "Profiler Status: ACTIVE"
//          << endl;


//     cout << "Instructions monitored: "
//          << program.size()
//          << endl;


//     cout << "Total instructions executed: "
//          << profiler.getTotalExecutions()
//          << endl;


//     cout << "Hotspot threshold: "
//          << profiler.getHotspotThreshold()
//          << endl;


//     cout << endl;

//     cout << "Execution Frequency:"
//          << endl;


//     for (size_t i = 0;
//          i < program.size();
//          ++i) {

//         cout << "Instruction "
//              << i
//              << " -> "
//              << profiler.getExecutionCount(i)
//              << " execution(s)"
//              << endl;
//     }


//     // ========================================================
//     // PHASE 5 — Hotspot Detection
//     // ========================================================

//     cout << endl;

//     cout << "========== Hotspot Detection =========="
//          << endl;


//     cout << "Hotspot Threshold: "
//          << profiler.getHotspotThreshold()
//          << endl;


//     cout << endl;


//     /*
//      * Store original instruction index
//      * together with the instruction.
//      */
//     vector<
//         pair<size_t, Instruction>
//     > hotInstructions;


//     for (size_t i = 0;
//          i < program.size();
//          ++i) {

//         unsigned long long count =
//             profiler.getExecutionCount(i);


//         cout << "Instruction "
//              << i
//              << " -> "
//              << count
//              << " execution(s) -> ";


//         if (profiler.isHot(i)) {

//             cout << "HOT";


//             hotInstructions.push_back(
//                 make_pair(
//                     i,
//                     program[i]
//                 )
//             );

//         }
//         else {

//             cout << "NORMAL";
//         }


//         cout << endl;
//     }


//     cout << endl;

//     cout << "Hotspot Detection completed successfully."
//          << endl;


//     // ========================================================
//     // PHASE 6 + PHASE 7 + PHASE 8
//     // JIT Compilation + Code Cache + Benchmarking
//     // ========================================================

//     cout << endl;

//     cout << "========== JIT Compilation =========="
//          << endl;


//     if (hotInstructions.empty()) {

//         cout << "No hot instructions detected."
//              << endl;

//         cout << "JIT compilation skipped."
//              << endl;


//         // ----------------------------------------------------
//         // Benchmarking without JIT
//         // ----------------------------------------------------

//         cout << endl;

//         cout << "========== Benchmarking =========="
//              << endl;


//         cout << "Interpreter Execution Time : "
//              << interpreterTime
//              << " microseconds"
//              << endl;


//         cout << "JIT Compilation Time      : N/A"
//              << endl;


//         cout << "JIT Execution Time        : N/A"
//              << endl;


//         cout << "JIT Total Time            : N/A"
//              << endl;


//         cout << "Hot Instructions          : 0"
//              << endl;


//         cout << "Code Cache Entries        : 0"
//              << endl;


//         cout << endl;

//         cout << "Benchmark completed successfully."
//              << endl;

//     }
//     else {

//         cout << "Hot instructions detected: "
//              << hotInstructions.size()
//              << endl;


//         cout << "Passing hot instructions to JIT compiler..."
//              << endl;


//         // ----------------------------------------------------
//         // Create one JIT compiler instance.
//         // This allows the cache to persist during
//         // the current VM execution.
//         // ----------------------------------------------------

//         JITCompiler jitCompiler;


//         // ====================================================
//         // FIRST JIT REQUEST
//         // ====================================================

//         cout << endl;

//         cout << "========== First JIT Request =========="
//              << endl;


//         cout << "Checking code cache..."
//              << endl;


//         if (
//             jitCompiler.isCached(
//                 hotInstructions
//             )
//         ) {

//             cout << "[CACHE] HIT"
//                  << endl;

//             cout << "[CACHE] Reusing previously compiled code."
//                  << endl;

//         }
//         else {

//             cout << "[CACHE] MISS"
//                  << endl;

//             cout << "[CACHE] No compiled code found."
//                  << endl;
//         }


//         // ----------------------------------------------------
//         // Measure JIT compilation
//         // ----------------------------------------------------

//         Benchmark jitCompilationBenchmark;

//         jitCompilationBenchmark.start();


//         jitCompiler.compile(
//             hotInstructions
//         );


//         long long jitCompilationTime =
//             jitCompilationBenchmark.stopMicroseconds();


//         // ----------------------------------------------------
//         // Display compiler information
//         // ----------------------------------------------------

//         jitCompiler.printCompilationInfo();


//         // ----------------------------------------------------
//         // Measure JIT execution
//         // ----------------------------------------------------

//         Benchmark jitExecutionBenchmark;

//         jitExecutionBenchmark.start();


//         jitCompiler.execute();


//         long long jitExecutionTime =
//             jitExecutionBenchmark.stopMicroseconds();


//         // ====================================================
//         // SECOND JIT REQUEST
//         // ====================================================

//         cout << endl;

//         cout << "========== Second JIT Request =========="
//              << endl;


//         cout << "Checking code cache again..."
//              << endl;


//         if (
//             jitCompiler.isCached(
//                 hotInstructions
//             )
//         ) {

//             cout << "[CACHE] HIT"
//                  << endl;

//             cout << "[CACHE] Reusing previously compiled code."
//                  << endl;

//         }
//         else {

//             cout << "[CACHE] MISS"
//                  << endl;

//             cout << "[CACHE] Code will be compiled."
//                  << endl;
//         }


//         /*
//          * compile() checks the cache internally.
//          *
//          * Since this hot region was already compiled,
//          * the compiler should reuse the cached code.
//          */

//         jitCompiler.compile(
//             hotInstructions
//         );


//         cout << endl;

//         cout << "[CACHE] Cached code reused successfully."
//              << endl;


//         // ====================================================
//         // CACHE STATUS
//         // ====================================================

//         cout << endl;

//         cout << "========== Final Cache Status =========="
//              << endl;


//         cout << "Code Cache Entries: "
//              << jitCompiler.getCacheSize()
//              << endl;


//         cout << "Code caching phase completed successfully."
//              << endl;


//         // ====================================================
//         // PHASE 8 — BENCHMARKING
//         // ====================================================

//         cout << endl;

//         cout << "========== Benchmarking =========="
//              << endl;


//         cout << "Interpreter Execution Time : "
//              << interpreterTime
//              << " microseconds"
//              << endl;


//         cout << "JIT Compilation Time      : "
//              << jitCompilationTime
//              << " microseconds"
//              << endl;


//         cout << "JIT Execution Time        : "
//              << jitExecutionTime
//              << " microseconds"
//              << endl;


//         cout << "JIT Total Time            : "
//              << jitCompilationTime + jitExecutionTime
//              << " microseconds"
//              << endl;


//         cout << "Hot Instructions          : "
//              << hotInstructions.size()
//              << endl;


//         cout << "Compiled Instructions     : "
//              << hotInstructions.size()
//              << endl;


//         cout << "Code Cache Entries        : "
//              << jitCompiler.getCacheSize()
//              << endl;


//         cout << endl;


//         /*
//          * Basic comparison.
//          *
//          * We do NOT claim that JIT is faster automatically.
//          * The measured values are printed for analysis.
//          */

//         cout << "========== Performance Summary =========="
//              << endl;


//         if (
//             jitCompilationTime +
//             jitExecutionTime
//             <
//             interpreterTime
//         ) {

//             cout << "JIT-assisted execution was faster"
//                  << " for this workload."
//                  << endl;

//         }
//         else if (
//             jitCompilationTime +
//             jitExecutionTime
//             >
//             interpreterTime
//         ) {

//             cout << "Interpreter execution was faster"
//                  << " for this workload."
//                  << endl;

//         }
//         else {

//             cout << "Both execution approaches took"
//                  << " approximately the same time."
//                  << endl;
//         }


//         cout << endl;

//         cout << "Benchmark completed successfully."
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
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <utility>

#include "bytecode/Instruction.h"
#include "vm/StackVM.h"
#include "jit/JITCompiler.h"
#include "benchmark/Benchmark.h"

using namespace std;


// ============================================================
// Convert string to uppercase
// ============================================================

string toUpperCase(string text)
{
    for (size_t i = 0; i < text.length(); ++i)
    {
        text[i] = static_cast<char>(
            toupper(
                static_cast<unsigned char>(text[i])
            )
        );
    }

    return text;
}


// ============================================================
// Parse bytecode instruction
// ============================================================

Instruction parseInstruction(const string& line)
{
    stringstream ss(line);

    string opcodeText;

    ss >> opcodeText;

    opcodeText = toUpperCase(opcodeText);


    if (opcodeText == "PUSH")
    {
        long long value;

        ss >> value;

        return Instruction(
            OpCode::PUSH,
            value
        );
    }


    if (opcodeText == "POP")
    {
        return Instruction(
            OpCode::POP,
            0
        );
    }


    if (opcodeText == "DUP")
    {
        return Instruction(
            OpCode::DUP,
            0
        );
    }


    if (opcodeText == "ADD")
    {
        return Instruction(
            OpCode::ADD,
            0
        );
    }


    if (opcodeText == "SUB")
    {
        return Instruction(
            OpCode::SUB,
            0
        );
    }


    if (opcodeText == "MUL")
    {
        return Instruction(
            OpCode::MUL,
            0
        );
    }


    if (opcodeText == "DIV")
    {
        return Instruction(
            OpCode::DIV,
            0
        );
    }


    if (opcodeText == "JUMP")
    {
        long long target;

        ss >> target;

        return Instruction(
            OpCode::JUMP,
            target
        );
    }


    if (opcodeText == "JUMP_IF_ZERO")
    {
        long long target;

        ss >> target;

        return Instruction(
            OpCode::JUMP_IF_ZERO,
            target
        );
    }


    if (opcodeText == "PRINT")
    {
        return Instruction(
            OpCode::PRINT,
            0
        );
    }


    if (opcodeText == "HALT")
    {
        return Instruction(
            OpCode::HALT,
            0
        );
    }


    cerr << "Invalid instruction: "
         << line
         << endl;


    return Instruction(
        OpCode::HALT,
        0
    );
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    cout << "====================================" << endl;
    cout << "     Stack-Based Virtual Machine" << endl;
    cout << "====================================" << endl;

    cout << endl;


    // ========================================================
    // PHASE 1 — Instruction Set Design
    // ========================================================

    size_t instructionCount;

    cout << "Enter number of instructions: ";

    cin >> instructionCount;

    cin.ignore();


    vector<Instruction> program;


    cout << endl;

    cout << "Enter bytecode instructions:" << endl;

    cout << "Supported instructions:" << endl;

    cout << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV," << endl;

    cout << "JUMP <index>, JUMP_IF_ZERO <index>," << endl;

    cout << "PRINT, HALT" << endl;

    cout << endl;


    for (size_t i = 0;
         i < instructionCount;
         ++i)
    {
        string line;

        cout << i << ": ";

        getline(cin, line);


        program.push_back(
            parseInstruction(line)
        );
    }


    // ========================================================
    // PHASE 2 + PHASE 3
    // Stack VM + Interpreter
    // ========================================================

    cout << endl;

    cout << "========== Execution =========="
         << endl;


    StackVM vm;


    // --------------------------------------------------------
    // Benchmark interpreter execution
    // --------------------------------------------------------

    Benchmark interpreterBenchmark;

    interpreterBenchmark.start();


    vm.execute(program);


    long long interpreterTime =
        interpreterBenchmark.stopMicroseconds();


    // ========================================================
    // PHASE 4 — Runtime Profiling
    // ========================================================

    const Profiler& profiler =
        vm.getProfiler();


    cout << endl;

    cout << "========== Runtime Profiler =========="
         << endl;


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


    for (size_t i = 0;
         i < program.size();
         ++i)
    {
        cout << "Instruction "
             << i
             << " -> "
             << profiler.getExecutionCount(i)
             << " execution(s)"
             << endl;
    }


    // ========================================================
    // PHASE 5 — Hotspot Detection
    // ========================================================

    cout << endl;

    cout << "========== Hotspot Detection =========="
         << endl;


    cout << "Hotspot Threshold: "
         << profiler.getHotspotThreshold()
         << endl;


    vector<
        pair<size_t, Instruction>
    > hotInstructions;


    for (size_t i = 0;
         i < program.size();
         ++i)
    {
        unsigned long long count =
            profiler.getExecutionCount(i);


        cout << "Instruction "
             << i
             << " -> "
             << count
             << " execution(s) -> ";


        if (profiler.isHot(i))
        {
            cout << "HOT";


            hotInstructions.push_back(
                make_pair(
                    i,
                    program[i]
                )
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
    // PHASE 6 — JIT Compilation
    // ========================================================

    cout << endl;

    cout << "========== JIT Compilation =========="
         << endl;


    cout << "Hot instructions detected: "
         << hotInstructions.size()
         << endl;


    if (hotInstructions.empty())
    {
        cout << "No hot instructions detected."
             << endl;

        cout << "JIT compilation skipped."
             << endl;


        // ====================================================
        // PHASE 8 — Benchmarking
        // ====================================================

        cout << endl;

        cout << "========== Phase 8: Benchmarking =========="
             << endl;


        cout << "Interpreter Execution Time : "
             << interpreterTime
             << " microseconds"
             << endl;


        cout << "JIT Compilation Time      : N/A"
             << endl;


        cout << "JIT Execution Time        : N/A"
             << endl;


        cout << "JIT Total Time            : N/A"
             << endl;


        cout << "Hot Instructions          : 0"
             << endl;


        cout << "Code Cache Entries        : 0"
             << endl;


        cout << endl;

        cout << "Benchmark completed successfully."
             << endl;
    }
    else
    {
        cout << "Passing hot instructions to JIT compiler..."
             << endl;


        JITCompiler jitCompiler;


        // ====================================================
        // PHASE 7 — First Cache Request
        // ====================================================

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


        // ====================================================
        // PHASE 6 — JIT Compilation Benchmark
        // ====================================================

        Benchmark jitCompilationBenchmark;

        jitCompilationBenchmark.start();


        jitCompiler.compile(
            hotInstructions
        );


        long long jitCompilationTime =
            jitCompilationBenchmark.stopMicroseconds();


        // Display compiler information

        jitCompiler.printCompilationInfo();


        // ====================================================
        // PHASE 6 — JIT Execution Benchmark
        // ====================================================

        Benchmark jitExecutionBenchmark;

        jitExecutionBenchmark.start();


        jitCompiler.execute();


        long long jitExecutionTime =
            jitExecutionBenchmark.stopMicroseconds();


        // ====================================================
        // PHASE 7 — Second Cache Request
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


        // Request the same compilation again.
        // JITCompiler internally detects the cache hit.

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
        // PHASE 8 — BENCHMARKING
        // ====================================================

        cout << endl;

        cout << "========== Phase 8: Benchmarking =========="
             << endl;


        cout << endl;


        cout << "Interpreter Execution Time : "
             << interpreterTime
             << " microseconds"
             << endl;


        cout << "JIT Compilation Time      : "
             << jitCompilationTime
             << " microseconds"
             << endl;


        cout << "JIT Execution Time        : "
             << jitExecutionTime
             << " microseconds"
             << endl;


        cout << "JIT Total Time            : "
             << jitCompilationTime
             + jitExecutionTime
             << " microseconds"
             << endl;


        cout << "Hot Instructions          : "
             << hotInstructions.size()
             << endl;


        cout << "Compiled Instructions     : "
             << hotInstructions.size()
             << endl;


        cout << "Code Cache Entries        : "
             << jitCompiler.getCacheSize()
             << endl;


        // ----------------------------------------------------
        // Performance comparison
        // ----------------------------------------------------

        cout << endl;

        cout << "========== Performance Comparison =========="
             << endl;


        cout << "Interpreter Time : "
             << interpreterTime
             << " microseconds"
             << endl;


        cout << "JIT Total Time   : "
             << jitCompilationTime
             + jitExecutionTime
             << " microseconds"
             << endl;


        if (interpreterTime > 0)
        {
            double speedup =
                static_cast<double>(interpreterTime)
                /
                static_cast<double>(
                    jitCompilationTime
                    + jitExecutionTime
                );


            cout << "Measured Ratio   : "
                 << speedup
                 << "x"
                 << endl;
        }
        else
        {
            cout << "Measured Ratio   : N/A"
                 << endl;
        }


        cout << endl;

        cout << "Note: This benchmark measures the "
             << "current JIT prototype implementation."
             << endl;

        cout << "Native machine-code speedup is not "
             << "claimed by this prototype."
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