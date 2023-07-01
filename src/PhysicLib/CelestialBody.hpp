#ifndef _CELESTIALBODY
#define _CELESTIALBODY

#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "Vector2D.hpp"
//#include "SolarSystem.hpp"

class SolarSystem;

class CelestialBody {
    protected:
        SolarSystem* solarSystem;
        double diameter;
        double mass;
        Vector2D position;
        Vector2D velocity;
        sf::Color color;

    public:
        // Constructeurs & Destructeur
        CelestialBody(SolarSystem* system);
        CelestialBody(double massIn, Vector2D posIn, SolarSystem* system);
        CelestialBody(double diameter, double massIn, Vector2D posIn, Vector2D velocity, SolarSystem* system);
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
        sf::Color getColor() const;
        void setDiameter(double x);
        void setMass(double x);
        void setPosition(Vector2D x);
        void setVelocity(Vector2D x);
        void setColor(int r, int g, int b);

        // real functions begin
        void addVelocity(Vector2D forceIn);
        double distance(CelestialBody p);
        void newtonGrav(CelestialBody p);
        void checkCollision(CelestialBody p);
        
        void drawObject(sf::RenderWindow *window);




};


#endif

bool operator==(const CelestialBody& lhs, const CelestialBody& rhs);
ostream & operator<<(ostream & out, CelestialBody c);

