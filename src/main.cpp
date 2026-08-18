#include "vm/StackVM.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

Instruction parseInstruction(const std::string& line) {

    std::stringstream ss(line);

    std::string opcode;
    int64_t operand = 0;

    ss >> opcode;

    if (opcode == "PUSH") {

        if (!(ss >> operand)) {
            throw std::runtime_error(
                "PUSH requires a numeric value"
            );
        }

        return Instruction(OpCode::PUSH, operand);
    }

    if (opcode == "POP") {
        return Instruction(OpCode::POP);
    }

    if (opcode == "DUP") {
        return Instruction(OpCode::DUP);
    }

    if (opcode == "ADD") {
        return Instruction(OpCode::ADD);
    }

    if (opcode == "SUB") {
        return Instruction(OpCode::SUB);
    }

    if (opcode == "MUL") {
        return Instruction(OpCode::MUL);
    }

    if (opcode == "DIV") {
        return Instruction(OpCode::DIV);
    }

    if (opcode == "JUMP") {

        if (!(ss >> operand)) {
            throw std::runtime_error(
                "JUMP requires an instruction index"
            );
        }

        return Instruction(OpCode::JUMP, operand);
    }

    if (opcode == "JUMP_IF_ZERO") {

        if (!(ss >> operand)) {
            throw std::runtime_error(
                "JUMP_IF_ZERO requires an instruction index"
            );
        }

        return Instruction(
            OpCode::JUMP_IF_ZERO,
            operand
        );
    }

    if (opcode == "PRINT") {
        return Instruction(OpCode::PRINT);
    }

    if (opcode == "HALT") {
        return Instruction(OpCode::HALT);
    }

    throw std::runtime_error(
        "Unknown instruction: " + opcode
    );
}


int main() {

    std::vector<Instruction> program;

    int numberOfInstructions;

    std::cout << "====================================\n";
    std::cout << "     Stack-Based Virtual Machine\n";
    std::cout << "====================================\n\n";

    std::cout << "Enter number of instructions: ";
    std::cin >> numberOfInstructions;

    if (numberOfInstructions <= 0) {
        std::cout << "Invalid number of instructions.\n";
        return 1;
    }

    std::cin.ignore();

    std::cout << "\nEnter bytecode instructions:\n";

    std::cout
        << "Supported instructions:\n"
        << "PUSH <value>, POP, DUP, ADD, SUB, MUL, DIV,\n"
        << "JUMP <index>, JUMP_IF_ZERO <index>,\n"
        << "PRINT, HALT\n\n";


    for (int i = 0;
         i < numberOfInstructions;
         i++) {

        std::string line;

        std::cout << i << ": ";
        std::getline(std::cin, line);

        try {

            Instruction instruction =
                parseInstruction(line);

            program.push_back(instruction);

        }
        catch (const std::exception& error) {

            std::cout
                << "Error: "
                << error.what()
                << std::endl;

            return 1;
        }
    }


    std::cout << "\n========== Execution ==========\n";

    try {

        StackVM vm;

        vm.execute(program);

        const Profiler& profiler =
            vm.getProfiler();


        unsigned long long totalExecutions = 0;

        for (std::size_t i = 0;
             i < program.size();
             i++) {

            totalExecutions +=
                profiler.getExecutionCount(i);
        }


        std::cout
            << "\n========== Runtime Profiler ==========\n";

        std::cout
            << "Profiler Status: ACTIVE\n";

        std::cout
            << "Instructions monitored: "
            << program.size()
            << std::endl;

        std::cout
            << "Total instructions executed: "
            << totalExecutions
            << std::endl;

        std::cout
            << "Hotspot threshold: "
            << profiler.getHotspotThreshold()
            << std::endl;


        std::cout
            << "\nExecution Frequency:\n";


        for (std::size_t i = 0;
             i < program.size();
             i++) {

            unsigned long long count =
                profiler.getExecutionCount(i);

            std::cout
                << "Instruction "
                << i
                << " -> "
                << count
                << " execution(s)";

            if (profiler.isHot(i)) {

                std::cout
                    << " [HOTSPOT]";
            }

            std::cout << std::endl;
        }


        std::cout
            << "\nProfiler monitoring completed successfully."
            << std::endl;

    }
    catch (const std::exception& error) {

        std::cout
            << "\nRuntime Error: "
            << error.what()
            << std::endl;

        return 1;
    }


    return 0;
}