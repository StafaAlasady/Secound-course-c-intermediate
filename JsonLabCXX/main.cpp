#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Loads and parses a JSON file with full error handling
json loadConfigFromFile(const std::string& filename) {
    // 1. Open the file stream
    std::ifstream file(filename);

    // 2. Check if the file opened successfully (handles file not found / permission issues)
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename + " (File not found or permission denied)");
    }

    // 3. Parse JSON directly from the input stream
    json config;
    file >> config; // Throws json::parse_error if the file content is invalid JSON

    return config;
}

// Function to print configuration data including arrays
void displayConfig(const json& config) {
    std::cout << "\n--- Configuration Loaded ---\n";
    std::cout << "App Name:        " << config.value("app_name", "Unknown") << "\n";
    std::cout << "Version:         " << config.value("version", "0.0.0") << "\n";
    std::cout << "Debug Mode:      " << (config.value("debug_mode", false) ? "Enabled" : "Disabled") << "\n";
    std::cout << "Max Connections: " << config.value("max_connections", 0) << "\n";

    // Accessing and displaying JSON arrays
    if (config.contains("features") && config["features"].is_array()) {
        std::cout << "Enabled Features:\n";
        for (const auto& feature : config["features"]) {
            std::cout << "  - " << feature.get<std::string>() << "\n";
        }
    }
    std::cout << "----------------------------\n\n";
}

int main() {
    std::cout << "Configuration Manager v2.0" << std::endl;    
    
    try {
        // First, create a sample config file on disk
        std::ofstream configFile("config.json");
        configFile << R"({
            "app_name": "FileBasedApp",
            "version": "2.0.0",
            "debug_mode": false,
            "max_connections": 200,
            "features": ["logging", "caching", "monitoring"]
        })";
        configFile.close();        

        // Test 1: Load and display valid configuration file
        std::cout << "\n[Test 1] Loading 'config.json'...\n";
        json config = loadConfigFromFile("config.json");
        displayConfig(config);

        // Test 2: Test error handling with a missing file
        std::cout << "[Test 2] Attempting to load missing file...\n";
        json missingConfig = loadConfigFromFile("non_existent_file.json");

    } catch (const json::parse_error& e) {
        std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }    
    
    return 0;
}