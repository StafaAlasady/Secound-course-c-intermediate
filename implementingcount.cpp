#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

int main() {
    int word_count = 0;
    std::string text = "The Quick Brown Fox Jumps Over The Lazy Dog";

    // Count words using stringstream
    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        ++word_count;
    }

    std::cout << "Word count: " << word_count << std::endl;

    return 0;
}