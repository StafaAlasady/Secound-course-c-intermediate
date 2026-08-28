#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
int main() {
    // C-style string operations
    const char* c_str = "Hello";
    char c_buffer[20];
    strcpy(c_buffer, c_str);
    strcat(c_buffer, " World");
    std::cout << "C-style result: " << c_buffer << std::endl;
    std::cout << "C-style length: " << strlen(c_buffer) << std::endl;
    // std::string operations
    std::string cpp_str = "Hello";
    cpp_str += " World";
    std::cout << "std::string result: " << cpp_str << std::endl;
    std::cout << "std::string length: " << cpp_str.length() << std::endl;    
    // Your code here: Demonstrate safe bounds checking
    // Try to access character at index 15 in both strings
    std::cout << "Unsafe access c_buffer[15]: " << c_buffer[15] << std::endl;

    try
    {
        std::cout << "Safe access cpp_str.at(15): " << cpp_str.at(15) << std::endl;
    }
    catch(const std::out_of_range& e){
        std::cout << "Caught an out_of_range exception: " << e.what() << std::endl;
    }


    // Your code here: Show what happens when you try to concatenate
    std::cout << "\n--- Buffer Overflow Hazard ---" << std::endl;
    // a very long string to c_buffer (comment out to avoid crash)
    // strcat(c_buffer, " This is a very long string that will cause overflow");
    cpp_str += " This is a very long string that automatically resizes memory safely!";
    std::cout << "Safe C++ string result: " << cpp_str << std::endl;
    return 0;
}