#include <iostream>
int main() {
    int footballpositionsA [3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };


    // Performing matrix transpose
    int result[3][3];  // Initialize result matrix

    // Correct way to store the transpose of matrix A into result:
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[j][i] = footballpositionsA[i][j]; 
        }
    }

    // 2. DISPLAY ORIGINAL
    std::cout << "Original Matrix A:" << std::endl;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            std::cout << footballpositionsA[r][c] << "\t";
        }
        std::cout << std::endl;
    }
    
    // Displaying the result
    std::cout << "Result of transposing both matrices:" << std::endl;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            std::cout << result[r][c] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}