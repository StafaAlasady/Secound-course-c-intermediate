#include <iostream>

int main() {
    // 3x3 Matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Matrix Dimension Validation
    int rows = 3;
    int cols = 3;

    // checking if the matrix is 3x3
    // if rows do not equal 3 and cols do not equal 3
    if (rows != 3 || cols != 3) {
        std::cout << "Error: Matrix must be 3x3 to calculate determinant using this formula." << std::endl;
        return 1;
    }

    // Step 1: Extract individual elements for clarity
    int a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
    int d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
    int g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];

    // Step 2: Calculate the 2x2 minors (cross-multiplications)
    int term1 = a * (e * i - f * h);
    int term2 = b * (d * i - f * g);
    int term3 = c * (d * h - e * g);

    // Step 3: Combine terms with alternating signs (+ - +)
    int determinant = term1 - term2 + term3;

    // Display original matrix
    std::cout << "Matrix:" << std::endl;
    for (int r = 0; r < 3; r++) {
        for (int c_idx = 0; c_idx < 3; c_idx++) {
            std::cout << matrix[r][c_idx] << "\t";
        }
        std::cout << std::endl;
    }

    // Output the result
    std::cout << "\nDeterminant: " << determinant << std::endl;

    return 0;
}