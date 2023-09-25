#include "SolarSystem.hpp"
#include <bits/stdc++.h>
#include "GlobalValues.hpp"

// Constructeur
SolarSystem::SolarSystem(Vector2D center) : paths{}, planetSystems{}, dimension{5 * GlobalValues::ASTROUNIT, 5 * GlobalValues::ASTROUNIT}
{
  double rand1 = (double)rand() / RAND_MAX;
  double massSun = (rand1 * 7.5 + 0.5) * GlobalValues::SOLARMASS;
  star = new Star{massSun, center, this};
  star->setDiameter(GlobalValues::SOLARDIAMETER);
}

SolarSystem::~SolarSystem()
{
  cout << "deleting SolarSystem" << endl;

  for (int i = 0; i < planetSystems.size(); i++)
  {
    delete (planetSystems[i]);
  }

  delete star;
}

vector<PlanetSystem *> SolarSystem::getPlanetSystems()
{
  return planetSystems;
}

map<PlanetSystem *, vector<Vector2D>> SolarSystem::getPaths()
{
  return paths;
}

Vector2D SolarSystem::getDimension()
{
  return dimension;
}
Vector2D SolarSystem::getCenter()
{
  return star->getPosition();
}

void SolarSystem::addPlanetSysem(PlanetSystem *body)
{
  planetSystems.push_back(body);
  addPath(body, body->getCenter());
  return;
}
void SolarSystem::addPlanetSysem(PlanetSystem *body, Vector2D c)
{
  planetSystems.push_back(body);
  addPath(body, c);
  return;
}

// vector<Vector2D> getPathOfBody(CelestialBody* body) {

// }

void SolarSystem::addPath(PlanetSystem *body, Vector2D vect)
{
  if (paths.find(body) == paths.end())
  {
    vector<Vector2D> vectvect;
    paths[body] = vectvect;
  }
  if (GlobalValues::pathSize == 0)
  {
  }
  else
  {
    if (paths[body].size() < GlobalValues::pathSize)
    {
      paths[body].push_back(vect);
    }
    if (paths[body].size() == GlobalValues::pathSize)
    {
      paths[body].erase(paths[body].begin());
      paths[body].push_back(vect);
    }
    if (paths[body].size() > GlobalValues::pathSize)
    {
      paths[body].erase(paths[body].begin());
      paths[body].erase(paths[body].begin());
      paths[body].push_back(vect);
    }
  }
}


void SolarSystem::updateAllPositions()
{
  for (unsigned int i = 0; i < getPlanetSystems().size(); i++)
  {
    getPlanetSystems()[i]->updatePosition();
    // update positions of satellites
    getPlanetSystems()[i]->updateAllPositionsSatellites();
  }
}

void SolarSystem::newtonGravAll()
{
  for (unsigned int i = 0; i < getPlanetSystems().size(); i++)
  {
    // for (unsigned int j = 0; j < getPlanetSystems().size(); j++)
    // {
    //   if (i != j)
    //   {
    //     getPlanetSystems()[i]->getPlanet()->newtonGrav(getPlanetSystems()[j]->getPlanet());
    //   }
    // }
    getPlanetSystems()[i]->getPlanet()->newtonGravAllStars();
    getPlanetSystems()[i]->newtonGravAll();
  }
}

void SolarSystem::generateRandomPlanetSystem()
{
  double height = dimension.getX() / 2;
  double width = dimension.getY() / 2;

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
  std::normal_distribution<double> distribution(0, 0.2);
  double numberX = distribution(gen);
  double numberY = distribution(gen);
  // cout << "x : " << numberX << endl;
  // cout << "y : " << numberY << endl;

  double x = numberX * width;
  x += getCenter().getX();
  // if (x<0) { x = -x; }
  // cout << "x : " << x << endl;

  double y = numberY * height;
  y += getCenter().getY();
  // if (y<0) { y = -y; }
  // cout << "y : " << y << endl;

  double f = (double)rand() / RAND_MAX;
  // double m = f * 50;
  double m = f * pow(10, 4) * pow(10, 23);
  // if (m<0) { m = -m; }
  // cout << "m : " << m << endl;

  f = (double)rand() / RAND_MAX;
  double vx = f * 10;
  double neg = (double)rand() / RAND_MAX;
  if (neg < 0.5)
  {
    vx = -vx;
  }
  // cout << "vx : " << vx << endl;
  f = (double)rand() / RAND_MAX;
  double vy = f * 10;
  neg = (double)rand() / RAND_MAX;
  if (neg < 0.5)
  {
    vy = -vy;
  }
  // cout << "vy : " << vy << endl;

  PlanetSystem *planetSys = new PlanetSystem{Vector2D{x, y},this};
  Planet *object = new Planet{m, Vector2D{x, y}, planetSys};
  object->addVelocity(Vector2D{vx, vy});

  // object->diameter = findDiametre(m);

  // cout << "===============" << endl;
}

void SolarSystem::generateLessRandomPlanetSystem()
{
  double height = dimension.getX() / 2;
  double width = dimension.getY() / 2;

  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::normal_distribution<double> distribution(0, 0.2);
  double numberX = distribution(gen);
  double numberY = distribution(gen);
  // cout << "x : " << numberX << endl;
  // cout << "y : " << numberY << endl;

  double x = numberX * width;
  if (x < 0)
  {
    x = -x;
  }
  x += getCenter().getX();

  double y = numberY * height;
  if (y < 0)
  {
    y = -y;
  }
  y += getCenter().getY();

  double f = (double)rand() / RAND_MAX;
  double m = f * pow(10, 4) * pow(10, 23);

  // f = (double)rand() / RAND_MAX;
  // double vx = f * 10;
  double vx = 0;

  f = (double)rand() / RAND_MAX;
  double vy = f * 10 * (-1);

  PlanetSystem *planetSys = new PlanetSystem{Vector2D{x, y},this};
  Planet *object = new Planet{m, Vector2D{x, y}, planetSys};
  object->addVelocity(Vector2D{vx, vy});

  // object->diameter = findDiametre(m);

  // cout << "===============" << endl;
}

void SolarSystem::generateXAxisPlanetSystem()
{
  double height = dimension.getX() / 2;
  double width = dimension.getY() / 2;

  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::normal_distribution<double> distribution(0, 0.2);
  double numberX = distribution(gen);
  double numberY = distribution(gen);
  // cout << "x : " << numberX << endl;
  // cout << "y : " << numberY << endl;

  double x = numberX * width;
  if (x < 0)
  {
    x = -x;
  }
  x = std::fmod(x, pow(10, 14));
  x += getCenter().getX();
  x += GlobalValues::ASTROUNIT / 10;

  double y = getCenter().getY();

  double f = (double)rand() / RAND_MAX;
  double m = f * pow(10, 4) * pow(10, 23);

  // f = (double)rand() / RAND_MAX;
  // double vx = f * 10;
  double vx = 0;

  f = (double)rand() / RAND_MAX;
  double vy = f * 5 * (-1) - 5;
  
  PlanetSystem *planetSys = new PlanetSystem{Vector2D{x, y},this};
  Planet *object = new Planet{m, Vector2D{x, y}, planetSys};
  object->addVelocity(Vector2D{vx, vy});

  double d = (double)rand() / RAND_MAX;
  double diam = d * 3.5 + 0.5;
  double cat = std::fmod((double)rand(), RAND_MAX);
  if (cat > 0.75)
  {
    if (cat > 0.9)
    {
      if (cat > 0.95)
      {
        diam += 16;
      }
      else
      {
        diam += 8;
      }
    }
    else
    {
      diam += 4;
    }
  }
  object->setDiameter(diam * GlobalValues::EARTHDIAMETER);

  for (int i = 0; i < 5; i++)
  {
      planetSys->generateXAxisSatellite();
  }
  // cout << "===============" << endl;
}


Star *SolarSystem::getStar()
{
  return star;
}

void SolarSystem::setStar(Star *s)
{
  star = s;
}