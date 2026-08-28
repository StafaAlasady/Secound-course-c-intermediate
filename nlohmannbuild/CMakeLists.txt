# 1. Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.14)

# 2. Name your project
project(JsonLab CXX)

# 3. Set C++ standard (C++17 or C++20 works great for this)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. Automatically download nlohmann/json library from GitHub
include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

# 5. Tell CMake to build an executable program called "my_app" from main.cpp
add_executable(nlohmannbuild AdvancedAidev.cpp)


# 6. Link the downloaded json library to your program
target_link_libraries(nlohmannbuild PRIVATE nlohmann_json::nlohmann_json)