#include <iostream>
#include <string>
int main() {
    std::string text = "Hello world! The world is beautiful.";
    std::cout << "Original: " << text << std::endl;    
    // Replace "world" with "universe"
    size_t pos = text.find("world");
    if (pos != std::string::npos) {
        text.replace(pos, 5, "universe");
        std::cout << "After first replacement: " << text << std::endl;
    }
    // Your code here: Replace the second occurrence of "world" with "universe"
    // Hint: Use find() with a starting position parameter
        size_t secound_pos = text.find("world", pos + 1);
    if (secound_pos != std::string::npos) {
        text.replace(secound_pos, 5, "universe");
        std::cout << "After second replacement: " << text << std::endl;
    }
    // Your code here: Remove all exclamation marks from the text using erase()
    std::string::size_type exclamation_pos = text.find('!');
    while (exclamation_pos != std::string::npos) {
        text.erase(exclamation_pos, 1);
        exclamation_pos = text.find('!', exclamation_pos);
    }  
    // Convert text to uppercase (for each character, use std::toupper)
    for (char& c : text) {
        c = std::toupper(c);
    }
    std::cout << "Uppercase: " << text << std::endl;    
    return 0;
}