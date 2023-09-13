#include <iostream>
#include "Star.hpp"
#include "SolarSystem.hpp"
#include "../Main/MainClass.hpp"


Star::Star(SolarSystem* system) : CelestialBody(system) {
    system->setStar(this);
    setDiameter(50);
    setColor(255,255,51);
}

Star::Star(double massIn, Vector2D posIn, SolarSystem* system) : CelestialBody(massIn,posIn,system) {
    system->setStar(this);
    setDiameter(50);
    setColor(255,255,51);
}

Star::Star(double diameter, double massIn, Vector2D posIn, Vector2D velocity, SolarSystem* system) : CelestialBody(diameter,massIn,posIn,velocity,system) {
    system->setStar(this);
}

Star::~Star() {
    // cout << "deleting Star" << endl;
} 
