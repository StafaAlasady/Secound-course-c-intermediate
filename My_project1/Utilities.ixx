module; // 1. Global module fragment (headers go here)
#include <cstdlib>
#include <ctime>

export module Utilities;

export namespace Utilities {
    int GenerateSecret(){
    std::srand(std::time(0));
    return std::rand() % 100 + 1;
    }
}