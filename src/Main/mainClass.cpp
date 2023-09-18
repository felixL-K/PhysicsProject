#include "MainClass.hpp"
#include "Vector2D.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../GUI/guiMain.hpp"
// #include <wx/wx.h>

#include <iostream>
int main() {

	SolarSystem* system = new SolarSystem{Vector2D{0,0}};

    for(int i=0;i<100;i++)
        system->generateRandomPlanet();

    guiMain g{};
    g.play(system);

    delete system;

	return 0;
}
