#include "JsonProcessor.hpp"
#include <fstream>
#include <stdexcept>

namespace JsonProcessor {

    std::string readFileContent(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open input file: " + filename);
        }
        
        return std::string((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
    }

    std::vector<DataRecord> parseData(const std::string& fileContent) {
        if (fileContent.empty()) {
            throw std::runtime_error("File content is empty.");
        }

        json j = json::parse(fileContent);
        std::vector<DataRecord> records;

        // Expecting a JSON array of record objects
        for (const auto& item : j) {
            DataRecord record;
            if (item.contains("id"))       record.id = item["id"].get<std::string>();
            if (item.contains("name"))     record.name = item["name"].get<std::string>();
            if (item.contains("age"))      record.age = item["age"].get<int>();
            if (item.contains("value"))    record.value = item["value"].get<double>();
            if (item.contains("category")) record.category = item["category"].get<std::string>();

            records.push_back(record);
        }

        return records;
    }

    void writeJsonFile(const std::string& filename, const json& data, int indent) {
        std::ofstream file(filename, std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            throw std::runtime_error("Could not create output file: " + filename);
        }
        file << data.dump(indent);
    }

} // namespace JsonProcessor