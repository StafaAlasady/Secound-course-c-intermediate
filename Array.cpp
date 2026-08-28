#include <iostream>
#include <array>
#include <stdexcept>
int main() {
    int c_temps[10] = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76};
    std::array<int, 10> std_temps = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76};
    // Modify 3rd reading (index 2) to 85 degrees
    c_temps[2] = 85;
    std_temps[2] = 85;
    // Your code here: Modify 8th reading (index 7) to 90 degrees
    c_temps[7] = 90;
    std_temps[7] = 90;
    // Display all temperatures to confirm modifications
    std::cout << "C-style temperatures: ";
    for (int i = 0; i < 10; i++) {
        std::cout << c_temps[i] << " ";
    }
    std::cout << std::endl;    
    std::cout << "std::array temperatures: ";
    for (const auto& temp : std_temps) {
        std::cout << temp << " ";
    }
    std::cout << std::endl;    
    return 0;
}
