#include <iostream>
int main() {
    int seating[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0}
    };    
    // Safe access function
    auto getSeat = [&](int row, int col) -> int {
        if (row >= 0 && row < 5 && col >= 0 && col < 5) {
            return seating[row][col];
        } else {
            std::cout << "Invalid seat position: row " << row 
                      << ", col " << col << std::endl;
            return -1; // Error value
        }
    };    
    // Test valid access
    std::cout << "Valid access - Row 2, Col 3: " << getSeat(1, 2) << std::endl;    
    // Test invalid access
    std::cout << "Invalid access - Row 6, Col 3: " << getSeat(5, 2) << std::endl;
    std::cout << "Invalid access - Row 3, Col 8: " << getSeat(2, 7) << std::endl;    
    // Your code here: Test accessing row -1, col 2
    std::cout << "Invalid access - Row -1, Col 2: " << getSeat(0, 1) << std::endl;
    return 0;
}