#include "MainToScale.hpp"
#include "../GUI/guiMain.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/GlobalValues.hpp"
#include "Vector2D.hpp"
// #include <wx/wx.h>

#include <iostream>
int main() {

    SolarSystem *system = new SolarSystem{Vector2D{0, 0}};
    system->getStar()->setMass(GlobalValues::SOLARMASS);

    Planet *mercure = new Planet{3.3011*pow(10,23),Vector2D{0,46000000000},system};
    mercure->setDiameter(4879000);
    mercure->setVelocity(Vector2D{58985,0});

    Planet *venus = new Planet{4.8675*pow(10,24),Vector2D{0,107480000000},system};
    venus->setDiameter(12104000);
    venus->setVelocity(Vector2D{35262,0});

    Planet *earth = new Planet{5.9722*pow(10,24),Vector2D{0,147095000000},system};
    earth->setDiameter(12756000);
    earth->setVelocity(Vector2D{30291,0});

    Planet *mars = new Planet{6.4171*pow(10,23),Vector2D{0,206650000000},system};
    mars->setDiameter(6792000);
    mars->setVelocity(Vector2D{26503,0});

    Planet *jupiter = new Planet{1.8982*pow(10,27),Vector2D{0,740600000000},system};
    jupiter->setDiameter(142984000);
    jupiter->setVelocity(Vector2D{13710,0});

    Planet *saturn = new Planet{5.6834*pow(10,26),Vector2D{0,1357600000000},system};
    saturn->setDiameter(120536000);
    saturn->setVelocity(Vector2D{10142,0});

    Planet *uranus = new Planet{8.6810*pow(10,25),Vector2D{0,2732700000000},system};
    uranus->setDiameter(51118000);
    uranus->setVelocity(Vector2D{7131,0});

    Planet *neptune = new Planet{1.02413*pow(10,26),Vector2D{0,4471100000000},system};
    neptune->setDiameter(49528000);
    neptune->setVelocity(Vector2D{5475,0});

    guiMain g{};
    g.play(system); // guiMain takes ownership of system


    return 0;
}
