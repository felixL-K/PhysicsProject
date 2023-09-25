#include "System.hpp"
#include <bits/stdc++.h>
#include "GlobalValues.hpp"

template <class T, class U>
// Constructeur
System<T, U>::System(Vector2D center) : paths{}, celestialBodys{}, dimension{30 * GlobalValues::ASTROUNIT, 30 * GlobalValues::ASTROUNIT}, center{center}
{
  double rand1 = (double)rand() / RAND_MAX;
  double massSun = (rand1 * 7.5 + 0.5) * GlobalValues::SOLARMASS;
  body = new T{massSun, center, this};
  body->setDiameter(GlobalValues::SOLARDIAMETER);
}

template <class T, class U>
System<T, U>::~System()
{
  cout << "deleting System" << endl;

  for (int i = 0; i < celestialBodys.size(); i++)
  {
    delete (celestialBodys[i]);
  }

  delete body;
}

template <class T, class U>
vector<U *> System<T, U>::getBodys()
{
  return celestialBodys;
}

template <class T, class U>
map<U *, vector<Vector2D>> System<T, U>::getPaths()
{
  return paths;
}

template <class T, class U>
Vector2D System<T, U>::getDimension()
{
  return dimension;
}
template <class T, class U>
Vector2D System<T, U>::getCenter()
{
  return center;
}

template <class T, class U>
void System<T, U>::addBody(U *body)
{
  celestialBodys.push_back(body);
  addPath(body, body->getPosition());
  return;
}

template <class T, class U>
// vector<Vector2D> getPathOfBody(CelestialBody* body) {

// }

void System<T, U>::addPath(U *body, Vector2D vect)
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

template <class T, class U>

// maintenant des vector de pointeurs, il faut jouer avec vector dans le maine pour comprendre
// comment marchent les fonctions begin, end etc sur des int et des int*
void System<T, U>::findIndexBody(CelestialBody *ser)
{
  // std::vector<CelestialBody*>::iterator it;
  // it = std::find(*(celestialBodys.begin()),*(celestialBodys.end()), *ser);
  // if (it != celestialBodys.end()) {
  //   std::cout << "Element " << ser << " found at position : ";
  //   std::cout << it - celestialBodys.begin() << " (counting from zero) \n";
  // }
  // else
  //   std::cout << "Element not found.\n\n";
}

template <class T, class U>
void System<T, U>::updateAllPositions()
{
  for (unsigned int i = 0; i < getBodys().size(); i++)
  {
    getBodys()[i]->updatePosition();
  }
}

template <class T, class U>
void System<T, U>::newtonGravAll()
{
  for (unsigned int i = 0; i < getBodys().size(); i++)
  {
    for (unsigned int j = 0; j < getBodys().size(); j++)
    {
      if (i != j)
      {
        getBodys()[i]->newtonGrav(getBodys()[j]);
      }
    }
    getBodys()[i]->newtonGrav(body);
  }
}

template <class T, class U>
void System<T, U>::generateRandomU()
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
  std::normal_distribution<double> distribution(0, 0.05);
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

  U *object = new U{m, Vector2D{x, y}, this};
  object->addVelocity(Vector2D{vx, vy});
  // object->diameter = findDiametre(m);

  // cout << "===============" << endl;
}

template <class T, class U>
void System<T, U>::generateLessRandomU()
{
  double height = dimension.getX() / 2;
  double width = dimension.getY() / 2;

  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::normal_distribution<double> distribution(0, 0.05);
  double numberX = distribution(gen);
  double numberY = distribution(gen);
  // cout << "x : " << numberX << endl;
  // cout << "y : " << numberY << endl;

  double x = numberX * width;
  if (x < 0)
  {
    x = -x;
  }
  x += center.getX();

  double y = numberY * height;
  if (y < 0)
  {
    y = -y;
  }
  y += center.getY();

  double f = (double)rand() / RAND_MAX;
  double m = f * pow(10, 4) * pow(10, 23);

  // f = (double)rand() / RAND_MAX;
  // double vx = f * 10;
  double vx = 0;

  f = (double)rand() / RAND_MAX;
  double vy = f * 10 * (-1);

  U *object = new U{m, Vector2D{x, y}, this};
  object->addVelocity(Vector2D{vx, vy});
  // object->diameter = findDiametre(m);

  // cout << "===============" << endl;
}

template <class T, class U>
void System<T, U>::generateXAxisU()
{
  double height = dimension.getX() / 2;
  double width = dimension.getY() / 2;

  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::normal_distribution<double> distribution(0, 0.05);
  double numberX = distribution(gen);
  double numberY = distribution(gen);
  // cout << "x : " << numberX << endl;
  // cout << "y : " << numberY << endl;

  double x = numberX * width;
  if (x < 0)
  {
    x = -x;
  }
  x += center.getX();

  double y = 0;

  double f = (double)rand() / RAND_MAX;
  double m = f * pow(10, 4) * pow(10, 23);

  // f = (double)rand() / RAND_MAX;
  // double vx = f * 10;
  double vx = 0;

  f = (double)rand() / RAND_MAX;
  double vy = f * 5 * (-1) - 5;

  U *object = new U{m, Vector2D{x, y}, this};
  object->addVelocity(Vector2D{vx, vy});
  // object->diameter = findDiametre(m);

  // cout << "===============" << endl;
}

template <class T, class U>

T *System<T, U>::getT()
{
  return body;
}

template <class T, class U>
void System<T, U>::setT(T *s)
{
  body = s;
}