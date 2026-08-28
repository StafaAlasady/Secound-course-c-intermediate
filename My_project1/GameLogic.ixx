module;
#include <iostream>
#include <cstdlib>
#include <ctime>

export module GameLogic;

export namespace GameLogic {
    bool evaluateGuess(int guess, int secret){
        if(guess < secret){
            std::cout << " Too Low, try again!\n";
            return false;
        }else if (guess > secret){
            std::cout << " too high, try again!\n";
            return false;
        }else {
            std::cout << " You won! the secret number was " << secret << "!\n";
            return true;
        }
    }

}
