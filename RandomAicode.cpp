#include <iostream>
#include <stdexcept>
#include <cmath>

namespace PlanetPhysics {
    // Renamed to reflect its generic mathematical purpose
    constexpr double G = 6.67430e-11; // Gravitational constant

    double calculateSurfaceGravity(double mass, double radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be greater than zero.");
        }
        return (G * mass) / (radius * radius);
    }
}

namespace GameUtilities {
    void displayWelcomeMessage() {
        std::cout << "Welcome to the Game!\n";
    }
}

namespace PlayerMovements {
    void movePlayer() {
        std::cout << "Player is moving...\n";
    }

    double calculateSpeedPlayer(double distance, double time) {
        if (time <= 0) {
            throw std::invalid_argument("Time must be greater than zero.");
        }
        return distance / time;
    }
}

int main() {
    GameUtilities::displayWelcomeMessage();
    PlayerMovements::movePlayer();

    try {
        double speed = PlayerMovements::calculateSpeedPlayer(100.0, 2.0);
        std::cout << "Player speed: " << speed << " units/s\n";

        // Testing exception handling
        double invalidSpeed = PlayerMovements::calculateSpeedPlayer(100.0, 0.0);
    } 
    catch (const std::exception& e) {
        std::cerr << "Movement Error: " << e.what() << '\n';
    }

    return 0;
}