#include "Satellite.hpp"

#include <iostream>
#include "Planet.hpp"
#include "CelestialBody.hpp"
#include "GlobalValues.hpp"

Satellite::Satellite(Planet *planet) : CelestialBody(planet)
{
    planet->addBody(this);
}

Satellite::Satellite(double massIn, Vector2D posIn, Planet *planet) : CelestialBody(massIn, posIn, planet)
{
    planet->addBody(this);
}

Satellite::Satellite(double diameter, double massIn, Vector2D posIn, Vector2D velocity, Planet *planet) : CelestialBody(diameter, massIn, posIn, velocity, planet)
{
    planet->addBody(this);
}

Satellite::~Satellite()
{
    // cout << "deleting Satellite" << endl;
}

void Satellite::updatePosition()
{
    position.add(velocity * GlobalValues::timeScale);
    solarSystem->addPath(this, position);
}