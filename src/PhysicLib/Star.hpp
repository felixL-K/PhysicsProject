#ifndef _STAR
#define _STAR

#include <iostream>
using namespace std;

#include "Vector2D.hpp"
#include "CelestialBody.hpp"
class SolarSystem;

class Star : public CelestialBody {
    private:

    public:
        // Constructeurs & Destructeur
        Star(SolarSystem* system);
        Star(double massIn, Vector2D posIn, SolarSystem* system);
        Star(double diameter, double massIn, Vector2D posIn, Vector2D velocity, SolarSystem* system);
        virtual ~Star(); 





};


#endif


