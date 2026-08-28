// test_data_processor.cpp - Testing framework
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <string>

// Include your DataProcessor definition
#include "AiFunctionIntegration.cpp" // Or paste class DataProcessor here if in single file

class TestRunner {
private:
    int testsRun = 0;
    int testsPassed = 0;    
public:
    void runTest(const std::string& testName, bool testResult) {
        testsRun++;
        std::cout << "Test '" << testName << "': ";        
        if (testResult) {
            testsPassed++;
            std::cout << "PASSED" << std::endl;
        } else {
            std::cout << "FAILED" << std::endl;
        }
    }    
    void printSummary() const {
        std::cout << "\n=== Test Summary ===" << std::endl;
        std::cout << "Tests run: " << testsRun << std::endl;
        std::cout << "Tests passed: " << testsPassed << std::endl;
        std::cout << "Success rate: " << (testsRun > 0 ? (testsPassed * 100.0 / testsRun) : 0) << "%" << std::endl;
    }
};

bool testValidateDataRange() {
    // 1. Empty data
    DataProcessor emptyProc("Empty");
    if (!emptyProc.validateDataRange(1, 10)) return false;

    // Setup populated processor
    DataProcessor proc("RangeProc");
    for (int v : {1, 2, 3, 4, 5}) {
        proc.addData(v);
    }

    // 2. All values in range [1, 5]
    if (!proc.validateDataRange(1, 5)) return false;

    // 3. Some values out of range [2, 4] (1 and 5 are outside)
    if (proc.validateDataRange(2, 4)) return false;

    // 4. Edge cases: boundary values
    if (!proc.validateDataRange(1, 5)) return false; // Exact min/max boundaries

    // 5. Invalid range parameters (min > max) -> should fail validation
    if (proc.validateDataRange(5, 1)) return false;

    return true;
}

bool testRemoveOutliers() {
    // 1. Empty data
    DataProcessor emptyProc("Empty");
    emptyProc.removeOutliers(5);
    if (emptyProc.getDataSize() != 0) return false;

    // Setup populated processor
    DataProcessor proc("OutlierProc");
    for (int v : {1, 2, 3, 4, 5}) {
        proc.addData(v);
    }

    // 2. Negative threshold (no values removed if threshold is -1)
    proc.removeOutliers(-1);
    if (proc.getDataSize() != 5) return false;

    // 3. No outliers to remove (threshold <= 1)
    proc.removeOutliers(1);
    if (proc.getDataSize() != 5) return false;

    // 4. Mixed data: remove values below 3 (removes 1 and 2, leaves 3, 4, 5)
    proc.removeOutliers(3);
    if (proc.getData() != std::vector<int>({3, 4, 5})) return false;

    // 5. All values are outliers (threshold = 100)
    proc.removeOutliers(100);
    if (proc.getDataSize() != 0) return false;

    return true;
}

bool testCalculateStatistics() {
    // 1. Empty data handling
    DataProcessor emptyProc("Empty");
    auto emptyStats = emptyProc.calculateStatistics();
    if (emptyStats.minimum != 0 || emptyStats.maximum != 0 || 
        emptyStats.average != 0.0 || emptyStats.median != 0.0) {
        return false;
    }

    // 2. Single value dataset
    DataProcessor singleProc("Single");
    singleProc.addData(42);
    auto singleStats = singleProc.calculateStatistics();
    if (singleStats.minimum != 42 || singleStats.maximum != 42 || 
        singleStats.average != 42.0 || singleStats.median != 42.0) {
        return false;
    }

    // 3. Odd number of values (median check: middle element)
    DataProcessor oddProc("Odd");
    for (int v : {1, 3, 2, 5, 4}) oddProc.addData(v); // {1, 2, 3, 4, 5} -> median 3.0
    auto oddStats = oddProc.calculateStatistics();
    if (oddStats.median != 3.0 || oddStats.average != 3.0) return false;

    // 4. Even number of values (median check: average of two middle elements)
    DataProcessor evenProc("Even");
    for (int v : {1, 2, 3, 4}) evenProc.addData(v); // median (2 + 3) / 2.0 = 2.5
    auto evenStats = evenProc.calculateStatistics();
    if (evenStats.median != 2.5 || evenStats.average != 2.5) return false;

    // 5. Duplicate values dataset
    DataProcessor dupProc("Duplicates");
    for (int v : {5, 5, 5, 5}) dupProc.addData(v);
    auto dupStats = dupProc.calculateStatistics();
    if (dupStats.minimum != 5 || dupStats.maximum != 5 || dupStats.average != 5.0) return false;

    // 6. Negative values dataset
    DataProcessor negProc("Negative");
    for (int v : {-5, -3, -1}) negProc.addData(v);
    auto negStats = negProc.calculateStatistics();
    if (negStats.minimum != -5 || negStats.maximum != -1 || negStats.average != -3.0) return false;

    return true;
}

int main() {
    std::cout << "Data Processor Test Suite" << std::endl;
    std::cout << "=========================" << std::endl;    
    
    TestRunner runner;    
    
    // Run all tests
    runner.runTest("validateDataRange", testValidateDataRange());
    runner.runTest("removeOutliers", testRemoveOutliers());
    runner.runTest("calculateStatistics", testCalculateStatistics());    
    
    runner.printSummary();    
    
    return 0;
}