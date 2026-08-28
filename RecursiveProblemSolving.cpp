#include <iostream>
// Recursive factorial calculation
long long factorial(int n) {
// Base case: factorial of 0 or 1 is 1
if (n <= 1) {
return 1;
}
// Recursive step: n! = n * (n-1)!
return n * factorial(n - 1);
}
// Recursive Fibonacci sequence
long long fibonacci(int n) {
// Base cases
if (n <= 0) return 0;
if (n == 1) return 1;
// Recursive step: F(n) = F(n-1) + F(n-2)
return fibonacci(n - 1) + fibonacci(n - 2);
}
// Recursive power calculation (alternative to iterative version)
long long recursivePower(int base, int exponent) {
// Base case
if (exponent == 0) return 1;
if (exponent == 1) return base;
// Recursive step for positive exponents
if (exponent > 0) {
return base * recursivePower(base, exponent - 1);
}
// Handle negative exponents (returns 0 for integer division)
return 0;
}
// Recursive sum of digits
int sumOfDigits(int number, int& count) {
// everytime this function is called we are processing 1 digit
count++;

// Make number positive if negative
number = std::abs(number);
// Base case: single digit
if (number < 10) {
return number;
}
// Recursive step: last digit + sum of remaining digits
return (number % 10) + sumOfDigits(number / 10, count);
}
int main() {
int count1 = 0;
std::cout << "=== Recursive Calculations ===" << std::endl;
// Test factorial
std::cout << "Factorial of 15: " << factorial(15) << std::endl;
std::cout << "Factorial of 20: " << factorial(20) << std::endl;
// Test Fibonacci
std::cout << "Fibonacci sequence (first 40 numbers): ";
for (int i = 0; i < 40; i++) {
std::cout << fibonacci(i) << " ";
}
std::cout << std::endl;
// Test recursive power
std::cout << "Recursive power: 3^4 = " << recursivePower(3, 4) << std::endl;
// Test sum of digits
std::cout << "Sum of digits in 12345: " << sumOfDigits(12345, count1) << std::endl;
std::cout << "Sum of digits in 987: " << sumOfDigits(987, count1) << std::endl;
return 0;
}