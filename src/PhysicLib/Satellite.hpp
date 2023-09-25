#ifndef _SATELLITE
#define _SATELLITE

#include <iostream>
using namespace std;

#include "Vector2D.hpp"
#include "CelestialBody.hpp"
// #include "PlanetSystem.hpp"

class PlanetSystem;

class Satellite : public CelestialBody
{
private:
    PlanetSystem* planetSystem;

public:
    // Constructeurs & Destructeur
    Satellite(PlanetSystem *planet);
    Satellite(double massIn, Vector2D posIn, PlanetSystem *planet);
    Satellite(double diameter, double massIn, Vector2D posIn, Vector2D velocity, PlanetSystem *planet);
    virtual ~Satellite();
    void updatePosition();
};

#endif
