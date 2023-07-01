#include "SolarSystem.hpp"
#include <bits/stdc++.h>
#include "../GUI/guiMain.hpp"

double solarMass = 20000;

// Constructeur
SolarSystem::SolarSystem(Vector2D center) : paths{}, celestialBodys{}, dimension{1000,1000} {
  double f = (double)rand() / RAND_MAX;
  double m = (f*7.5 + 0.5) * solarMass;
  star = new Star{m,center,this};
}

// SolarSystem::SolarSystem(const SolarSystem &) {

// }

// virtual SolarSystem::~SolarSystem() {

// }

vector<Planet*> SolarSystem::getBodys() {
  return celestialBodys;
}

map<Planet*,vector<Vector2D>> SolarSystem::getPaths() {
  return paths;
}

Vector2D SolarSystem::getDimension() {
  return dimension;
}

void SolarSystem::addBody(Planet* body) {
    celestialBodys.push_back(body);
    addPath(body,body->getPosition());
    return;
}

// vector<Vector2D> getPathOfBody(CelestialBody* body) {

// }

void SolarSystem::addPath(Planet* body, Vector2D vect) {
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
    getBodys()[i]->newtonGrav(*star);
  }
}

void SolarSystem::generateRandomPlanet() {
  double height = dimension.getX();
  double width = dimension.getY();;

  double f = (double)rand() / RAND_MAX;
  double x = f * width;
  if (x<0) { x = -x; }
  // cout << "x : " << x << endl;

  f = (double)rand() / RAND_MAX;
  double y = f * height;
  if (y<0) { y = -y; }
  // cout << "y : " << y << endl;

  f = (double)rand() / RAND_MAX;
  double m = f * 50;
  if (m<0) { m = -m; }
  // cout << "m : " << m << endl;

  f = (double)rand() / RAND_MAX;
  double vx = f * 10;
  double neg = (double)rand() / RAND_MAX;
  if (neg<0.5) {
    vx = -vx;
  }
  // cout << "vx : " << vx << endl;
  f = (double)rand() / RAND_MAX;
  double vy = f * 10;
  neg = (double)rand() / RAND_MAX;
  if (neg<0.5) {
    vy = -vy;
  }
  // cout << "vy : " << vy << endl;

  Planet *object = new Planet{m, Vector2D{x, y}, this};
  object->addVelocity(Vector2D{vx, vy});
  //object->diameter = findDiametre(m);

}


Star* SolarSystem::getStar() {
  return star;
}
void SolarSystem::setStar(Star* s) {
  star = s;
}