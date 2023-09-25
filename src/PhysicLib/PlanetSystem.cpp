#include "PlanetSystem.hpp"
#include <bits/stdc++.h>
#include "GlobalValues.hpp"

// Constructeur
PlanetSystem::PlanetSystem(Vector2D center, SolarSystem *s) : paths{}, satellites{}, dimension{5 * GlobalValues::MOONDISTANCE, 5 * GlobalValues::MOONDISTANCE}
{
    solarSystem = s;
    solarSystem->addPlanetSysem(this, center);
}

PlanetSystem::~PlanetSystem()
{
    cout << "deleting PlanetSystem" << endl;

    for (int i = 0; i < satellites.size(); i++)
    {
        delete (satellites[i]);
    }

    delete planet;
}

vector<Satellite *> PlanetSystem::getSatellites()
{
    return satellites;
}

map<Satellite *, vector<Vector2D>> PlanetSystem::getPaths()
{
    return paths;
}

Vector2D PlanetSystem::getDimension()
{
    return dimension;
}
Vector2D PlanetSystem::getCenter()
{
    return planet->getPosition();
}

void PlanetSystem::addSatellite(Satellite *body)
{
    satellites.push_back(body);
    addPath(body, body->getPosition());
    return;
}

// vector<Vector2D> getPathOfBody(CelestialBody* body) {

// }

void PlanetSystem::addPath(Satellite *body, Vector2D vect)
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

// maintenant des vector de pointeurs, il faut jouer avec vector dans le maine pour comprendre
// comment marchent les fonctions begin, end etc sur des int et des int*
void PlanetSystem::findIndexBody(CelestialBody *ser)
{
    // std::vector<CelestialBody*>::iterator it;
    // it = std::find(*(satellites.begin()),*(satellites.end()), *ser);
    // if (it != satellites.end()) {
    //   std::cout << "Element " << ser << " found at position : ";
    //   std::cout << it - satellites.begin() << " (counting from zero) \n";
    // }
    // else
    //   std::cout << "Element not found.\n\n";
}

void PlanetSystem::updatePosition()
{
    //planet->getPosition().add(getPlanet()->getVelocity() * GlobalValues::timeScale);
    planet->updatePosition();
    //getCenter().add(getPlanet()->getVelocity() * GlobalValues::timeScale);
    getSolarSystem()->addPath(this, getCenter());
}

void PlanetSystem::updateAllPositionsSatellites()
{
    for (unsigned int i = 0; i < getSatellites().size(); i++)
    {
        getSatellites()[i]->updatePosition();
    }
}

void PlanetSystem::newtonGravAll()
{
    for (unsigned int i = 0; i < getSatellites().size(); i++)
    {
        for (unsigned int j = 0; j < getSatellites().size(); j++)
        {
            if (i != j)
            {
                getSatellites()[i]->newtonGrav(getSatellites()[j]);
            }
        }
        getSatellites()[i]->newtonGrav(planet);
        getSatellites()[i]->newtonGrav(solarSystem->getStar());
    }
}

void PlanetSystem::generateRandomSatellite()
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

    Satellite *object = new Satellite{m, Vector2D{x, y}, this};
    object->addVelocity(Vector2D{vx, vy});
    // object->diameter = findDiametre(m);

    // cout << "===============" << endl;
}

void PlanetSystem::generateLessRandomSatellite()
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

    Satellite *object = new Satellite{m, Vector2D{x, y}, this};
    object->addVelocity(Vector2D{vx, vy});
    // object->diameter = findDiametre(m);

    // cout << "===============" << endl;
}

void PlanetSystem::generateXAxisSatellite()
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
    x += GlobalValues::MOONDISTANCE / 2;

    double y = getCenter().getY();

    double f = (double)rand() / RAND_MAX;
    double m = planet->getMass() / 10000000; //f * pow(10, 4) * pow(10, 22);

    // f = (double)rand() / RAND_MAX;
    // double vx = f * 10;
    double vx = 0;

    f = (double)rand() / RAND_MAX;
    double vy = f * (- 3) -0.5;

    Satellite *object = new Satellite{m, Vector2D{x, y}, this};
    //object->addVelocity(Vector2D{vx, vy});
    object->addVelocity(Vector2D{planet->getVelocity().getX()/15000, planet->getVelocity().getY()/15000});

    double d = (double)rand() / RAND_MAX;
    
    object->setDiameter(d * 5000 +10);

    // cout << "===============" << endl;
}

Planet *PlanetSystem::getPlanet()
{
    return planet;
}

SolarSystem* PlanetSystem::getSolarSystem(){
    return solarSystem;
}


void PlanetSystem::setPlanet(Planet *s)
{
    planet = s;
}