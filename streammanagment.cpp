#include <iostream>
#include <limits>
#include <string>
int main() {
    std::string productName;
    double price;
    int quantity;
    std::cout << "Enter product name: ";
    std::getline(std::cin, productName);
    while (productName.empty()) {
        // Check what went wrong
        std::cerr << "Error: Please enter a name for the product. Enter atleast a letter." << std::endl;
        std::cout << " please Enter a product name: ";
        std::getline(std::cin, productName);
    }
    std::cout << "Enter product price: $";
    while (!(std::cin >> price) || price < 0) {
        // Check what went wrong
        if (std::cin.fail()) {
            std::cerr << "Error: Invalid price format. Please enter a number." << std::endl;
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cerr << "Error: Price cannot be negative." << std::endl;
        }
        std::cout << "Enter product price: $";
    }    
    std::cout << "Enter quantity: ";
    while (!(std::cin >> quantity) || quantity < 1) {
        if (std::cin.fail()) {
            std::cerr << "Error: Invalid quantity format. Please enter a whole number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cerr << "Error: Quantity must be at least 1." << std::endl;
        }
        std::cout << "Enter quantity: ";
    }    
    std::cout << "Valid input received!" << std::endl;
    std::cout << "Price: $" << price << ", Quantity: " << quantity << std::endl;    
    return 0;
}