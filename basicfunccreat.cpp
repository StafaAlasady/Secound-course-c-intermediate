#include <iostream>
#include <string>
#include <vector>
// Function to display employee information (pass-by-value for simple types)
void displayEmployee(int id, std::string name, double salary, double bonus) {
    std::cout << "Employee ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Salary: $" << salary << std::endl;
    std::cout << "Salary Bonus: %" << bonus << std::endl;
    std::cout << "------------------------" << std::endl;
}
// Function to calculate annual salary from monthly salary
double calculateAnnualSalary(double monthlySalary) {
    return monthlySalary * 12;
}

double calculateBonus( double BonusCalc){
    return BonusCalc / 10.0;
}
int main() {
    // Test the functions
    displayEmployee(101, "Alice Johnson", 5500.0, 10);
    double monthly = 4200.0;
    double annual = calculateAnnualSalary(monthly);
    double Bonus = calculateBonus(monthly);
    double BonusSalary = Bonus + monthly;
    std::cout << "Monthly: $" << monthly << " -> Annual: $" << annual << std::endl;
    std::cout << "Salary Bonus: $" << Bonus << ", Salary plus bonus: $"<< BonusSalary << std::endl;
    return 0;
}