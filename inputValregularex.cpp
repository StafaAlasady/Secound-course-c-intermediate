#include <iostream>
#include <string>
#include <regex>
bool validateEmail(const std::string& email) {
    // Basic email pattern: username@domain.extension
    std::regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, email_pattern);
}
bool validatePhone(const std::string& phone) {
    // US phone pattern: (123) 456-7890 or 123-456-7890
    std::regex phone_pattern(R"((\d3
\d{3}
\s?|\d{3}[-.]?)\d{3}[-.]?\d{4})");
    return std::regex_match(phone, phone_pattern);
}
bool validateZipCode(const std::string& zipCode) {
    static const std::regex zip_pattern(R"(^\d{5}(-\d{4})?$)");
    return std::regex_match(zipCode, zip_pattern);
}
bool validateName(const std::string& name) {
    // Name should contain only letters and spaces, at least 2 characters
    std::regex name_pattern(R"([a-zA-Z\s]{2,})");
    return std::regex_match(name, name_pattern) && !name.empty();
}
int main() {
    std::string name, email, phone, zipCode;    
    // Validate name
    do {
        std::cout << "Enter full name: ";
        std::getline(std::cin, name);        
        if (!validateName(name)) {
            std::cerr << "Error: Name must contain only letters and spaces (minimum 2 characters)." << std::endl;
        }
    } while (!validateName(name));   
    // Validate email
    do {
        std::cout << "Enter email address: ";
        std::getline(std::cin, email);        
        if (!validateEmail(email)) {
            std::cerr << "Error: Invalid email format. Use: user@domain.com" << std::endl;
        }
    } while (!validateEmail(email));    
    // Validate phone
    do {
        std::cout << "Enter phone number (123-456-7890 or (123) 456-7890): ";
        std::getline(std::cin, phone);        
        if (!validatePhone(phone)) {
            std::cerr << "Error: Invalid phone format. Use: 123-456-7890 or (123) 456-7890" << std::endl;
        }
    } while (!validatePhone(phone));
        // Validate ZipCode
    do {
        std::cout << "Enter your Zip-code (12-123): ";
        std::getline(std::cin, zipCode);        
        if (!validateZipCode(zipCode)) {
            std::cerr << "Error: Invalid phone format. Use: (12-345)" << std::endl;
        }
    } while (!validateZipCode(zipCode));
    // Display success message with formatted output
    std::cout << "\nRegistration successful!" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Customer Information:" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    std::cout << "Name:  " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "zip-code: " << zipCode << std::endl;
    std::cout << std::string(40, '=') << std::endl;    
    return 0;
}