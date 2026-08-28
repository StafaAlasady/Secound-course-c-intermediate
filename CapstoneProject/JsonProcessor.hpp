#pragma once

#include <string>
#include <vector>
#include "DataRecord.hpp"
#include "json.hpp"

using json = nlohmann::json;

namespace JsonProcessor {
    // Standard file reader
    std::string readFileContent(const std::string& filename);

    // Parses string content into vector of DataRecords (Lab Spec)
    std::vector<DataRecord> parseData(const std::string& fileContent);

    // Saves output metrics to a file
    void writeJsonFile(const std::string& filename, const json& data, int indent = 4);
}