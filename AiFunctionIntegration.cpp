#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdexcept>

class DataProcessor {
private:
    std::vector<int> data;
    std::string processorName;    

public:
    DataProcessor(const std::string& name) : processorName(name) {}    

    void addData(int value) {
        data.push_back(value);
    }

    void printData() const {
        std::cout << "Processor '" << processorName << "' Data: ";
        for (const int& value : data) {
            std::cout << value << " ";
        }
        std::cout << '\n';
    }

    // 1. REFACTORED: Validates range with std::all_of & parameter sanity check
    [[nodiscard]] bool validateDataRange(int min, int max) const {
        if (min > max) {
            return false; // Invalid boundary parameters
        }
        return std::all_of(data.begin(), data.end(), [min, max](int value) {
            return value >= min && value <= max;
        });
    }

    // 2. REFACTORED: Modern C++ erase_if idiom
    void removeOutliers(int threshold) {
        std::erase_if(data, [threshold](int value) { 
            return value < threshold; 
        });
    }

    struct Statistics {
        int minimum;
        int maximum;
        double average;
        double median;
    };    

    // 3. REFACTORED: Optimized single-pass min/max and O(N) median calculation
    [[nodiscard]] Statistics calculateStatistics() const {
        if (data.empty()) {
            return {0, 0, 0.0, 0.0}; // Safe fallback for empty state
        }

        Statistics stats{};

        // Single pass for min and max (O(N) vs 2 * O(N))
        const auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
        stats.minimum = *minIt;
        stats.maximum = *maxIt;

        // Average calculation
        const double sum = std::accumulate(data.begin(), data.end(), 0.0);
        stats.average = sum / static_cast<double>(data.size());

        // Median calculation using std::nth_element (O(N) vs O(N log N))
        std::vector<int> sortedData = data;
        const size_t mid = sortedData.size() / 2;

        if (sortedData.size() % 2 != 0) {
            std::nth_element(sortedData.begin(), sortedData.begin() + mid, sortedData.end());
            stats.median = sortedData[mid];
        } else {
            std::nth_element(sortedData.begin(), sortedData.begin() + mid, sortedData.end());
            const int upperMid = sortedData[mid];
            
            std::nth_element(sortedData.begin(), sortedData.begin() + mid - 1, sortedData.end());
            const int lowerMid = sortedData[mid - 1];

            stats.median = (static_cast<double>(lowerMid) + static_cast<double>(upperMid)) / 2.0;
        }

        return stats;
    }

    // Getters
    [[nodiscard]] const std::vector<int>& getData() const { return data; }
    [[nodiscard]] const std::string& getName() const { return processorName; }
    [[nodiscard]] size_t getDataSize() const { return data.size(); }
};