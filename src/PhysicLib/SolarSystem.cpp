#include "SolarSystem.hpp"
#include <bits/stdc++.h>
#include "../GUI/guiMain.hpp"

// Constructeur
SolarSystem::SolarSystem() : paths{}, celestialBodys{}, dimension{800,800} {
  
}

// SolarSystem::SolarSystem(const SolarSystem &) {

// }

// virtual SolarSystem::~SolarSystem() {

// }

vector<CelestialBody*> SolarSystem::getBodys() {
  return celestialBodys;
}

map<CelestialBody*,vector<Vector2D>> SolarSystem::getPaths() {
  return paths;
}

Vector2D SolarSystem::getDimension() {
  return dimension;
}

void SolarSystem::addBody(CelestialBody* body) {
    celestialBodys.push_back(body);
    addPath(body,body->getPosition());
    return;
}

// vector<Vector2D> getPathOfBody(CelestialBody* body) {

// }

void SolarSystem::addPath(CelestialBody* body, Vector2D vect) {
  if(paths.find(body) == paths.end()) {
    vector<Vector2D> vectvect;
    paths[body] = vectvect;
  }
  if (paths[body].size() >= pathSize) {
    paths[body].erase(paths[body].begin());
  }
  paths[body].push_back(vect);
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

void SolarSystem::updateAllPositions() {
  for(unsigned int i = 0; i < getBodys().size(); i++) {
    getBodys()[i]->updatePosition();
  }
}

void SolarSystem::newtonGravAll() {
  for(unsigned int i = 0; i < getBodys().size(); i++) {
    for(unsigned int j = 0; j < getBodys().size(); j++) {
      if(i != j) {
        getBodys()[i]->newtonGrav(*getBodys()[j]);
      }
    }
  }
}

void SolarSystem::generateRandomObjetPhysique() {
  double height = dimension.getX();
  double width = dimension.getY();;

  
  double f = (double)rand() / RAND_MAX;
  double x = f * width;
  if (x<0) { x = -x; }

  f = (double)rand() / RAND_MAX;
  double y = f * height;
  if (y<0) { y = -y; }

  f = (double)rand() / RAND_MAX;
  double m = f * 500;
  if (m<0) { m = -m; }

  f = (double)rand() / RAND_MAX;
  double vx = f * 10;
  double vy = f * 10;

  CelestialBody object{m, Vector2D{50, 50}, this};
  //this->addBody(&object);
  object.addVelocity(Vector2D{vx, vy});
  //object.diameter = findDiametre(m);
}

