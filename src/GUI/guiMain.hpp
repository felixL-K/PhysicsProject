#ifndef _MAINGUI
#define _MAINGUI

#include "../GUI/SliderSFML.hpp"
#include "../PhysicLib/CelestialBody.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/Galaxy.hpp"
#include "../PhysicLib/Vector2D.hpp"
#include <SFML/Graphics.hpp>

class guiMain {
  private:
    // SolarSystem* system;
    static SliderSFML sliderTimeScale;
    static SliderSFML sliderPathSize;
    std::vector<Galaxy *> systems;

    // Slider menu, drawn over the main window in screen coordinates
    bool menuOpen;
    sf::RectangleShape menuButton;
    sf::RectangleShape menuPanel;

  public:
    guiMain();
    void drawAllObjects(SolarSystem *system, sf::RenderWindow *window);
    void drawAllGalaxies(sf::RenderWindow *window);
    void drawPaths(sf::RenderWindow *window);
    void drawMenu(sf::RenderWindow &window);
    bool isOverMenu(sf::Vector2i pixel);
    void play(SolarSystem *system);
    virtual ~guiMain();
    void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, float zoom);

    static SliderSFML &getSliderTimeScale();
    static SliderSFML &getSliderPathSize();
};

#endif
