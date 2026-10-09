#include "../GUI/guiMain.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/Galaxy.hpp"
#include "MainClass.hpp"
#include "Vector2D.hpp"
// #include <wx/wx.h>

#include <iostream>
int main() {

    SolarSystem *system = new SolarSystem{Vector2D{0, 0}};

    for (int i = 0; i < 100; i++)
        system->generateXAxisPlanet();

    guiMain g{};
    g.play(system); // guiMain takes ownership of system

    return 0;
}
