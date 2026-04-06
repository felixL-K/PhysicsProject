#ifndef _MAINGUI
#define _MAINGUI

#include "../GUI/SliderSFML.hpp"
#include "../PhysicLib/CelestialBody.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/Vector2D.hpp"
#include <SFML/Graphics.hpp>

class guiMain {
  private:
    // SolarSystem* system;
    static SliderSFML sliderTimeScale;
    static SliderSFML sliderPathSize;
    std::vector<SolarSystem *> systems;

  public:
    guiMain();
    void drawAllObjects(SolarSystem *system, sf::RenderWindow *window);
    void drawPaths(SolarSystem *system, sf::RenderWindow *window);
    void play(SolarSystem *system);
    virtual ~guiMain();
    void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, float zoom);

    static SliderSFML getSliderTimeScale();
    static SliderSFML getSliderPathSize();
};

#endif
