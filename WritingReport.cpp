#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
int main() {
    std::ofstream reportFile("sales_report.txt", std::ios::app);    
    if (!reportFile) {
        std::cerr << "Error: Could not create sales report file" << std::endl;
        return 1;
    }    
    // Write report header
    reportFile << "DAILY SALES REPORT" << std::endl;
    reportFile << "==================" << std::endl;
    reportFile << std::left << std::setw(15) << "Product" 
               << std::setw(10) << "Quantity" 
               << std::setw(10) << "Price" << std::endl;    
    // Sample sales data
    reportFile << std::left << std::setw(15) << "Laptop" 
               << std::setw(10) << "5" 
               << "$" << std::fixed << std::setprecision(2) << 999.99 << std::endl;    
    reportFile << std::left << std::setw(15) << "Mouse" 
               << std::setw(10) << "12" 
               << "$" << std::fixed << std::setprecision(2) << 29.99 << std::endl;
    reportFile << std::left << std::setw(15) << "House/mansion" 
               << std::setw(10) << "5" 
               << "$" << std::fixed << std::setprecision(2) << 90009990.99 << std::endl;
    reportFile << std::left << std::setw(15) << "Cars" 
               << std::setw(10) << "5" 
               << "$" << std::fixed << std::setprecision(2) << 9000099.99 << std::endl;
    reportFile << std::left << std::setw(15) << "Helicopter" 
               << std::setw(10) << "5" 
               << "$" << std::fixed << std::setprecision(2) << 5900099.99 << std::endl;
    reportFile.close();    
    std::cout << "Sales report generated successfully!" << std::endl;    
    return 0;
}