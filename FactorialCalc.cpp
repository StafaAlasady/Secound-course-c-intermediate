#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>

// --- FACTORIAL IMPLEMENTATIONS ---

long long factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// --- FIBONACCI IMPLEMENTATIONS ---

// 1. Naive Recursive O(2^n)
long long fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// 2. Memoized Recursive O(n)
long long fibMemoHelper(int n, std::vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemoHelper(n - 1, memo) + fibMemoHelper(n - 2, memo);
    return memo[n];
}

long long fibonacciMemoized(int n) {
    if (n <= 1) return n;
    std::vector<long long> memo(n + 1, -1);
    return fibMemoHelper(n, memo);
}

// 3. Iterative O(n)
long long fibonacciIterative(int n) {
    if (n <= 1) return n;
    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

// --- TIMING HELPER (Returns nanoseconds for extreme accuracy) ---

template<typename Func>
long long measureNanoseconds(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

int main() {
    std::cout << "========================================================================================\n";
    std::cout << "                              EMPIRICAL BENCHMARK REPORT                                \n";
    std::cout << "========================================================================================\n\n";

    // 1. FACTORIAL BENCHMARK (N = 5 to N = 20)
    std::cout << "--- 1. FACTORIAL COMPARISON (Nanoseconds) ---\n";
    std::cout << std::left << std::setw(10) << "Input N" 
              << std::setw(25) << "Recursive Time (ns)" 
              << std::setw(25) << "Iterative Time (ns)" << "\n";
    std::cout << "---------------------------------------------------------\n";

    std::vector<int> factorialInputs = {5, 10, 15, 20};
    for (int n : factorialInputs) {
        long long recTime = measureNanoseconds([&]() { factorialRecursive(n); });
        long long iterTime = measureNanoseconds([&]() { factorialIterative(n); });

        std::cout << std::left << std::setw(10) << n 
                  << std::setw(25) << recTime 
                  << std::setw(25) << iterTime << "\n";
    }

    std::cout << "\n--- 2. FIBONACCI COMPARISON ACROSS VARIED SIZES ---\n";
    std::cout << std::left << std::setw(10) << "Input N" 
              << std::setw(25) << "Naive Recursive" 
              << std::setw(25) << "Memoized Recursive" 
              << std::setw(25) << "Iterative" << "\n";
    std::cout << "----------------------------------------------------------------------------------------\n";

    std::vector<int> fibInputs = {10, 20, 30, 35, 40, 42};

    for (int n : fibInputs) {
        // Measure Naive Recursive
        long long naiveNs = measureNanoseconds([&]() { fibonacciRecursive(n); });
        
        // Measure Memoized
        long long memoNs = measureNanoseconds([&]() { fibonacciMemoized(n); });

        // Measure Iterative
        long long iterNs = measureNanoseconds([&]() { fibonacciIterative(n); });

        // Display results cleanly formatted
        std::string naiveStr = std::to_string(naiveNs / 1000.0 / 1000.0) + " ms";
        std::string memoStr  = std::to_string(memoNs / 1000.0) + " us";
        std::string iterStr  = std::to_string(iterNs / 1000.0) + " us";

        std::cout << std::left << std::setw(10) << n 
                  << std::setw(25) << naiveStr 
                  << std::setw(25) << memoStr 
                  << std::setw(25) << iterStr << "\n";
    }

    std::cout << "========================================================================================\n";

    return 0;
}