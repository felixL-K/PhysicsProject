#include "SolarSystem.hpp"
#include <bits/stdc++.h>

std::vector<std::vector<Vector2D>> SolarSystem::paths = {};
std::vector<CelestialBody*> SolarSystem::celestialBodys = {};

// Constructeur
SolarSystem::SolarSystem() {
  
}

// SolarSystem::SolarSystem(const SolarSystem &) {

// }

// virtual SolarSystem::~SolarSystem() {

// }

vector<CelestialBody*> SolarSystem::getBodys() {
  return celestialBodys;
}

void SolarSystem::addBody(CelestialBody* body) {
    celestialBodys.push_back(body);
    return;
}

// vector<Vector2D> getPathOfBody(CelestialBody* body) {

// }

void SolarSystem::addPath(CelestialBody* body, Vector2D* vect) {
    // if (paths[body].size() > pathSize) {
    //   paths[body].erase(paths[body].begin());
    //   paths[body].insert(paths[body].begin(),Vector2D(vect));
    // } else {
    //   paths[body].insert(paths[body].begin(),Vector2D(vect));
    // }
    // return;
}

// ostream & operator<<(ostream & out, SolarSystem & d) {

// }

// map<CelestialBody, vector<Vector2D>> SolarSystem::getPaths() {
//   return paths;
// }


// maintenant des vector de pointeurs, il faut jouer avec vector dans le maine pour comprendre 
// comment marchent les fonctions begin, end etc sur des int et des int*
void SolarSystem::findIndexBody(CelestialBody* ser) {
  // std::vector<CelestialBody*>::iterator it;
  // it = std::find(*(celestialBodys.begin()),*(celestialBodys.end()), *ser);
  // if (it != celestialBodys.end()) {
  //   std::cout << "Element " << ser << " found at position : ";
  //   std::cout << it - celestialBodys.begin() << " (counting from zero) \n";
  // }
  // else
  //   std::cout << "Element not found.\n\n";
}
