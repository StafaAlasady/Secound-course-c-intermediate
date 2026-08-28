#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <format>

struct Item {
    std::string name;
    double price = 0.0;
    int quantity = 0;
};

// ==========================================
// 1. HELPER: Create Test Files
// ==========================================
void createSampleFiles() {
    // Create sample.csv (includes an edge-case row with a missing field)
    std::ofstream csvFile("sample.csv");
    csvFile << "Name,Price,Quantity\n";
    csvFile << "Laptop,999.99,2\n";
    csvFile << "Mouse,29.50,5\n";
    csvFile << "BadRow,19.99\n"; // Missing quantity field (edge case!)
    csvFile << "Keyboard,89.99,3\n";
    csvFile.close();

    // Create sample.json
    std::ofstream jsonFile("sample.json");
    jsonFile << "[\n";
    jsonFile << "  { \"name\": \"Monitor\", \"price\": 199.99, \"quantity\": 1 },\n";
    jsonFile << "  { \"name\": \"Headphones\", \"price\": 49.99, \"quantity\": 4 },\n";
    jsonFile << "  { \"name\": \"Desk Lamp\" }\n"; // Missing price and quantity (edge case!)
    jsonFile << "]\n";
    jsonFile.close();

    std::cout << "[System] Generated sample.csv and sample.json files.\n\n";
}

void logMessage(const std::string& message){
    std::ofstream logFile("log.txt", std::ios::app);

    if(logFile.is_open()){
        logFile << message << "\n";
    } else{
        std::cerr << " failed to open log.txt.\n";
    }
}
// ==========================================
// 2. CSV PARSER
// ==========================================
std::vector<Item> parseCSV(const std::string& filename) {
    std::vector<Item> items;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << std::format("Error: Could not open {}\n", filename);
        return items;
    }

    std::string line;
    bool isHeader = true;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        if (line.empty()) continue;

        // Skip CSV Header row
        if (isHeader) {
            isHeader = false;
            continue;
        }

        std::istringstream ss(line);
        std::string nameStr, priceStr, qtyStr;

        // Read fields separated by commas
        std::getline(ss, nameStr, ',');
        std::getline(ss, priceStr, ',');
        std::getline(ss, qtyStr, ',');

        // EDGE CASE CHECK: Ensure all 3 fields exist and aren't empty
        if (nameStr.empty() || priceStr.empty() || qtyStr.empty()) {
            std::cerr << std::format("CSV Warning (Line {}): Missing fields in row '{}'. Skipping.\n", lineNumber, line);
            continue;
        }

        try {
            Item item;
            item.name = nameStr;
            item.price = std::stod(priceStr);
            item.quantity = std::stoi(qtyStr);
            items.push_back(item);
        } catch (const std::exception& e) {
            std::cerr << std::format("CSV Warning (Line {}): Conversion error in row '{}'. Skipping.\n", lineNumber, line);
        }
    }

    return items;
}

// ==========================================
// 3. JSON PARSER
// ==========================================
std::vector<Item> parseJSON(const std::string& filename) {
    std::vector<Item> items;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << std::format("Error: Could not open {}\n", filename);
        return items;
    }

    try {
        std::string content((std::istreambuf_iterator<char>(file)),
                             std::istreambuf_iterator<char>());

        std::regex objectRegex(R"(\{([^}]+)\})");
        std::regex nameRegex(R"(\"name\"\s*:\s*\"([^\"]+)\")");
        std::regex priceRegex(R"(\"price\"\s*:\s*([0-9.]+))");
        std::regex qtyRegex(R"(\"quantity\"\s*:\s*([0-9]+))");

        auto objectBegin = std::sregex_iterator(content.begin(), content.end(), objectRegex);
        auto objectEnd = std::sregex_iterator();

        int objectCount = 0;

        for (std::sregex_iterator i = objectBegin; i != objectEnd; ++i) {
            objectCount++;
            std::string objectBlock = i->str();

            std::smatch match;
            Item item;
            bool hasName = false, hasPrice = false, hasQty = false;

            if (std::regex_search(objectBlock, match, nameRegex)) {
                item.name = match[1].str();
                hasName = true;
            }

            if (std::regex_search(objectBlock, match, priceRegex)) {
                try {
                    item.price = std::stod(match[1].str());
                    hasPrice = true;
                } catch (const std::exception& e) {
                    std::cerr << std::format("JSON Error (Object {}): Invalid price '{}' ({})\n", 
                                             objectCount, match[1].str(), e.what());
                }
            }

            if (std::regex_search(objectBlock, match, qtyRegex)) {
                try {
                    item.quantity = std::stoi(match[1].str());
                    hasQty = true;
                } catch (const std::exception& e) {
                    std::cerr << std::format("JSON Error (Object {}): Invalid quantity '{}' ({})\n", 
                                             objectCount, match[1].str(), e.what());
                }
            }

            if (hasName && hasPrice && hasQty) {
                items.push_back(item);
            } else {
                std::cerr << std::format("JSON Warning (Object {}): Missing required fields. Skipping.\n", objectCount);
            }
        }
    } catch (const std::regex_error& e) {
        std::cerr << std::format("JSON Regex Error: Pattern matching failed: {}\n", e.what());
    } catch (const std::exception& e) {
        std::cerr << std::format("JSON General Error: {}\n", e.what());
    }

    return items;
}

// ==========================================
// 4. MAIN & DISPLAY
// ==========================================
void printTable(const std::string& title, const std::vector<Item>& items) {
    std::cout << std::format("\n=== {} ===\n", title);
    std::cout << std::format("{:<15} {:>8} {:>8} {:>10}\n", "Name", "Price", "Qty", "Total");
    std::cout << std::string(45, '-') << '\n';

    double grandTotal = 0.0;
    for (const auto& item : items) {
        double lineTotal = item.price * item.quantity;
        grandTotal += lineTotal;

        std::cout << std::format("{:<15} ${:>7.2f} {:>8} ${:>9.2f}\n",
                                 item.name, item.price, item.quantity, lineTotal);
    }
    std::cout << std::string(45, '-') << '\n';
    std::cout << std::format("{:>32} ${:>9.2f}\n", "GRAND TOTAL:", grandTotal);
}

int main() {
    // Step 1: Generate sample files
    createSampleFiles();
    logMessage("INFO starting application");

    // Step 2: Read & Parse CSV
    std::cout << "--- Parsing CSV File --- \n";
    std::vector<Item> csvItems = parseCSV("sample.csv");
    printTable("CSV DATA IMPORT", csvItems);
    logMessage("[INFO] Read the CSV file...");

    std::cout << "\n";

    // Step 3: Read & Parse JSON
    std::cout << "--- Parsing JSON File --- \n";
    std::vector<Item> jsonItems = parseJSON("sample.json");
    printTable("JSON DATA IMPORT", jsonItems);
    logMessage("[INFO] Read the json file");

    logMessage("application finished running");

    return 0;
}