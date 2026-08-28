#include <iostream>
#include <chrono>

// Iterative: O(n) Time | O(1) Space Memory
long long fibonacciIterative(int n) {
    if (n < 0) return -1;  // Edge case handle negative input
    if (n <= 1) return n;  // Base cases: 0 and 1
    
    long long a = 0, b = 1, next = 0;
    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

// Recursive: O(2^n) Time | O(n) Stack Memory
long long fibonacciRecursive(int n) {
    if (n < 0) return -1;  // Edge case handle negative input
    if (n <= 1) return n;  // Base cases: 0 and 1
    
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int testN = 45; // Try 45 to see the drastic performance gap

    std::cout << "=== PERFORMANCE & MEMORY EVALUATION ===" << std::endl;
    std::cout << "Target Sequence Number (N): " << testN << "\n\n";

    // 1. Benchmark Iterative Method
    auto startIter = std::chrono::high_resolution_clock::now();
    long long iterResult = fibonacciIterative(testN);
    auto endIter = std::chrono::high_resolution_clock::now();
    auto iterDuration = std::chrono::duration_cast<std::chrono::microseconds>(endIter - startIter).count();

    std::cout << "[Iterative Method]\n";
    std::cout << "Result: " << iterResult << "\n";
    std::cout << "Execution Time: " << iterDuration << " microseconds\n";
    std::cout << "Memory Usage: O(1) Constant (~24 bytes on stack)\n\n";

    // 2. Benchmark Recursive Method
    auto startRec = std::chrono::high_resolution_clock::now();
    long long recResult = fibonacciRecursive(testN);
    auto endRec = std::chrono::high_resolution_clock::now();
    auto recDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endRec - startRec).count();

    std::cout << "[Recursive Method]\n";
    std::cout << "Result: " << recResult << "\n";
    std::cout << "Execution Time: " << recDuration << " milliseconds\n";
    std::cout << "Call Stack Depth: " << testN << " active frames simultaneously\n";
    std::cout << "Memory Usage: O(n) Linear stack space\n";

    return 0;
}