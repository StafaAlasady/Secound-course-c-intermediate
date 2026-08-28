#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

int main() {
    std::string name;
    int customerID;
    double balance;

    std::cout << "Enter customer name: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid name: ";
    }

// 4. Validate Balance (must be non-negative)
    std::cout << "Enter Balance: ";
    while (!(std::cin >> balance) || balance < 0.0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid balance (0 or higher): ";
    }

// 3. Validate Customer ID (must be positive)
    std::cout << "Enter Customer ID: ";
    while (!(std::cin >> customerID) || customerID <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a positive Customer ID: ";
    }

    std::cout << std::endl; // Clean spacing before table display
    // Header
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << "CUSTOMER INFORMATION" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;    
    // Data display
    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::setw(15) << "Customer ID:" << customerID << std::endl;
    std::cout << std::setw(15) << "Balance:" << std::fixed << std::setprecision(2) << "$" << balance << std::endl;    
    return 0;
}
