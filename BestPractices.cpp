#include <iostream>
#include <string>
#include <vector>
// Same namespace definitions as Task 2...
namespace Graphics {
void render() {
std::cout << "Rendering 2D sprites" << std::endl;
}
void render(bool use3D) {
if (use3D) {
std::cout << "Rendering 3D models" << std::endl;
} else {
std::cout << "Rendering 2D sprites" << std::endl;
}
}
void initialize() {
std::cout << "Initializing graphics system" << std::endl;
}
namespace Advanced {
void renderShadows() {
std::cout << "Rendering advanced shadows" << std::endl;
}
}
}
namespace Audio {
void play() {
std::cout << "Playing background music" << std::endl;
}
void play(const std::string& soundEffect) {
std::cout << "Playing sound effect: " << soundEffect << std::endl;
}
void setVolume(float volume) {
std::cout << "Setting audio volume to: " << volume << std::endl;
}
// Nested namespace for different audio types
namespace Music {
void playTrack(const std::string& filename) {
std::cout << "Playing music track: " << filename << std::endl;
}
void fadeOut(float duration) {
std::cout << "Fading out music over " << duration << " seconds" << std::endl;
}
}
namespace Effects {
void playExplosion() {
std::cout << "Playing explosion sound effect" << std::endl;
}
void playFootstep(const std::string& surface) {
std::cout << "Playing footstep on " << surface << std::endl;
}
}
}
namespace Physics {
void update() {
std::cout << "Updating physics calculations" << std::endl;
}
void update(double deltaTime) {
std::cout << "Updating physics with delta time: " << deltaTime << "ms" << std::endl;
}
}
// Example of GOOD using practices
void gameInitialization() {
std::cout << "=== Game Initialization Function ===" << std::endl;
// Limited scope using declarations - good practice
using Graphics::initialize;
using Physics::update;
initialize(); // Clear which initialize() this is within this function
update();   // Clear which update() this is within this function
// Still need full qualification for other namespaces
Audio::play();
}
void graphicsTestFunction() {
std::cout << "\n=== Graphics Test Function ===" << std::endl;
// Using entire namespace in limited scope - acceptable for focused functions
using namespace Graphics;
render();      // Graphics::render()
render(true);    // Graphics::render(bool)
initialize();    // Graphics::initialize()
// Still need qualification for other namespaces
Audio::play("test.wav");
}
// Example of BAD practice (commented out to avoid issues)
/*
// DON'T DO THIS - global using namespace can cause conflicts
using namespace Graphics;
using namespace Audio;
using namespace Physics;
void badExample() {
// Now we have the same problems as before!
// Which initialize()? Which update()? Which play()?
initialize(); // Ambiguous!
update();   // Ambiguous!
play();    // Ambiguous!
}
*/
// Demonstration of namespace aliases for long names
namespace GFX = Graphics;
namespace SFX = Audio;
void gameLoop() {
std::cout << "\n=== Game Loop (with aliases) ===" << std::endl;
// Namespace aliases make long names shorter while keeping clarity
GFX::render();
GFX::Advanced::renderShadows();
SFX::play("ambient.wav");
// You can also use using declarations with aliases
using GFX::render;
render(); // Now refers to Graphics::render()
}
// Demonstration of using declarations with specific functions
void audioTest() {
std::cout << "\n=== Audio Test (selective using) ===" << std::endl;
// Only bring in specific functions we need
using Audio::play;
using Audio::setVolume; // This would need to be defined in Audio namespace
play();          // Audio::play()
play("button_click.wav"); // Audio::play(const std::string&)
// Other Audio functions still need full qualification
// Audio::Music::playTrack("song.mp3"); // Still need full path for nested
}
int main() {
gameInitialization();
graphicsTestFunction();
gameLoop();
audioTest();
std::cout << "\n=== Manual Qualification (always safe) ===" << std::endl;
// The safest approach - always be explicit
Graphics::render();
Graphics::render(true);
Audio::play();
Audio::play("game_over.wav");
Physics::update();
Physics::update(16.67);
return 0;
}