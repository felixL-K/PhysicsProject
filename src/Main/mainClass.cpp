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

    Planet mercure{3.3*pow(10,23),Vector2D{0,GlobalValues::ASTROUNIT*0.39},system};
    mercure.setDiameter(4900000);
    mercure.setVelocity(Vector2D{47900,0});

    Planet venus{4.9*pow(10,24),Vector2D{0,GlobalValues::ASTROUNIT*0.72},system};
    venus.setDiameter(12100000);
    venus.setVelocity(Vector2D{35000,0});

    Planet earth{6*pow(10,24),Vector2D{0,GlobalValues::ASTROUNIT},system};
    earth.setDiameter(12700000);
    earth.setVelocity(Vector2D{29800,0});

    Planet mars{6.4*pow(10,23),Vector2D{0,GlobalValues::ASTROUNIT*1.52},system};
    mars.setDiameter(6800000);
    mars.setVelocity(Vector2D{24100,0});

    guiMain g{};
    g.play(system);

    delete system;
	return 0;
}
