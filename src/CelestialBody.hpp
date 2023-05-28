#ifndef _CELESTIALBODY
#define _CELESTIALBODY

#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>

#include "Vector2D.hpp"
//#include "SolarSystem.hpp"

class SolarSystem;

class CelestialBody {
    private:
        //SolarSystem* solarSystem;
        double diameter;
        double mass;
        Vector2D position;
        Vector2D velocity;

    public:
        // Constructeurs & Destructeur
        CelestialBody();
        CelestialBody(double massIn, Vector2D posIn);
        CelestialBody(double diameter, double massIn, Vector2D posIn, Vector2D velocity);
        CelestialBody(const CelestialBody &cb); 
        virtual ~CelestialBody(); 

        // Surcharge de l'initialisation
        //CelestialBody &operator=(const CelestialBody &); 
        //Surcharge du <<
        //friend ostream & operator<<(ostream &,const CelestialBody &); 

        // getters & setters
        double getDiameter() const;
        double getMass() const;
        Vector2D getPosition() const;
        Vector2D getVelocity() const;
        void setDiameter(double x);
        void setMass(double x);
        void setPosition(Vector2D x);
        void setVelocity(Vector2D x);

        // real functions begin
        void addVelocity(Vector2D forceIn);
        double distance(CelestialBody p);
        void newtonGrav(CelestialBody p);
        void updatePosition();
        void checkCollision(CelestialBody p);
        




};


#endif

bool operator==(const CelestialBody& lhs, const CelestialBody& rhs);
ostream & operator<<(ostream & out, CelestialBody c);

