#ifndef _SOLARSYSTEM
#define _SOLARSYSTEM

#include <iostream>
using namespace std;
#include <map>
#include <vector>

#include "CelestialBody.hpp"

//class CelestialBody;

class SolarSystem {
    private:
        const unsigned int pathSize = 30;
        map<CelestialBody*,vector<Vector2D>> paths;
        std::vector<CelestialBody*> celestialBodys;
        Vector2D dimention;

    public:
        
        // Constructeur
        SolarSystem();
        // SolarSystem(const SolarSystem &); 
        // virtual ~SolarSystem(); 
        // Surcharge de l'initialisation
        //SolarSystem &operator=(const SolarSystem &); 
        //Surcharge du <<
        //friend ostream & operator<<(ostream &,const SolarSystem &); 

        //static map<CelestialBody, vector<Vector2D>> getPaths();
        vector<CelestialBody*> getBodys();
        map<CelestialBody*,vector<Vector2D>> getPaths();
        Vector2D getDimention();
        void addBody(CelestialBody* body);
        // vector<Vector2D> getPathOfBody(CelestialBody* body);
        void addPath(CelestialBody* body, Vector2D vect);
        void findIndexBody(CelestialBody* c);
        void updateAllPositions();
        void newtonGravAll();

        static void generateRandomObjetPhysique();

};


#endif

// ostream & operator<<(ostream & out, SolarSystem & d);
