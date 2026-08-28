#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
// Note: std::format requires C++20. If unavailable, we'll use traditional formatting
#include <format> // Uncomment if available
struct Product {
    std::string name;
    double price;
    int quantity;
    double total() const { return price * quantity; }
};
int main() {

    double TAX_RATE = 0.085;
    std::vector<Product> products = {
        {"Laptop", 999.99, 2},
        {"Mouse", 29.50, 5},
        {"Keyboard", 89.99, 3}
    };    
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "INVOICE SUMMARY" << std::endl;
    std::cout << std::string(50, '=') << std::endl;    
    // Traditional formatting (works on all compilers)
    std::cout << std::left << std::setw(15) << "Product" 
              << std::right << std::setw(8) << "Price"
              << std::right << std::setw(8) << "Qty"
              << std::right << std::setw(10) << "Total" << std::endl;
    std::cout << std::string(50, '-') << std::endl;  

    double grandTotal = 0.0;
    for (const auto& product : products) {
        std::cout << std::left << std::setw(15) << product.name
                  << std::right << std::setw(7) << std::fixed << std::setprecision(2) 
                  << "$" << product.price
                  << std::right << std::setw(8) << product.quantity
                  << std::right << std::setw(9) << "$" << std::fixed 
                  << std::setprecision(2) << product.total() << std::endl;
        grandTotal += product.total();
    }
    
    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::right << std::setw(41) << "GRAND TOTAL: $"
              << std::fixed << std::setprecision(2) << grandTotal << std::endl;    
    //Modern formatting example (uncomment if C++20 is available)
    
    //std::cout << std::format("Tax (8.5%): ${:.2f}\n", grandTotal * 0.085);
    //std::cout << std::format("Final Total: ${:.2f}\n", grandTotal * 1.085);

    //tax calculation!
    double taxAmount = grandTotal * TAX_RATE;
    double finalTotal = grandTotal + taxAmount;

    // Totals Breakdown
    std::cout << std::string(50, '-') << std::endl;
    
    std::cout << std::right << std::setw(40) << "Subtotal: $"
              << std::setw(10) << grandTotal << std::endl;
    
    std::cout << std::right << std::setw(40) << "Tax (8.5%): $"
              << std::setw(10) << taxAmount << std::endl;
              
    std::cout << std::string(50, '-') << std::endl;
    
    std::cout << std::right << std::setw(40) << "FINAL TOTAL: $"
              << std::setw(10) << finalTotal << std::endl;
        
    return 0;
}
