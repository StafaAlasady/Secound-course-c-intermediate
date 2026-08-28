// main.cpp - Mathematical Utility Library
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <numeric>
// TODO: Use AI to generate the following functions:
// 1. Function to calculate factorial of a number
// 2. Function to check if a number is prime
// 3. Function to calculate average of a vector of numbers
unsigned long long calculateFactorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial is undefined for negative numbers.");
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

double calculateAverage(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot calculate average of an empty vector.");
    }
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

int main() {
    std::cout << "Mathematical Utility Library" << std::endl; 
    std::cout << "------------------------------------" << std::endl;
    
    // Test factorial function
    std::cout << "Testing factorial function..." << std::endl;
    std::cout << "Factorial of 5: " << calculateFactorial(5) << " (Expected: 120)" << std::endl;
    std::cout << "Factorial of 10: " << calculateFactorial(10) << " (Expected: 3628800)" << std::endl;
    std::cout << std::endl;
    
    // Test prime checking function
    std::cout << "Testing prime checking function..." << std::endl;
    // std::boolalpha formats '1' and '0' as 'true' and 'false'
    std::cout << "Is 17 prime? " << std::boolalpha << isPrime(17) << " (Expected: true)" << std::endl;
    std::cout << "Is 16 prime? " << std::boolalpha << isPrime(16) << " (Expected: false)" << std::endl;
    std::cout << "Is 120 prime? " << std::boolalpha << isPrime(120) << " (Expected: false)" << std::endl;
    std::cout << std::endl;
    
    // Test average calculation function
    std::cout << "Testing average calculation function..." << std::endl;
    std::vector<double> numbers = {10.5, 20.0, 15.5, 30.0, 25.5};
    std::cout << "Average of numbers: " << calculateAverage(numbers) << " (Expected: 20.3)" << std::endl;
    
    return 0;
}