#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include "SliderSFML.hpp"
#include "../PhysicLib/SolarSystem.hpp"

class View
{
private:
    sf::RenderWindow &mainWindow;
    sf::RenderWindow &sliderWindow;

    static SliderSFML sliderTimeScale;
    static SliderSFML sliderPathSize;

    std::uint64_t iterations = 0;
    bool model_was_updated = false;

public:
    View(int const width, int const height, sf::RenderWindow &mainWin_, sf::RenderWindow &sliderWin_);
    void drawSolarSystem(SolarSystem *system, sf::RenderWindow *window);
    void drawPaths(SolarSystem *system, sf::RenderWindow *window);
    void drawPathsArt(SolarSystem *system, sf::RenderWindow *window);
    static void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, float zoom);
    static SliderSFML getSliderTimeScale();
    static SliderSFML getSliderPathSize();

    void update(int pos, bool const state, std::uint64_t const iterations_);
    void display();
};
