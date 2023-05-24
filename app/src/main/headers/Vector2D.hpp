#ifndef _VECTOR2D
#define _VECTOR2D

#include <iostream>
using namespace std;

class Vector2D {
    private:
        double x;
        double y;

    public:
        // Constructeur
        Vector2D(double vx, double vy);
        // Constructeur par copie
        Vector2D(const Vector2D &); 
        // Destructeur
        virtual ~Vector2D(); 
        // Surcharge de l'initialisation
        //Vector2D &operator=(const Vector2D &); 
        //Surcharge du <<
        //friend ostream & operator<<(ostream &,const Vector2D &); 

        double getX() const;
        double getY() const;

};


#endif

ostream & operator<<(ostream & out, Vector2D & d);




















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
