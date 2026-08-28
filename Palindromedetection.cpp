#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

 bool isPalindrome(const std::string& text) {
    //filtering non alphanumeric chars
    std::string clean_text = "";
    for (char c : text) {
        if (std::isalnum(c)) {
            clean_text += std::tolower(c);
        }
    }
    std::string reversed_text = clean_text;
    std::reverse(reversed_text.begin(), reversed_text.end());
    return clean_text == reversed_text;
}
int main() {
    std::string text = "A man, a plan, a canal: Panama";
    if (isPalindrome(text)) {
        std::cout << "\"" << text << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << text << "\" is not a palindrome." << std::endl;
    }
    return 0;
}
