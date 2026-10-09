#ifndef _GALAXY
#define _GALAXY

#include <iostream>
using namespace std;

#include "SolarSystem.hpp"

class Galaxy {
  private:
    std::vector<SolarSystem *> solarSystems;
    Vector2D center;
    Vector2D dimension;

  public:
    Galaxy(Vector2D center);
    virtual ~Galaxy();

    vector<SolarSystem *> getSolarSystems();
    Vector2D getDimension();
    Vector2D getCenter();
    void addSolarSystem(SolarSystem *ss);
    void findIndexSolarSystem(SolarSystem *c);
    void updateAllPositions();
    void newtonGravAll();

    void generateRandomSolarSystem();
};

#endif
