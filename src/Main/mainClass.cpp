#include "MainClass.hpp"
#include "Vector2D.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/Planet.hpp"
#include "../GUI/guiMain.hpp"
// #include <wx/wx.h>

double ASTROUNIT1 = 150000000; // in km

#include <iostream>
int main() {

	SolarSystem* system = new SolarSystem{Vector2D{0,0}};

    // for(int i=0;i<100;i++)
    //     system->generateRandomPlanet();

    Planet mercure{3.3*pow(10,23),Vector2D{0,ASTROUNIT1*0.39},system};
    mercure.setDiameter(4900);
    mercure.setVelocity(Vector2D{30000000000000000,0});

    Planet venus{4.9*pow(10,24),Vector2D{0,ASTROUNIT1*0.72},system};
    venus.setDiameter(12100);
    venus.setVelocity(Vector2D{30000000000000000,0});

    Planet earth{6*pow(10,24),Vector2D{0,ASTROUNIT1},system};
    earth.setDiameter(12700);
    earth.setVelocity(Vector2D{30000000000000000,0});

    Planet mars{6.4*pow(10,23),Vector2D{0,ASTROUNIT1*1.52},system};
    mars.setDiameter(6800);
    mars.setVelocity(Vector2D{25000000000000000,0});

    guiMain g{};
    g.play(system);

    delete system;
	return 0;
}

double MainClass::getDeltaTime(){
	return 1;
}