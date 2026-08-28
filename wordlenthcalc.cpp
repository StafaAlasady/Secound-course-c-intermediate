#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

double calculateAverageWordLength(const std::string& text) {
    std::string cleanText = text;
    for (char &c : cleanText) {
        if (std::ispunct(c)) {
            c = ' ';
        }
    }

    std::istringstream stream(cleanText);
    std::string word;
    int totalLength = 0;
    int wordCount = 0;

    while (stream >> word) {
        totalLength += word.length();
        ++wordCount;
    }

    // 3. Safe guard against division by zero!
    if (wordCount == 0) return 0.0;

    return static_cast<double>(totalLength) / wordCount;
}


int main() {
    std::string text = "The Quick Brown Fox Jumps Over The Lazy Dog";
    double averageLength = calculateAverageWordLength(text);
    std::cout << "Average word length: " << averageLength << std::endl;
    return 0;
}