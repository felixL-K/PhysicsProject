#include "SolarSystem.hpp"


SolarSystem::SolarSystem(Vector2D center) : System<Star,Planet>(center) {
  
}

SolarSystem::~SolarSystem() {
    this->System::~System();
}