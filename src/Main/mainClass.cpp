#include "MainClass.hpp"
#include "Vector2D.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../GUI/guiMain.hpp"
// #include <wx/wx.h>

#include <iostream>
int main() {
	std::cout << "hello cmake tests" << std::endl;
	Vector2D v{1,2};
    v.add(v);
    std::cout << v << std::endl;


	SolarSystem system{Vector2D{400,400}};

    for(int i=0;i<200;i++)
        system.generateRandomPlanet();

    guiMain g{&system};
    g.play();

	return 0;
}

double MainClass::getDeltaTime(){
	return 1;
}