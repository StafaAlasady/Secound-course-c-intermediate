#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
int main() {
    std::string text = "The Quick Brown Fox Jumps Over The Lazy Dog";
    std::cout << "Analyzing: " << text << std::endl;    
    // Count words (spaces + 1)
    int word_count = std::count(text.begin(), text.end(), ' ') + 1;
    std::cout << "Word count: " << word_count << std::endl;    
    // Your code here: Count vowels (a, e, i, o, u) - case insensitive
    int vowel_count = 0;
    for (char c : text) {
        c = std::tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++vowel_count;
        }
    }
    std::cout << "Vowel count: " << vowel_count << std::endl;

    // Your code here: Find the longest word in the text
    std::string longest_word;
    size_t max_length = 0;
    size_t start = 0;
    while (start < text.length()) {
        size_t end = text.find(' ', start);
        if (end == std::string::npos) end = text.length();
        std::string word = text.substr(start, end - start);
        if (word.length() > max_length) {
            max_length = word.length();
            longest_word = word;
        }
        start = end + 1;
    }
    std::cout << "Longest word: " << longest_word << std::endl;

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // 1. Create a lowercase copy of text
    std::string text_lower = text;
    for (char &c : text_lower) {
        c = std::tolower(c);
    }

    // 2. Check if every lowercase alphabet letter is inside text_lower
    bool is_pangram = true;
    for (char c : alphabet) {
        if (text_lower.find(c) == std::string::npos) {
            is_pangram = false;
            break;
        }
    }
    std::cout << "Is pangram: " << (is_pangram ? "Yes" : "No") << std::endl;
    return 0;
}