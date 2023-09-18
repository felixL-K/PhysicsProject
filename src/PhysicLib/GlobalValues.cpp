#include "GlobalValues.hpp"
#include <bits/stdc++.h>
#include "../GUI/guiMain.hpp"

int GlobalValues::PHYSICS_TICK_SPEED = 200;
double GlobalValues::timeScale = 17140;
double GlobalValues::SOLARMASS = 1.989 * pow(10,30); // in kg
double GlobalValues::SOLARDIAMETER = 1400000000; // in m
double GlobalValues::ASTROUNIT = 150000000000; // in m
double GlobalValues::GRAVITATIONALCONSTANT = 6.674*pow(10,-11);
double GlobalValues::pathSize = 30;


// double GlobalValues::getDeltaTime() {
//     return 1/(double)PHYSICS_TICK_SPEED*timeScale;
//     // return 86400; // number of seconds in a day
//     // return 1;

// }

void GlobalValues::updateGlobalValues() {
    GlobalValues::timeScale = guiMain::getSliderTimeScale().getSliderValue();
    GlobalValues::pathSize = guiMain::getSliderPathSize().getSliderValue();

}