#ifndef _MAINCLASS
#define _MAINCLASS

#include <iostream>
using namespace std;

#include "Vector2D.hpp"
#include "CelestialBody.hpp"

class MainClass {
    private:
        static const int TICK_SPEED = 200;
        static const int timeScale = 200;
        //UserInterface interface_utilisateur = new UserInterface();
        //JFrame simulationFrame = new JFrame();
        //int pathSize = 30;
        int refreshSpeed = 1;
        //AlgoStrategy algo;

    public:
        // Constructeur
        MainClass();
        virtual ~MainClass(); 
        
        static double getDeltaTime();

        ostream & operator<<(ostream & out);


};


#endif

