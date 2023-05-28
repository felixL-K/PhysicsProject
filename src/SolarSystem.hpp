#ifndef _SOLARSYSTEM
#define _SOLARSYSTEM

#include <iostream>
using namespace std;
#include <map>
#include <vector>

#include "CelestialBody.hpp"
//#include "Vector2D.hpp"

//class CelestialBody;

class SolarSystem {
    private:
        
        //static Vector2D[][] paths;

    public:
        static const unsigned int pathSize = 300;
        static std::vector<std::vector<Vector2D>> paths;
        static std::vector<CelestialBody*> celestialBodys;
        // Constructeur
        SolarSystem();
        // SolarSystem(const SolarSystem &); 
        // virtual ~SolarSystem(); 
        // Surcharge de l'initialisation
        //SolarSystem &operator=(const SolarSystem &); 
        //Surcharge du <<
        //friend ostream & operator<<(ostream &,const SolarSystem &); 

        //static map<CelestialBody, vector<Vector2D>> getPaths();
        static vector<CelestialBody*> getBodys();
        static void addBody(CelestialBody* body);
        //static vector<Vector2D> getPathOfBody(CelestialBody* body);
        static void addPath(CelestialBody* body, Vector2D* vect);
        static void findIndexBody(CelestialBody* c);

};


#endif

// ostream & operator<<(ostream & out, SolarSystem & d);
