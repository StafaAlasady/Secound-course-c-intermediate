#include <iostream>

import Utilities;
import PlayerInput;
import GameLogic;

namespace processing {
    void process(int x) {
        std::cout << "Processing player input: " << x << "\n";
    }
}

int main() {
    int secret = Utilities::GenerateSecret();
    bool isGameWon = false;
    
    while (!isGameWon) {
        int guess = PlayerInput::PlayerTextInput();
        processing::process(guess);
        isGameWon = GameLogic::evaluateGuess(guess, secret);
    }

    return 0;
}