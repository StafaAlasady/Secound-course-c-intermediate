#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

int main() {
    std::string name;
    int customerID;
    double balance;
    // Collect customer name
    std::cout << "Enter customer name: ";
    std::getline(std::cin, name);
    // Collect and validate customer ID
    std::cout << "Enter customer ID (1000-9999): ";
    while (!(std::cin >> customerID) || customerID < 1000 || customerID > 9999) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid customer ID (1000-9999): ";
    }
    
    // Collect and validate balance
    std::cout << "Enter account balance: $";
    while (!(std::cin >> balance) || balance < 0.0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid balance (0 or higher): ";
    }

    // Display formatted output
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Customer Name: " << name << std::endl;
    std::cout << "Customer ID: " << customerID << std::endl;
    std::cout << "Account Balance: $" << balance << std::endl;

    return 0;
}