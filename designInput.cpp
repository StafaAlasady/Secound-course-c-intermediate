#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

int main()
{
    std::string birth;
    std::string name;
    std::string Email;
    std::string address;
    int age = 0;
    int Date = 0;
    double Score = 0.0;

    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your email: ";
    std::getline(std::cin >> std::ws, Email);

    std::cout << "Enter your birth date (DD/MM/YYYY): ";
    std::getline(std::cin >> std::ws, birth);

    std::cout << "Enter your address: ";
    std::getline(std::cin >> std::ws, address);

    std::cout << "Enter your age: ";
    while (!(std::cin >> age) || age < 0 || age > 120)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an age between 0 and 120: ";
    }

    std::cout << "Enter your score: ";

    while (!(std::cin >> Score) || Score < 0.00 || Score > 150.00)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a score between 0.00 and 150.00: ";
    }

    // Report output
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << "Student Report" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;

    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::setw(15) << "DOB:" << birth << std::endl;
    std::cout << std::setw(15) << "Email:" << Email << std::endl;
    std::cout << std::setw(15) << "Address:" << address << std::endl;
    std::cout << std::setw(15) << "Age:" << age << std::endl;
    std::cout << std::setw(15) << "Score:" << std::fixed << std::setprecision(2) << Score << std::endl;

    return 0;
}