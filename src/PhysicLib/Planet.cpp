#include <iostream>
#include "Planet.hpp"
#include "SolarSystem.hpp"
#include "../Main/MainClass.hpp"

Planet::Planet(SolarSystem* system) : CelestialBody(system) {
    system->addBody(this);
}

Planet::Planet(double massIn, Vector2D posIn, SolarSystem* system) : CelestialBody(massIn,posIn,system) {
    system->addBody(this);
}

Planet::Planet(double diameter, double massIn, Vector2D posIn, Vector2D velocity, SolarSystem* system) : CelestialBody(diameter,massIn,posIn,velocity,system) {
    system->addBody(this);
}


Planet::~Planet() {
    // cout << "deleting Planet" << endl;
}

void Planet::updatePosition(){
    //position.add(Vector2D::multiply(velocity, MainClass::getDeltaTime()));
    position.add(velocity*0.0000000001);
    solarSystem->addPath(this,position);
    //addPath(this.position);
}