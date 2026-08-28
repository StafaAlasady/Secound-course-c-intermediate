module;
#include <iostream>
#include <cstdlib>
#include <ctime>

export module PlayerInput;

export namespace PlayerInput{
    int PlayerTextInput(){
    int guess;
    std::cout << "=== GUESSING GAME ===\n";
    std::cout << "Guess a number between 1 and 100: ";
    std::cin >> guess;
    return guess;
    }
}