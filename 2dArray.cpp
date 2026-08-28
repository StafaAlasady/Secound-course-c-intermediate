#include <iostream>
int main() {
    int seating[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0}
    };    
    // Check specific seats (row 2, column 3) and (row 4, column 1)
    std::cout << "Seat at row 2, column 3: " << seating[1][2] << std::endl;
    std::cout << "Seat at row 4, column 1: " << seating[3][0] << std::endl;    
    // Your code here: Check seat at row 1, column 4 and row 5, column 2
    std::cout << "seat at row 1, column 4: " << seating[0][3] << std::endl;
    std::cout << "seat at row 5, column 2: " << seating[4][1] << std::endl;

    // Reserve seat at row 3, column 2 (change from 0 to 1)
    seating[2][1] = 1;
    std::cout << "Reserved seat at row 3, column 2" << std::endl;   
    // Your code here: Free up seat at row 2, column 1 (change from 1 to 0)   
    seating[1][0] = 0;
    std::cout << "Freed up seat at row 2, column 1" << std::endl;

    return 0;
}