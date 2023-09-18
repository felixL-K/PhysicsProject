#include "MainClass.hpp"
#include "Vector2D.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/Planet.hpp"
#include "../PhysicLib/GlobalValues.hpp"
#include "../GUI/guiMain.hpp"
// #include <wx/wx.h>


#include <iostream>
int main() {

	SolarSystem* system = new SolarSystem{Vector2D{0,0}};

    // for(int i=0;i<100;i++)
    //     system->generateRandomPlanet();

    Planet mercure{3.33010*pow(10,23),Vector2D{0,46000000000},system};
    mercure.setDiameter(4900000);
    mercure.setVelocity(Vector2D{58970,0});

    Planet venus{4.8673*pow(10,24),Vector2D{0,107480000000},system};
    venus.setDiameter(12100000);
    venus.setVelocity(Vector2D{35260,0});

    Planet earth{5.9722*pow(10,24),Vector2D{0,147095000000},system};
    earth.setDiameter(12700000);
    earth.setVelocity(Vector2D{30290,0});

    Planet mars{6.4169*pow(10,23),Vector2D{0,206650000000},system};
    mars.setDiameter(6800000);
    mars.setVelocity(Vector2D{26500,0});

    guiMain g{};
    g.play(system);

    delete system;
	return 0;
}
