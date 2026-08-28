#include <iostream>
#include <fstream>
#include <string>
int main() {
    // Create a simple products.txt file with these contents:
    // Laptop
    // Mouse
    // Keyboard
    // Monitor    
    std::ifstream inputFile("whatiwantinlife.txt");    
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open whatiwantinlife.txt" << std::endl;
        return 1;
    }    
    std::string productName;
    int count = 0;    
    std::cout << "Product Inventory:" << std::endl;
    while (std::getline(inputFile, productName)) {
        count++;
        std::cout << count << ". " << productName << std::endl;
    }    
    inputFile.close();
    std::cout << "Total products: " << count << std::endl;    
    return 0;
}