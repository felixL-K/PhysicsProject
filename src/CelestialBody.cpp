#include <iostream>
#include "CelestialBody.hpp"

// Constructeur
CelestialBody::CelestialBody() {}

CelestialBody::CelestialBody(Vector2D posIn, double massIn) : position{posIn}, mass{massIn} {}

CelestialBody::CelestialBody(const CelestialBody & vect) : position{vect.getPosition()}, mass{vect.getMass()}, velocity{vect.getVelocity()}, diameter{vect.getDiameter()} {}

CelestialBody::~CelestialBody() {
    cout << "= Destruction d'un CelestialBody =" << endl;
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
    return position;
}
Vector2D CelestialBody::getVelocity() const {
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

ostream & CelestialBody::operator<<(ostream & out) {
    out << "CelestialBody(" << "hahahha" << ")" << endl; 
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


