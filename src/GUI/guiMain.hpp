#ifndef _MAINGUI
#define _MAINGUI

#include <SFML/Graphics.hpp>

#include "../PhysicLib/Vector2D.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/CelestialBody.hpp"


class guiMain {
    private:

    public:
        void drawAllObjects(SolarSystem system, sf::RenderWindow *window);
        void play();
};


#endif
