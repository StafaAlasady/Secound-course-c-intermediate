#include <iostream>
#include <string>
int main() {
    std::string message = "Welcome to the world of C++ programming!";
    std::cout << "Original message: " << message << std::endl;    
    // Extract the first word using substr()
    size_t first_space = message.find(' ');
    if (first_space != std::string::npos) {
        std::string first_word = message.substr(0, first_space);
        std::cout << "First word: " << first_word << std::endl;
    }    
    // Your code here: Find and extract the last word using rfind() and substr()
    std::size_t last_space = message.rfind(' ');
    if (last_space != std::string::npos) {
        std::string last_word = message.substr(last_space + 1);
        std::cout << "Last word: " << last_word << std::endl;
    }
    // Your code here: Count how many times the letter 'o' appears in the message
    int count_o = 0;

    for (char c: message) {
        if (c == 'o')
            count_o++;
    }
    std::cout << "Count of 'o': " << count_o << std::endl;
    return 0;
}
