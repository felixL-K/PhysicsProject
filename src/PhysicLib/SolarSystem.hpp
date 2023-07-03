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
        const unsigned int pathSize = 300;
        map<Planet*,vector<Vector2D>> paths;
        std::vector<Planet*> celestialBodys;
        Star* star;
        Vector2D center;
        Vector2D dimension;

    public:
        
        // Constructeur
        SolarSystem(Vector2D center);
        virtual ~SolarSystem();
        // SolarSystem(const SolarSystem &); 
        // virtual ~SolarSystem(); 
        // Surcharge de l'initialisation
        //SolarSystem &operator=(const SolarSystem &); 
        //Surcharge du <<
        //friend ostream & operator<<(ostream &,const SolarSystem &); 

        //static map<CelestialBody, vector<Vector2D>> getPaths();
        vector<Planet*> getBodys();
        map<Planet*,vector<Vector2D>> getPaths();
        Vector2D getDimension();
        Vector2D getCenter();
        Star* getStar();
        void setStar(Star* s);
        void addBody(Planet* body);
        // vector<Vector2D> getPathOfBody(CelestialBody* body);
        void addPath(Planet* body, Vector2D vect);
        void findIndexBody(CelestialBody* c);
        void updateAllPositions();
        void newtonGravAll();

        void generateRandomPlanet();

};


#endif

// ostream & operator<<(ostream & out, SolarSystem & d);
