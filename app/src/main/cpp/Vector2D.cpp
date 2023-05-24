#include <iostream>
#include "Vector2D.hpp"

// Constructeur
Vector2D::Vector2D(double vx, double vy) : x{vx}, y{vy} {

}

// Constructeur par copie
Vector2D::Vector2D(const Vector2D & vect) : x{vect.getX()}, y{vect.getY()} {

}

// Destructeur
Vector2D::~Vector2D() {
    cout << "= Destruction de Vector2D(" << x << y << ") =" << endl;
}

// Surcharge de l'égalité
// Vector2D Vector2D::&operator=(const Vector2D & vect) {
//     return new Vector2D(vect.getX(),vect.getY());
// }


double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}



ostream & operator<<(ostream & out, Vector2D & v) {
    out << "Vector2D(" << v.getX() << v.getY() << ")" << endl; 
    return out;
}


