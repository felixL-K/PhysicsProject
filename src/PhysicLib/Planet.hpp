#ifndef _PLANET
#define _PLANET

#include <iostream>
using namespace std;

#include "Vector2D.hpp"
#include "CelestialBody.hpp"
class SolarSystem;

class Planet : public CelestialBody
{
private:
    SolarSystem *solarSystem;

public:
    // Constructeurs & Destructeur
    Planet(SolarSystem *system);
    Planet(double massIn, Vector2D posIn, SolarSystem *system);
    Planet(double diameter, double massIn, Vector2D posIn, Vector2D velocity, SolarSystem *system);
    virtual ~Planet();
    void updatePosition();
};

#endif
