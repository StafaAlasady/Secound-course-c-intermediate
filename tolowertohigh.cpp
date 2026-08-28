#include <iostream>
#include <string>
#include <cctype>
#include <map> // Optional: helpful for storing letter -> count pairs

void analyzeCharacterFrequency(const std::string& text) {
    // 1. Create your storage structure (e.g., std::map<char, int> counts;)
    std::map<char, int> counts;

    // 2. Loop through every character in text
    //    - Filter with std::isalpha()
    //    - Convert with std::tolower()
    //    - Increment its count in your storage structure
    for (char c : text) {
        if (std::isalpha(c)) {
            c = std::tolower(c);
            counts[c]++;
        }
    }

    // 3. Print out each letter and its frequency count
    for (const auto& pair : counts) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    std::string sample = "Hello, World! 123";
    analyzeCharacterFrequency(sample);
    return 0;
}