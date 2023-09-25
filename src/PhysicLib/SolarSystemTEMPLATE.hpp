#include "System.hpp"

#ifndef _SOLARSYSTEM
#define _SOLARSYSTEM

// template <class T, class U>
// class SolarSystem : public System<T,U> {

// };

// template<>
class SolarSystem : public System<Star, Planet>
{
private:

public:
    SolarSystem(Vector2D center);
    virtual ~SolarSystem();
};

#endif
