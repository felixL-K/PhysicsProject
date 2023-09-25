#include <iostream>
#include "Star.hpp"
#include "SolarSystem.hpp"
#include "../Main/MainClass.hpp"

Star::Star(SolarSystem *system) : CelestialBody(10, 10, Vector2D{0, 0}, Vector2D{0, 0}), solarSystem{system}
{
    system->setStar(this);
    setDiameter(50);
    setColor(255, 255, 51);
}

Star::Star(double massIn, Vector2D posIn, SolarSystem *system) : CelestialBody(massIn, posIn), solarSystem{system}
{
    system->setStar(this);
    setDiameter(50);
    setColor(255, 255, 51);
}

Star::Star(double diameter, double massIn, Vector2D posIn, Vector2D velocity, SolarSystem *system) : CelestialBody(diameter, massIn, posIn, velocity), solarSystem{system}
{
    system->setStar(this);
}

Star::~Star()
{
    cout << "deleting Star" << endl;
}
