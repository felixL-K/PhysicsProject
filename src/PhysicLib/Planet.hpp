#ifndef _PLANET
#define _PLANET

#include <iostream>
using namespace std;

#include "Vector2D.hpp"
#include "CelestialBody.hpp"
#include "PlanetSystem.hpp"

// class PlanetSystem;

class Planet : public CelestialBody
{
private:
    PlanetSystem *planetSystem;

public:
    // Constructeurs & Destructeur
    Planet(PlanetSystem *system);
    Planet(double massIn, Vector2D posIn, PlanetSystem *system);
    Planet(double diameter, double massIn, Vector2D posIn, Vector2D velocity, PlanetSystem *system);
    virtual ~Planet();
    PlanetSystem* getPlanetSystem();
    void updatePosition();

};

#endif
