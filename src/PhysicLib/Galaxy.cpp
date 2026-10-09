#include "Galaxy.hpp"
#include "GlobalValues.hpp"

Galaxy::Galaxy(Vector2D center)
    : solarSystems{}
    , center{center}
    , dimension{100 * GlobalValues::ASTROUNIT, 100 * GlobalValues::ASTROUNIT} {
    SolarSystem *solarSystem = new SolarSystem{center};
    solarSystems.push_back(solarSystem);
}

Galaxy::~Galaxy() {
    for (int i = 0; i < solarSystems.size(); i++) {
	delete(solarSystems[i]);
    }
}

vector<SolarSystem *> Galaxy::getSolarSystems() { return solarSystems; }
Vector2D Galaxy::getDimension() { return dimension; }
Vector2D Galaxy::getCenter() { return center; }

void Galaxy::addSolarSystem(SolarSystem *ss) {
    solarSystems.push_back(ss);
    return;
}

void Galaxy::findIndexSolarSystem(SolarSystem *c) {

}

void Galaxy::updateAllPositions() {
    for (int i = 0; i < solarSystems.size(); i++) {
	solarSystems[i]->updateAllPositions();
    }
}

void Galaxy::newtonGravAll() {
    for (int i = 0; i < getSolarSystems().size(); i++) {
	getSolarSystems()[i]->newtonGravAll();
    }
}

void Galaxy::generateRandomSolarSystem() {

}
