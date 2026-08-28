#include <iostream>
#include <cmath>
// Overloaded functions for calculating area
double calculateArea(double radius) {
// Circle area: π * r²
return 3.14159 * radius * radius;
}
double calculateArea(double length, double width) {
// Rectangle area: length * width
return length * width;
}
double calculateArea(double base, double height, bool isTriangle) {
// Triangle area: 0.5 * base * height
// The bool parameter distinguishes this from rectangle
return 0.5 * base * height;
}
double calculateArea(double side, bool isSquare){
// Square area: side * side
return side * side;
}
// Overloaded functions for power calculations
int power(int base, int exponent) {
// Integer power using repeated multiplication
if (exponent == 0) return 1;
if (exponent == 1) return base;
int result = 1;
for (int i = 0; i < exponent; i++) {
result *= base;
}
return result;
}
double power(double base, double exponent) {
// Floating-point power using library function
return std::pow(base, exponent);
}
double power(double base, int exponent){
    // any number to the power of 0 is 1
    if(exponent == 0) return 1;

int absExponent = std::abs(exponent);
    double result = 1.0;

    for (int i = 0; i < absExponent; i++) {
        result *= base;
    }

    // 3. If exponent was negative, flip it: 1 / result
    if (exponent < 0) {
        return 1.0 / result;
    }
    return result;
}
int main() {
// Test area calculations
std::cout << "=== Area Calculations ===" << std::endl;
std::cout << "Circle (radius 5): " << calculateArea(5.0) << std::endl;
std::cout << "Rectangle (4x6): " << calculateArea(4.0, 6.0) << std::endl;
std::cout << "Triangle (base 4, height 6): " << calculateArea(4.0, 6.0, true) << std::endl;
std::cout << "Square (Side x side 4): " << calculateArea(4.0, true) << std::endl;
// Test power calculations
std::cout << "\n=== Power Calculations ===" << std::endl;
std::cout << "Integer: 2^8 = " << power(2, 8) << std::endl;
std::cout << "Float: 2.5^3.2 = " << power(2.5, 3.2) << std::endl;
std::cout << "Negative power: (2,-3) = " << power(2.0,-3.0) << std::endl;
return 0;
}