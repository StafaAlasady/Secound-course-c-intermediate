#include <iostream>
int main() {
    int seating[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0}
    };    
    // Row-major traversal (row by row)
    std::cout << "Seating chart (row by row):" << std::endl;
    for (int row = 0; row < 5; row++) {
        std::cout << "Row " << (row + 1) << ": ";
        for (int col = 0; col < 5; col++) {
            std::cout << seating[row][col] << " ";
        }
        std::cout << std::endl;
    }    
    // Your code here: Implement column-major traversal (column by column)
    std::cout << "\nSeating chart (column by column):" << std::endl;
    // Add your column traversal code
    for (int col = 0; col < 5; col++) {
        std::cout << "Column " << (col + 1) << ": ";
        for (int row = 0; row < 5; row++) {
            std::cout << seating[row][col] << " ";
        }
        std::cout << std::endl;
    }
    // Count total available and occupied seats
    int available = 0, occupied = 0;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (seating[row][col] == 0) {
                available++;
            } else {
                occupied++;
            }
        }
    }    
    std::cout << "\nSummary: " << available << " available, " 
              << occupied << " occupied" << std::endl;    
    return 0;
}