#include "GlobalValues.hpp"
#include <bits/stdc++.h>

int GlobalValues::PHYSICS_TICK_SPEED = 200;
double GlobalValues::timeScale = 200;
double GlobalValues::SOLARMASS = 1.989 * pow(10,30); // in kg
double GlobalValues::SOLARDIAMETER = 1400000; // in km
double GlobalValues::ASTROUNIT = 150000000; // in km
double GlobalValues::DELTATIME = 0.0000000001;

double GlobalValues::getDeltaTime() {
    return 1/(double)PHYSICS_TICK_SPEED*timeScale;
}