#include <iostream>
#include "Planet.hpp"
#include "GlobalValues.hpp"

Planet::Planet(PlanetSystem *system) : CelestialBody(10, 10, Vector2D{0, 0}, Vector2D{0, 0}), planetSystem{system}
{
    system->setPlanet(this);
    setDiameter(50);
}

Planet::Planet(double massIn, Vector2D posIn, PlanetSystem *system) : CelestialBody(massIn, posIn), planetSystem{system}
{
    system->setPlanet(this);
    setDiameter(50);
}

Planet::Planet(double diameter, double massIn, Vector2D posIn, Vector2D velocity, PlanetSystem *system) : CelestialBody(diameter, massIn, posIn, velocity), planetSystem{system}
{
    system->setPlanet(this);
}

Planet::~Planet()
{
    // cout << "deleting Planet" << endl;
}

PlanetSystem* Planet::getPlanetSystem() {
    return planetSystem;
}

void Planet::updatePosition()
{
    position.add(velocity * GlobalValues::timeScale);
    getPlanetSystem()->getSolarSystem()->addPath(getPlanetSystem(), position);
}