#include <iostream>
#include <limits>
int main() {
    int age;
    std::cout << "Enter customer age: ";
    while (!(std::cin >> age) || age < 1000 || age > 9999) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an age between 1000 and 9999: ";
    }
    std::cout << "Age entered: " << age << std::endl;
    return 0;
}