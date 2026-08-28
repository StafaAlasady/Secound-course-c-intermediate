Project Title & Overview: High-level summary of the high-performance JSON data processing pipeline.

Architecture Diagram / Overview: Brief breakdown of the modular namespace architecture (DataRecord, JsonProcessor, StatsAnalyzer).

Prerequisites & Toolchain: C++17 compliant compiler (g++, clang++, or MSVC) and dependencies the (nlohmann/json)library from github.com/nlohmann/json.

## Getting Started & Usage

Build & Run Instructions: Clear step-by-step terminal commands for PowerShell, Linux, and macOS.

Sample Input/Output: Code blocks showing data_input.json input alongside the generated processed_output.json.

## Directory Structure

CapstoneProject/
├── CMakeLists.txt        # Cross-platform build configuration
├── DataRecord.hpp        # Core data model struct
├── JsonProcessor.hpp     # I/O & parsing namespace declarations
├── JsonProcessor.cpp     # File I/O implementations
├── StatsAnalyzer.hpp     # Mathematical & statistical processing engine
├── main.cpp              # Application entry point & orchestration
├── test_main.cpp         # Automated test suite
└── data_input.json       # Input dataset