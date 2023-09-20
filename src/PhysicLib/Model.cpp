#include "Model.hpp"

#include <cstddef>
#include <cstdint>
#include <ctime>
#include <random>
#include <vector>
#include <cstdlib>

std::vector<Planet*> Model::planets{};
std::vector<SolarSystem*> Model::stars{};

Model::Model(int const width_, int const height_, View& view_)
    : dimension{width_,height_}
    , center{0,0}
    , view{view_}
{
    reset();
}

void Model::update() {
    for (int i =0; i< stars.size();i++) {
        stars[i]->newtonGravAll();
        stars[i]->updateAllPositions();
    }

    ++iterations;
}

void Model::reset() {
    for (int i =0; i< planets.size();i++) {
        delete (planets[i]);
    } 
    for (int i =0; i< stars.size();i++) {
        delete (stars[i]);
    } 
    iterations = 0;
}

std::vector<Planet*> Model::getPlanets() {
    return planets;
}
std::vector<SolarSystem*> Model::getSolarSystems() {
    return stars;
}

void Model::addSolarSytemModel(SolarSystem* sys){
    stars.push_back(sys);

    // update center
    if(stars.size() == 1) {
        center.setX(sys->getCenter().getX());
        center.setY(sys->getCenter().getY());
    } else {
        center.setX((center.getX()+sys->getCenter().getX())/2);
        center.setY((center.getY()+sys->getCenter().getY())/2);
    }
    

    // update dimension
    if(stars.size() == 1) {
        dimension.setX(sys->getDimension().getX());
        dimension.setY(sys->getDimension().getY());
    } else {
        Vector2D centerUpLeft{center.getX()-(dimension.getX()/2),center.getY()-(dimension.getY()/2)};
        Vector2D centerUpRight{center.getX()+(dimension.getX()/2),center.getY()-(dimension.getY()/2)};
        Vector2D centerDownLeft{center.getX()-(dimension.getX()/2),center.getY()+(dimension.getY()/2)};
        Vector2D centerDownRight{center.getX()+(dimension.getX()/2),center.getY()+(dimension.getY()/2)};

        Vector2D sysUpLeft{sys->getCenter().getX()-(sys->getDimension().getX()/2),sys->getCenter().getY()-(sys->getDimension().getY()/2)};
        Vector2D sysUpRight{sys->getCenter().getX()+(sys->getDimension().getX()/2),sys->getCenter().getY()-(sys->getDimension().getY()/2)};
        Vector2D sysDownLeft{sys->getCenter().getX()-(sys->getDimension().getX()/2),sys->getCenter().getY()+(sys->getDimension().getY()/2)};
        Vector2D sysDownRight{sys->getCenter().getX()+(sys->getDimension().getX()/2),sys->getCenter().getY()+(sys->getDimension().getY()/2)};

        double finalDimX = dimension.getX();
        double finalDimY = dimension.getY();

        if (sysUpLeft.getX()<centerUpLeft.getX()) {
            finalDimX += (abs(centerUpLeft.getX())-abs(sysUpLeft.getX()))*2;
        }
        if (sysUpLeft.getY()<centerUpLeft.getY()) {
            finalDimY += (abs(centerUpLeft.getY())-abs(sysUpLeft.getY()))*2;
        }

        if (sysUpRight.getX()>centerUpRight.getX()) {
            finalDimX += (abs(centerUpRight.getX())-abs(sysUpRight.getX()))*2;
        }
        if (sysUpRight.getY()<centerUpRight.getY()) {
            finalDimY += (abs(centerUpRight.getY())-abs(sysUpRight.getY()))*2;
        }

        if (sysDownLeft.getX()<centerDownLeft.getX()) {
            finalDimX += (abs(centerDownLeft.getX())-abs(sysDownLeft.getX()))*2;
        }
        if (sysDownLeft.getY()>centerDownLeft.getY()) {
            finalDimY += (abs(centerDownLeft.getY())-abs(sysDownLeft.getY()))*2;
        }

        if (sysDownRight.getX()>centerDownRight.getX()) {
            finalDimX += (abs(centerDownRight.getX())-abs(sysDownRight.getX()))*2;
        }
        if (sysDownRight.getY()>centerDownRight.getY()) {
            finalDimY += (abs(centerDownRight.getY())-abs(sysDownRight.getY()))*2;
        }

        dimension.setX(finalDimX);
        dimension.setY(finalDimY);
    }
    return;
}
