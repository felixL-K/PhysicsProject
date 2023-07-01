#include <iostream>
#include "CelestialBody.hpp"
#include "SolarSystem.hpp"
#include "../Main/MainClass.hpp"

// Constructeur
//solarSystem{new SolarSystem{}},
CelestialBody::CelestialBody(SolarSystem* system) : diameter{10}, mass{10}, position{Vector2D{0,0}}, velocity{Vector2D{0,0}}, color{rand() % 255, rand() % 255, rand() % 255}, solarSystem{system} {
    
}

CelestialBody::CelestialBody(double massIn, Vector2D posIn, SolarSystem* system) : diameter{10}, mass{massIn}, position{posIn}, velocity{Vector2D{0,0}}, color{rand() % 255, rand() % 255, rand() % 255}, solarSystem{system} {
    
}

CelestialBody::CelestialBody(double diameter, double massIn, Vector2D posIn, Vector2D velocity, SolarSystem* system)
: diameter{diameter},mass{massIn},position{posIn}, velocity{velocity}, color{rand() % 255, rand() % 255, rand() % 255}, solarSystem{system} {}

CelestialBody::CelestialBody(const CelestialBody & vect) 
: diameter{vect.getDiameter()}, mass{vect.getMass()}, position{vect.getPosition()},  velocity{vect.getVelocity()}, color{rand() % 255, rand() % 255, rand() % 255} {}


CelestialBody::~CelestialBody() {
    // cout << "= Destruction d'un CelestialBody =" << endl;
    //delete SolarSystem;
}

/*
Surcharge de l'égalité
CelestialBody CelestialBody::&operator=(const CelestialBody & vect) {
    return new CelestialBody(vect.getX(),vect.getY());
}
*/

// getters & setters
double CelestialBody::getDiameter() const {
    return diameter;
}
double CelestialBody::getMass() const {
    return mass;
}
Vector2D CelestialBody::getPosition() const {
    // return Vector2D{position};
    return position;
}
Vector2D CelestialBody::getVelocity() const {
    // return Vector2D{velocity};
    return velocity;
}
sf::Color CelestialBody::getColor() const {
    return color;
}
void CelestialBody::setDiameter(double x){
    diameter = x;
}
void CelestialBody::setMass(double x){
    mass = x;
}
void CelestialBody::setPosition(Vector2D x){
    position = x;
}
void CelestialBody::setVelocity(Vector2D x){
    velocity = x;
}
void CelestialBody::setColor(int r, int g, int b) {
    color = sf::Color{r,g,b};
}


ostream & operator<<(ostream & out, CelestialBody c) {
    out << "CelestialBody(mass=" << c.getMass() << ", " << c.getPosition() << ")" ; 
    return out;
}

// real functions begin
void CelestialBody::addVelocity(Vector2D forceIn){
    velocity.add(forceIn);
}

double CelestialBody::distance(CelestialBody p){
    return position.distance(p.getPosition());
}

void CelestialBody::newtonGrav(CelestialBody p) {
    double dist = this->distance(p);
    if (dist != 0) {
        double force = this->mass * p.mass / pow(dist, 2);
        double angle = position.getAngleDegrees(p.position);
        double acc = force / this->mass;
        double dirx = acc * cos(angle * (M_PI / 180));
        double diry = acc * sin(angle * (M_PI / 180));
        this->velocity.add(dirx, diry);
        return;
    }
    return;
}

void CelestialBody::checkCollision(CelestialBody p){

}

bool operator==(const CelestialBody& lhs, const CelestialBody& rhs) {
    bool sameDiameter = lhs.getDiameter() == rhs.getDiameter();
    bool sameMass = lhs.getMass() == rhs.getMass();
    bool samePos = lhs.getPosition() == rhs.getPosition();
    bool sameVelo = lhs.getVelocity() == rhs.getVelocity();
    return sameDiameter && sameMass && samePos && sameVelo;
}

void CelestialBody::drawObject(sf::RenderWindow *window) {
    sf::CircleShape circle1;
    circle1.setRadius(diameter);
    circle1.setFillColor(color);
    circle1.setPosition(position.getX()-diameter/2,position.getY()-diameter/2);
    circle1.setOrigin (sf::Vector2f(diameter/2,diameter/2));
    //circle1.setRadius(50);
    window->draw(circle1);
}
