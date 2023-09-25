#include "Satellite.hpp"

#include <iostream>
#include "Planet.hpp"
#include "CelestialBody.hpp"
#include "GlobalValues.hpp"

Satellite::Satellite(PlanetSystem *system) : CelestialBody(10, 10, Vector2D{0, 0}, Vector2D{0, 0}), planetSystem{system}
{
    system->addSatellite(this);
}

Satellite::Satellite(double massIn, Vector2D posIn, PlanetSystem *system) : CelestialBody(massIn, posIn), planetSystem{system}
{
    system->addSatellite(this);
}

Satellite::Satellite(double diameter, double massIn, Vector2D posIn, Vector2D velocity, PlanetSystem *system) : CelestialBody(diameter, massIn, posIn, velocity), planetSystem{system}
{
    system->addSatellite(this);
}

Satellite::~Satellite()
{
    // cout << "deleting Satellite" << endl;
}

void Satellite::updatePosition()
{
    position.add(velocity * GlobalValues::timeScale);
    planetSystem->addPath(this, position);
}