cmake_minimum_required(VERSION 3.14)
project(CapstoneProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main Application Executable
add_executable(capstone_app
    main.cpp
    JsonProcessor.cpp
)
target_include_directories(capstone_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Unit Test Runner Executable
add_executable(run_tests
    test_main.cpp
)
target_include_directories(run_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})