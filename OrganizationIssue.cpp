#include <iostream>
#include <string>
#include <vector>
// Global functions from different developers - naming conflicts ahead!
//text output

namespace Sound{
    void play() {
    std::cout << "Playing background music" << std::endl;
    }
    void play(std::string soundEffect) {
    std::cout << "Playing sound effect: " << soundEffect << std::endl;
    }
}

namespace Graphics{
    void render() {
    std::cout << "Rendering 2D sprites" << std::endl;
    }
    void initialize() {
    std::cout << "Initializing graphics system" << std::endl;
    }
    void render(bool use3D) {
    if (use3D) {
    std::cout << "Rendering 3D models" << std::endl;
    } else {
    std::cout << "Rendering 2D sprites" << std::endl;
    }
    }
}

namespace Physics{
    void update() {
    std::cout << "Updating physics calculations" << std::endl;
    }
    void update(double deltaTime) {
    std::cout << "Updating physics with delta time: " << deltaTime << std::endl;
    }
    void initialize(int maxEntities) {
    std::cout << "Initializing physics system with " << maxEntities << " entities" << std::endl;
    }

}


// physics


int main() {
// This code is confusing - which functions do what?
Graphics::initialize();
Physics::initialize(1000);

    Graphics::render(true);
    Sound::play("explosion.wav");
    Physics::update(16.67);
return 0;
}