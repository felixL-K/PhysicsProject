#ifndef _VECTOR2D
#define _VECTOR2D

#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>

class Vector2D {
    private:
        double x;
        double y;

    public:
        // Constructeur
        Vector2D();
        Vector2D(double vx, double vy);
        Vector2D(const Vector2D &); 
        virtual ~Vector2D(); 
        // Surcharge de l'initialisation
        //Vector2D &operator=(const Vector2D &); 
        //Surcharge du <<
        //friend ostream & operator<<(ostream &,const Vector2D &); 

        double getX() const;
        double getY() const;

        double distance(Vector2D v);
        void add(double vx, double vy);
        void add(Vector2D v);
        static Vector2D multiply(Vector2D pos1, double multiplier);
        float getAngleDegrees(Vector2D target);
        Vector2D operator*(double d);
        Vector2D operator/(double d);

};


#endif

ostream & operator<<(ostream & out, Vector2D c);
bool operator==(const Vector2D& lhs, const Vector2D& rhs);




















/*
class Vector2D { 
	public: 
		// Constructeur
		Vector2D(); 
		// Constructeur par copie
		Vector2D(const ClassCanon &); 
		// Destructeur
		virtual ~Vector2D(); 
		// Surcharge de l'égalité
		Vector2D &operator=(const Vector2D &); 
		//Surcharge du <<
		friend ostream & operator<<(ostream &,const Vector2D &); 
}; 
*/
