#include "Model.hpp"

#include <cstddef>
#include <cstdint>
#include <ctime>
#include <random>
#include <vector>

std::vector<Planet*> Model::planets{};
std::vector<SolarSystem*> Model::stars{};

Model::Model(int const width_, int const height_, View& view_)
    : width{width_}
    , height{height_}
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
    return;
}
