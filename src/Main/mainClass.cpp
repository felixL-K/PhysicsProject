#include "MainClass.hpp"
#include "Vector2D.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../GUI/guiMain.hpp"
// #include <wx/wx.h>

#include <iostream>
int main() {

	SolarSystem system{Vector2D{100,100}};

    for(int i=0;i<200;i++)
        system.generateRandomPlanet();

    guiMain g{&system};
    g.play();

	return 0;
}

double MainClass::getDeltaTime(){
	return 1;
}