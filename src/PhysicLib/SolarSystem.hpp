#ifndef _SOLARSYSTEM
#define _SOLARSYSTEM

#include <iostream>
using namespace std;
#include <map>
#include <vector>

#include "Planet.hpp"
#include "Star.hpp"

//class CelestialBody;

class SolarSystem {
    private:
        map<Planet*,vector<Vector2D>> paths;
        std::vector<Planet*> celestialBodys;
        Star* star;
        Vector2D center;
        Vector2D dimension;

    public:
        
        // Constructeur
        SolarSystem(Vector2D center);
        virtual ~SolarSystem();

        //static map<CelestialBody, vector<Vector2D>> getPaths();
        vector<Planet*> getBodys();
        map<Planet*,vector<Vector2D>> getPaths();
        Vector2D getDimension();
        Vector2D getCenter();
        Star* getStar();
        void setStar(Star* s);
        void addBody(Planet* body);
        void addPath(Planet* body, Vector2D vect);
        void findIndexBody(CelestialBody* c);
        void updateAllPositions();
        void newtonGravAll();

        void generateRandomPlanet();
        void generateLessRandomPlanet();

};


#endif

// ostream & operator<<(ostream & out, SolarSystem & d);
