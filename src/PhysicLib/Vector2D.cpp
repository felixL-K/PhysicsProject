#include "Vector2D.hpp"

// Constructeur
Vector2D::Vector2D() : x{0}, y{0} {}

Vector2D::Vector2D(double vx, double vy) : x{vx}, y{vy} {}

Vector2D::Vector2D(const Vector2D & vect) : x{vect.getX()}, y{vect.getY()} {}

Vector2D::~Vector2D() {
    // double vx = this->getX();
    // double vy = this->getY();
    // cout << "= Destruction de " << "Vector2D(" << vx << "," << vy << ") " << " =" << endl;
    // =================================================================
    // cout << "= Destruction de " << *this << " =" << endl;
    // boucle infini : le *this creer une copie, qui est affiché, puis dupprimé, dc recopié etc
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

void Vector2D::setX(double vx) {
    x = vx;
}
void Vector2D::setY(double vy) {
    y = vy;
}

ostream & operator<<(ostream & out, Vector2D v) {
    double vx = v.getX();
    double vy = v.getY();
    out << "Vector2D(" << vx << "," << vy << ")"; 
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

bool operator==(const Vector2D& lhs, const Vector2D& rhs) {
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

Vector2D Vector2D::operator*(double d) {
    return Vector2D{x*d,y*d};
}
Vector2D Vector2D::operator/(double d) {
    return Vector2D{x/d,y/d};
}