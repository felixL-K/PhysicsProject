#include <iostream>
#include "CelestialBody.hpp"
#include "SolarSystem.hpp"
#include "MainClass.hpp"

// Constructeur
//solarSystem{new SolarSystem{}},
CelestialBody::CelestialBody() : diameter{10}, mass{10}, position{Vector2D{0,0}}, velocity{Vector2D{0,0}} {
    SolarSystem::addBody(this);
}

CelestialBody::CelestialBody(double diameter, Vector2D posIn) : diameter{diameter}, mass{10}, position{posIn}, velocity{Vector2D{0,0}} {
    SolarSystem::addBody(this);
}

CelestialBody::CelestialBody(double diameter, double massIn, Vector2D posIn, Vector2D velocity)
: diameter{diameter},mass{massIn},position{posIn}, velocity{velocity} {}

CelestialBody::CelestialBody(const CelestialBody & vect) 
: diameter{vect.getDiameter()}, mass{vect.getMass()}, position{vect.getPosition()},  velocity{vect.getVelocity()} {}


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

ostream & operator<<(ostream & out, CelestialBody c) {
    out << "CelestialBody(mass=" << c.getMass() << ", " << c.getPosition() << ")" << endl; 
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

void CelestialBody::updatePosition(){
    position.add(Vector2D::multiply(velocity, MainClass::getDeltaTime()));
    //addPath(this.position);
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
