#include <iostream>
#include <array>
#include <stdexcept>
#include <algorithm>
#include <numeric> // Required for std::accumulate

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int c_dataset[20] = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76, 10, 23, 55, 60, 43, 99, 32, 64, 58, 12};
    
    // Sort C-style array
    bubbleSort(c_dataset, 20);

    std::cout << "Sorted C-style array: ";
    for (int i = 0; i < 20; i++) {
        std::cout << c_dataset[i] << " ";
    }
    std::cout << std::endl;

    std::array<int, 20> std_dataset = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76, 10, 23, 55, 60, 43, 99, 32, 64, 58, 12};
    std::sort(std_dataset.begin(), std_dataset.end());

    std::cout << "Sorted std::array:   ";
    for (const auto& num : std_dataset) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ---------------------------------------------------------
    // 1. MEAN CALCULATION
    // ---------------------------------------------------------
    // C-style manual sum loop
    double c_sum = 0;
    for (int i = 0; i < 20; i++) {
        c_sum += c_dataset[i];
    }
    double c_mean = c_sum / 20.0;

    // std::array using std::accumulate (from <numeric>)
    double std_sum = std::accumulate(std_dataset.begin(), std_dataset.end(), 0);
    double std_mean = std_sum / 20.0;

    // ---------------------------------------------------------
    // 2. MEDIAN CALCULATION (Even dataset rule)
    // ---------------------------------------------------------
    double c_median = (c_dataset[9] + c_dataset[10]) / 2.0;
    double std_median = (std_dataset[9] + std_dataset[10]) / 2.0;

    // ---------------------------------------------------------
    // 3. DISPLAY RESULTS
    // ---------------------------------------------------------
    std::cout << "\n--- C-Style Array Stats ---" << std::endl;
    std::cout << "Mean:   " << c_mean << std::endl;
    std::cout << "Median: " << c_median << std::endl;

    std::cout << "\n--- std::array Stats ---" << std::endl;
    std::cout << "Mean:   " << std_mean << std::endl;
    std::cout << "Median: " << std_median << std::endl;

    return 0;
}