#include <iostream>
#include <chrono>
#include <vector>

// Recursive Fibonacci (inefficient - exponential time O(2^n))
long long fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Memoized Fibonacci Helper (Top-Down Dynamic Programming)
long long fibonacciMemoHelper(int n, std::vector<long long>& memo) {
    if (n <= 1) return n;
    
    // 1. Check if result is already in cache
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // 2. Compute and store in cache before returning
    memo[n] = fibonacciMemoHelper(n - 1, memo) + fibonacciMemoHelper(n - 2, memo);
    return memo[n];
}

// Wrapper function to initialize the memoization vector
long long fibonacciMemoized(int n) {
    if (n <= 1) return n;
    // Cache size n+1 initialized with -1
    std::vector<long long> memo(n + 1, -1);
    return fibonacciMemoHelper(n, memo);
}

// Iterative Fibonacci (efficient - linear time O(n))
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

// Recursive array sum
int sumArrayRecursive(const std::vector<int>& arr, int index = 0) {
    if (index >= arr.size()) {
        return 0;
    }
    return arr[index] + sumArrayRecursive(arr, index + 1);
}

// Iterative array sum
int sumArrayIterative(const std::vector<int>& arr) {
    int sum = 0;
    for (int value : arr) {
        sum += value;
    }
    return sum;
}

// Function to measure execution time
template<typename Function>
void measureTime(const std::string& description, Function func) {
    auto start = std::chrono::high_resolution_clock::now();
    auto result = func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << description << ": " << result
              << " (Time: " << duration.count() << " microseconds)" << std::endl;
}

int main() {
    std::cout << "=== Performance Comparison ===" << std::endl;
    
    int fibNumber = 35; 
    std::cout << "Fibonacci(" << fibNumber << "):" << std::endl;
    
    // Test all three implementations
    measureTime("Memoized ", [=]() { return fibonacciMemoized(fibNumber); });
    measureTime("Iterative", [=]() { return fibonacciIterative(fibNumber); });
    measureTime("Recursive", [=]() { return fibonacciRecursive(fibNumber); });

    // Compare array sum implementations
    std::vector<int> testArray = {1, 5, 3, 9, 2, 8, 4, 7, 6, 10};
    std::cout << "\nArray Sum:" << std::endl;
    measureTime("Recursive", [&]() { return sumArrayRecursive(testArray); });
    measureTime("Iterative", [&]() { return sumArrayIterative(testArray); });

    // Stack depth demonstration
    std::cout << "\n=== Stack Depth Demonstration ===" << std::endl;
    std::vector<int> largeArray(10000, 1);
    std::cout << "Large array (10,000 elements):" << std::endl;
    std::cout << "Iterative sum: " << sumArrayIterative(largeArray) << std::endl;

    std::cout << "Recursive sum: ";
    try {
        std::cout << sumArrayRecursive(largeArray) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Stack overflow or other error occurred!" << std::endl;
    }

    return 0;
}