#ifndef _MAINGUI
#define _MAINGUI

#include <SFML/Graphics.hpp>

#include "../PhysicLib/Vector2D.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/CelestialBody.hpp"

#include "../GUI/SliderSFML.hpp"


class guiMain {
    private:
        //SolarSystem* system;
        static SliderSFML sliderTimeScale;
    public:
        guiMain();
        void drawAllObjects(SolarSystem* system, sf::RenderWindow *window);
        void drawPaths(SolarSystem* system, sf::RenderWindow *window);
        void play(SolarSystem* system);
        virtual ~guiMain();
        void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow& window, float zoom);

        static SliderSFML getSliderTimeScale();
};


#endif

