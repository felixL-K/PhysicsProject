#ifndef _CELESTIALBODY
#define _CELESTIALBODY

#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>

#include "Vector2D.hpp"
#include "MainClass.hpp"

class CelestialBody {
    private:
        double diameter = 10;
        double mass = 10;
        Vector2D position{0, 0};
        Vector2D velocity{0, 0};

    public:
        // Constructeurs & Destructeur
        CelestialBody();
        CelestialBody(Vector2D posIn, double massIn);
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

        ostream & operator<<(ostream & out);



};


#endif




