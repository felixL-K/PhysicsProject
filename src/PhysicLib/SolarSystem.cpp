#include "SolarSystem.hpp"
#include <bits/stdc++.h>
#include "../GUI/guiMain.hpp"
#include "GlobalValues.hpp"


// Constructeur
SolarSystem::SolarSystem(Vector2D center) : paths{}, celestialBodys{}, dimension{30*GlobalValues::ASTROUNIT,30*GlobalValues::ASTROUNIT}, center{center} {
  double rand1 = (double)rand() / RAND_MAX;
  double massSun = (rand1*7.5 + 0.5) * GlobalValues::SOLARMASS;
  star = new Star{massSun,center,this};
  star->setDiameter(GlobalValues::SOLARDIAMETER);
}

SolarSystem::~SolarSystem(){
  cout << "deleting SolarSystem" << endl;

  for (int i =0; i< celestialBodys.size();i++)
   {
     delete (celestialBodys[i]);
   } 

  delete star;
}

vector<Planet*> SolarSystem::getBodys() {
  return celestialBodys;
}

map<Planet*,vector<Vector2D>> SolarSystem::getPaths() {
  return paths;
}

Vector2D SolarSystem::getDimension() {
  return dimension;
}
Vector2D SolarSystem::getCenter() {
  return center;
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
  if(GlobalValues::pathSize == 0) {

  } else {
    if (paths[body].size() < GlobalValues::pathSize) {
      paths[body].push_back(vect);
    }
    if (paths[body].size() == GlobalValues::pathSize) {
      paths[body].erase(paths[body].begin());
      paths[body].push_back(vect);
    }
    if (paths[body].size() > GlobalValues::pathSize) {
      paths[body].erase(paths[body].begin());
      paths[body].erase(paths[body].begin());
      paths[body].push_back(vect);
    }
  }
  
  
}


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
        getBodys()[i]->newtonGrav(getBodys()[j]);
      }
    }
    getBodys()[i]->newtonGrav(star);
  }
}

void SolarSystem::generateRandomPlanet() {
  double height = dimension.getX()/2;
  double width = dimension.getY()/2;

  // double f = (double)rand() / RAND_MAX;
  // double x = f * width;
  // double neg = (double)rand() / RAND_MAX;
  // if (neg<0.5) {
  //   x = -x;
  // }
  // x += center.getX();
  // // if (x<0) { x = -x; }
  // // cout << "x : " << x << endl;

  // f = (double)rand() / RAND_MAX;
  // double y = f * height;
  // neg = (double)rand() / RAND_MAX;
  // if (neg<0.5) {
  //   y = -y;
  // }
  // y += center.getY();
  // // if (y<0) { y = -y; }
  // // cout << "y : " << y << endl;

  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::normal_distribution<double> distribution(0,0.05);
  double numberX = distribution(gen);
  double numberY = distribution(gen);
  // cout << "x : " << numberX << endl;
  // cout << "y : " << numberY << endl;

  double x = numberX * width;
  x += center.getX();
  // if (x<0) { x = -x; }
  // cout << "x : " << x << endl;

  double y = numberY * height;
  y += center.getY();
  // if (y<0) { y = -y; }
  // cout << "y : " << y << endl;
  

  double f = (double)rand() / RAND_MAX;
  //double m = f * 50;
  double m = f*pow(10,4)*pow(10,23);
  // if (m<0) { m = -m; }
  //cout << "m : " << m << endl;

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

  // cout << "===============" << endl;
}

void SolarSystem::generateLessRandomPlanet() {
  double height = dimension.getX()/2;
  double width = dimension.getY()/2;

  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::normal_distribution<double> distribution(0,0.05);
  double numberX = distribution(gen);
  double numberY = distribution(gen);
  // cout << "x : " << numberX << endl;
  // cout << "y : " << numberY << endl;

  double x = numberX * width;
  if (x<0) {
    x = -x;
  }
  x += center.getX();

  double y = numberY * height;
  if (y<0) {
    y = -y;
  }
  y += center.getY() ;
  

  double f = (double)rand() / RAND_MAX;
  double m = f*pow(10,4)*pow(10,23);


  // f = (double)rand() / RAND_MAX;
  // double vx = f * 10;
  double vx = 0;
  
  f = (double)rand() / RAND_MAX;
  double vy = f * 10 *(-1);
  
  Planet *object = new Planet{m, Vector2D{x, y}, this};
  object->addVelocity(Vector2D{vx, vy});
  //object->diameter = findDiametre(m);

  // cout << "===============" << endl;
}

void SolarSystem::generateXAxisPlanet() {
  double height = dimension.getX()/2;
  double width = dimension.getY()/2;

  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::normal_distribution<double> distribution(0,0.05);
  double numberX = distribution(gen);
  double numberY = distribution(gen);
  // cout << "x : " << numberX << endl;
  // cout << "y : " << numberY << endl;

  double x = numberX * width;
  if (x<0) {
    x = -x;
  }
  x += center.getX();

  double y = 0;
  

  double f = (double)rand() / RAND_MAX;
  double m = f*pow(10,4)*pow(10,23);


  // f = (double)rand() / RAND_MAX;
  // double vx = f * 10;
  double vx = 0;
  
  f = (double)rand() / RAND_MAX;
  double vy = f * 5 *(-1)-5;
  
  Planet *object = new Planet{m, Vector2D{x, y}, this};
  object->addVelocity(Vector2D{vx, vy});
  //object->diameter = findDiametre(m);

  // cout << "===============" << endl;
}


Star* SolarSystem::getStar() {
  return star;
}

void SolarSystem::setStar(Star* s) {
  star = s;
}