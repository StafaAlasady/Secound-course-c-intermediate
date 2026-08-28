#pragma once

#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <map>
#include <stdexcept>
#include "DataRecord.hpp"

namespace StatsAnalyzer {

    // ==========================================
    // 1. STATISTICAL CALCULATIONS
    // ==========================================
    inline double calculateAverageValue(const std::vector<DataRecord>& records) {
        if (records.empty()) return 0.0;
        double sum = 0.0;
        for (const auto& rec : records) {
            sum += rec.value;
        }
        return sum / static_cast<double>(records.size());
    }

    inline double getMaxValue(const std::vector<DataRecord>& records) {
        if (records.empty()) throw std::invalid_argument("Records vector is empty.");
        auto maxIt = std::max_element(records.begin(), records.end(),
            [](const DataRecord& a, const DataRecord& b) { return a.value < b.value; });
        return maxIt->value;
    }

    inline double getMinValue(const std::vector<DataRecord>& records) {
        if (records.empty()) throw std::invalid_argument("Records vector is empty.");
        auto minIt = std::min_element(records.begin(), records.end(),
            [](const DataRecord& a, const DataRecord& b) { return a.value < b.value; });
        return minIt->value;
    }

    // ==========================================
    // 2. FILTERING OPERATIONS
    // ==========================================
    // Filters records where 'value' is greater than or equal to a threshold
    inline std::vector<DataRecord> filterByThreshold(const std::vector<DataRecord>& records, double threshold) {
        std::vector<DataRecord> filtered;
        for (const auto& rec : records) {
            if (rec.value >= threshold) {
                filtered.push_back(rec);
            }
        }
        return filtered;
    }

    // ==========================================
    // 3. AGGREGATION BY CATEGORY
    // ==========================================
    // Aggregates total 'value' grouped by record category
    inline std::map<std::string, double> aggregateCategoryTotals(const std::vector<DataRecord>& records) {
        std::map<std::string, double> categoryTotals;
        for (const auto& rec : records) {
            categoryTotals[rec.category] += rec.value;
        }
        return categoryTotals;
    }

    // ==========================================
    // 4. DATA TRANSFORMATIONS
    // ==========================================
    // Normalizes record values to a 0.0 - 1.0 scale
    inline std::vector<DataRecord> normalizeValues(const std::vector<DataRecord>& records) {
        if (records.empty()) return {};

        double minVal = getMinValue(records);
        double maxVal = getMaxValue(records);
        double range = maxVal - minVal;

        std::vector<DataRecord> normalized = records;
        for (auto& rec : normalized) {
            rec.value = (range == 0.0) ? 0.0 : (rec.value - minVal) / range;
        }
        return normalized;
    }

} // namespace StatsAnalyzer