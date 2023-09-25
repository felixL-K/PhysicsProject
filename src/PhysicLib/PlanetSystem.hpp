#ifndef _PLANETSYSTEM
#define _PLANETSYSTEM

#include <iostream>
using namespace std;
#include <map>
#include <vector>

#include "Satellite.hpp"
// #include "Planet.hpp"
#include "SolarSystem.hpp"

class Planet;

class PlanetSystem
{
private:
    SolarSystem* solarSystem;
    map<Satellite *, vector<Vector2D>> paths;
    std::vector<Satellite *> satellites;
    Planet *planet;
    Vector2D dimension;

public:
    // Constructeur
    PlanetSystem(Vector2D center, SolarSystem* s);
    virtual ~PlanetSystem();

    // static map<CelestialBody, vector<Vector2D>> getPaths();
    vector<Satellite *> getSatellites();
    map<Satellite *, vector<Vector2D>> getPaths();
    Vector2D getDimension();
    Vector2D getCenter();
    Planet *getPlanet();
    SolarSystem* getSolarSystem();
    void setPlanet(Planet *s);
    void addSatellite(Satellite *body);
    void addPath(Satellite *body, Vector2D vect);
    void findIndexBody(CelestialBody *c);
    void updateAllPositionsSatellites();
    void newtonGravAll();
    void updatePosition();

    void generateRandomSatellite();
    void generateLessRandomSatellite();
    void generateXAxisSatellite();
};

#endif

// ostream & operator<<(ostream & out, PlanetSystem & d);
