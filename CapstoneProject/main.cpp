#include <iostream>
#include "JsonProcessor.hpp"
#include "StatsAnalyzer.hpp"

int main() {
    try {
        // 1. Read input string
        std::string rawContent = JsonProcessor::readFileContent("data_input.json");

        // 2. Parse into vector of DataRecords
        std::vector<DataRecord> records = JsonProcessor::parseData(rawContent);
        std::cout << "Successfully parsed " << records.size() << " records.\n";

        // 3. Category 1: Statistical Calculations
        double avg = StatsAnalyzer::calculateAverageValue(records);
        double maxVal = StatsAnalyzer::getMaxValue(records);
        double minVal = StatsAnalyzer::getMinValue(records);

        // 4. Category 2: Filtering (Records with value >= 80.0)
        auto highValueRecords = StatsAnalyzer::filterByThreshold(records, 80.0);

        // 5. Category 3: Aggregation by Category
        auto categoryTotals = StatsAnalyzer::aggregateCategoryTotals(records);

        // 6. Build final output payload
        json outputData;
        outputData["recordCount"] = records.size();

        // Stats summary
        outputData["statistics"]["average"] = avg;
        outputData["statistics"]["max"] = maxVal;
        outputData["statistics"]["min"] = minVal;

        // Filtered results
        outputData["filteredSummary"]["highValueCount"] = highValueRecords.size();

        // Aggregated category totals map
        for (const auto& [category, total] : categoryTotals) {
            outputData["categoryTotals"][category] = total;
        }

        // Save output file
        JsonProcessor::writeJsonFile("processed_output.json", outputData);
        std::cout << "All analyses complete! Results saved to processed_output.json\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}