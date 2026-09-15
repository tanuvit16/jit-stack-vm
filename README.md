# JIT Compiler for a Stack-Based Virtual Machine

A modular C++ implementation of a **Just-In-Time (JIT) Compiler for a Stack-Based Virtual Machine**.

The project demonstrates the complete runtime pipeline of a small virtual machine: custom bytecode is parsed and executed by a stack-based interpreter, runtime execution frequencies are collected, frequently executed instructions are identified as hot code, hot code is passed to a JIT compiler, compiled representations are stored in a code cache, cached code can be reused, and execution performance is measured using benchmarking utilities.

The project is designed as a compiler-design and runtime-systems prototype that demonstrates the fundamental concepts behind modern JIT-based execution systems.

---

## 📌 Project Overview

Traditional interpreters execute bytecode instruction-by-instruction. This approach is simple and flexible, but repeatedly interpreting the same instructions can introduce execution overhead.

A JIT compiler improves this model by identifying **frequently executed code**, commonly called **hot code**, and compiling that code into a more optimized representation for repeated execution.

This project implements a simplified version of that idea.

The system starts with custom bytecode and executes it through a stack-based virtual machine. During execution, the runtime profiler records how frequently each instruction is executed. The hotspot detector then identifies instructions whose execution count reaches a predefined threshold.

The detected hot instructions are supplied to the JIT compiler. The JIT compiler recognizes a hot loop/block pattern, creates an optimized execution representation, and stores the compiled representation in a code cache.

On subsequent requests, the runtime checks the cache before compiling again. If the corresponding compiled block already exists, it is reused.

The project also contains a benchmarking module for comparing interpreter execution with JIT-assisted execution and measuring compilation and execution overhead.

---

## 🎯 Project Objectives

The major objectives of this project are:

- Design a small custom bytecode instruction set.
- Implement a stack-based virtual machine.
- Implement a bytecode interpreter.
- Implement runtime instruction profiling.
- Detect frequently executed/hot instructions.
- Pass hot code to a JIT compiler.
- Recognize and compile a hot loop/block.
- Preserve original bytecode instruction indices.
- Maintain a compiled-code cache.
- Demonstrate cache MISS and cache HIT behavior.
- Reuse previously compiled code.
- Execute an optimized hot region.
- Benchmark interpreter and JIT execution.
- Provide a modular and understandable compiler-runtime architecture.

---

## 🏗️ System Architecture

The overall architecture of the project is:

```text
                    +----------------------+
                    |    User / Program    |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    |    Bytecode Input    |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    |    Stack-Based VM    |
                    |  Interpreter + PC    |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    |   Runtime Profiler  |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    |  Hotspot Detection  |
                    +----------+-----------+
                               |
                         Hot Code?
                        /        \
                      NO          YES
                      |             |
                      v             v
                Interpreter    +-------------+
                               | JITCompiler |
                               +------+------+
                                      |
                                      v
                               +-------------+
                               | Code Cache  |
                               +------+------+
                                      |
                                      v
                              Optimized Execution
                                      |
                                      v
                                 Program Output

                                      |
                                      v
                               +-------------+
                               | Benchmark   |
                               +-------------+
