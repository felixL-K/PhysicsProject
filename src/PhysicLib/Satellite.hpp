#ifndef _SATELLITE
#define _SATELLITE

#include <iostream>
using namespace std;

#include "Vector2D.hpp"
#include "CelestialBody.hpp"
class Planet;

class Satellite : public CelestialBody {
    private:

    public:
        // Constructeurs & Destructeur
        Satellite(Planet* planet);
        Satellite(double massIn, Vector2D posIn, Planet* planet);
        Satellite(double diameter, double massIn, Vector2D posIn, Vector2D velocity, Planet* planet);
        virtual ~Satellite(); 
        void updatePosition();





};


#endif


