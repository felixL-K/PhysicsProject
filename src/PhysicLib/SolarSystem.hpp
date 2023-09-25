#ifndef _SOLARSYSTEM
#define _SOLARSYSTEM

#include <iostream>
using namespace std;
#include <map>
#include <vector>

#include "Planet.hpp"
#include "Star.hpp"
#include "PlanetSystem.hpp"

// class CelestialBody;

class SolarSystem
{
private:
    map<PlanetSystem *, vector<Vector2D>> paths;
    std::vector<PlanetSystem *> planetSystems;
    Star *star;
    Vector2D dimension;

public:
    // Constructeur
    SolarSystem(Vector2D center);
    virtual ~SolarSystem();

    // static map<CelestialBody, vector<Vector2D>> getPaths();
    vector<PlanetSystem *> getPlanetSystems();
    map<PlanetSystem *, vector<Vector2D>> getPaths();
    Vector2D getDimension();
    Vector2D getCenter();
    Star *getStar();
    void setStar(Star *s);
    void addPlanetSysem(PlanetSystem *body);
    void addPlanetSysem(PlanetSystem *body, Vector2D c);
    void addPath(PlanetSystem *body, Vector2D vect);
    void updateAllPositions();
    void newtonGravAll();

    void generateRandomPlanetSystem();
    void generateLessRandomPlanetSystem();
    void generateXAxisPlanetSystem();
    
};

#endif

// ostream & operator<<(ostream & out, SolarSystem & d);
