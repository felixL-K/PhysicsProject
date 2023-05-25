#include <iostream>
#include "Vector2D.hpp"

// Constructeur
Vector2D::Vector2D(double vx, double vy) : x{vx}, y{vy} {}

Vector2D::Vector2D(const Vector2D & vect) : x{vect.getX()}, y{vect.getY()} {}

Vector2D::~Vector2D() {
    cout << "= Destruction de " << *this << " =" << endl;
}

/*
Surcharge de l'égalité
Vector2D Vector2D::&operator=(const Vector2D & vect) {
    return new Vector2D(vect.getX(),vect.getY());
}
*/

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

ostream & operator<<(ostream & out, Vector2D & v) {
    out << "Vector2D(" << v.getX() << "," << v.getY() << ")"; 
    return out;
}

double Vector2D::distance(Vector2D v){
    double dx = v.getX() - this->x;
    double dy = v.getY() - this->y;
    return sqrt(dx * dx + dy * dy);
}

void Vector2D::add(double vx, double vy) {
    x += vx;
    y += vy;
    return;
}

void Vector2D::add(Vector2D v) {
    x += v.getX();
    y += v.getY();
    return;
}

Vector2D Vector2D::multiply(Vector2D pos1, double multiplier) {
    return Vector2D{pos1.getX() * multiplier, pos1.getY() * multiplier};
}

float Vector2D::getAngleDegrees(Vector2D target) {
    float angle = atan2(target.getY() - y, target.getX() - x); // in radian
    float angleDegree = angle * 180 / M_PI; //3.141592653589793238463
    if (angleDegree < 0) {
        angleDegree += 360;
    }
    return angleDegree;
}

