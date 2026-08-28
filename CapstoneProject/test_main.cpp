#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include "DataRecord.hpp"
#include "StatsAnalyzer.hpp"

// Helper function to compare floating point numbers
bool isClose(double a, double b, double epsilon = 0.0001) {
    return std::fabs(a - b) < epsilon;
}

// -------------------------------------------------------------
// Test Case 1: Statistical Calculations
// -------------------------------------------------------------
void testStatistics() {
    std::cout << "[TEST] Running testStatistics...\n";

    std::vector<DataRecord> records;
    
    DataRecord r1; r1.value = 10.0;
    DataRecord r2; r2.value = 20.0;
    DataRecord r3; r3.value = 30.0;
    
    records.push_back(r1);
    records.push_back(r2);
    records.push_back(r3);

    // Verify Average
    double avg = StatsAnalyzer::calculateAverageValue(records);
    assert(isClose(avg, 20.0));

    // Verify Max & Min
    assert(isClose(StatsAnalyzer::getMaxValue(records), 30.0));
    assert(isClose(StatsAnalyzer::getMinValue(records), 10.0));

    std::cout << "  [PASS] testStatistics\n";
}

// -------------------------------------------------------------
// Test Case 2: Filtering Operations
// -------------------------------------------------------------
void testFiltering() {
    std::cout << "[TEST] Running testFiltering...\n";

    std::vector<DataRecord> records;
    DataRecord r1; r1.value = 50.0;
    DataRecord r2; r2.value = 85.0;
    DataRecord r3; r3.value = 95.0;

    records.push_back(r1);
    records.push_back(r2);
    records.push_back(r3);

    // Filter threshold >= 80.0
    auto filtered = StatsAnalyzer::filterByThreshold(records, 80.0);
    
    assert(filtered.size() == 2);
    assert(isClose(filtered[0].value, 85.0));
    assert(isClose(filtered[1].value, 95.0));

    std::cout << "  [PASS] testFiltering\n";
}

// -------------------------------------------------------------
// Test Case 3: Category Aggregation
// -------------------------------------------------------------
void testCategoryAggregation() {
    std::cout << "[TEST] Running testCategoryAggregation...\n";

    std::vector<DataRecord> records;
    
    DataRecord r1; r1.category = "Sales";      r1.value = 100.0;
    DataRecord r2; r2.category = "Engineering"; r2.value = 150.0;
    DataRecord r3; r3.category = "Sales";      r3.value = 50.0;

    records.push_back(r1);
    records.push_back(r2);
    records.push_back(r3);

    auto totals = StatsAnalyzer::aggregateCategoryTotals(records);

    assert(totals.size() == 2);
    assert(isClose(totals["Sales"], 150.0));
    assert(isClose(totals["Engineering"], 150.0));

    std::cout << "  [PASS] testCategoryAggregation\n";
}

// -------------------------------------------------------------
// Test Case 4: Edge Cases & Exception Handling
// -------------------------------------------------------------
void testEdgeCases() {
    std::cout << "[TEST] Running testEdgeCases...\n";

    std::vector<DataRecord> emptyRecords;

    // Average of empty set should return 0.0
    assert(isClose(StatsAnalyzer::calculateAverageValue(emptyRecords), 0.0));

    // Max/Min of empty set should throw std::invalid_argument
    bool maxThrew = false;
    try {
        StatsAnalyzer::getMaxValue(emptyRecords);
    } catch (const std::invalid_argument&) {
        maxThrew = true;
    }
    assert(maxThrew);

    std::cout << "  [PASS] testEdgeCases\n";
}

int main() {
    std::cout << "========================================\n";
    std::cout << "       RUNNING CAPSTONE TEST SUITE      \n";
    std::cout << "========================================\n";

    testStatistics();
    testFiltering();
    testCategoryAggregation();
    testEdgeCases();

    std::cout << "========================================\n";
    std::cout << "   ALL TESTS PASSED SUCCESSFULLY! (4/4) \n";
    std::cout << "========================================\n";

    return 0;
}