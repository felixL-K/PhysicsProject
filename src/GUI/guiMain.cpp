#include "guiMain.hpp"
#include "../PhysicLib/GlobalValues.hpp"

// #include <iostream>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>
// #include <vector>
using namespace sf;

SliderSFML guiMain::sliderTimeScale{100, 100, 5000, 30000, "TimeScale"};
SliderSFML guiMain::sliderPathSize{100, 200, 3, 300, "Path Size", 30};

guiMain::guiMain()
{
}

// Test d'interface graphique : les manipulations des tuiles peuvent se faire au clavier
void guiMain::play(SolarSystem *system)
{

    RenderWindow window(VideoMode(900, 900), "Rendering the rectangle1.");
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(0, 50));
    sf::Vector2f Center(system->getCenter().getX(), system->getCenter().getY());
    double HalfSizeX = 5 * GlobalValues::ASTROUNIT;
    double HalfSizeY = 5 * GlobalValues::ASTROUNIT;
    sf::Vector2f HalfSize(HalfSizeX, HalfSizeY);
    sf::View View1(Center, HalfSize);
    window.setView(View1);

    // Slider window
    sf::RenderWindow sliderWindow(sf::VideoMode(500, 500), "Slider!");
    sliderWindow.setFramerateLimit(60);
    sliderWindow.setPosition(sf::Vector2i(50, 10));

    while (window.isOpen() && sliderWindow.isOpen())
    {
        GlobalValues::updateGlobalValues();
        // Updating principal window
        window.clear(Color::Black);
        system->newtonGravAll();
        system->updateAllPositions();
        this->drawAllObjects(system, &window);
        this->drawPaths(system, &window);
        window.display();

        // Updating slider window
        sliderWindow.clear(sf::Color(25, 29, 33));
        sliderTimeScale.draw(sliderWindow);
        sliderPathSize.draw(sliderWindow);
        sliderWindow.display();

        // defining zoom speed
        const float zoomAmount{1.1f}; // zoom by 10%

        // System of turn per second
        const sf::Time freezeLength{sf::milliseconds(1000.0 / GlobalValues::PHYSICS_TICK_SPEED)};
        sf::Clock freezeClock;
        while (freezeClock.getElapsedTime() < freezeLength)
        {
            sf::Event event;
            while (window.pollEvent(event) || sliderWindow.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    // Close window button clicked.
                    window.close();
                    sliderWindow.close();
                }
                if (event.type == sf::Event::MouseWheelScrolled)
                {
                    if (event.mouseWheelScroll.delta > 0)
                        zoomViewAt({event.mouseWheelScroll.x, event.mouseWheelScroll.y}, window, (1.f / zoomAmount));
                    else if (event.mouseWheelScroll.delta < 0)
                        zoomViewAt({event.mouseWheelScroll.x, event.mouseWheelScroll.y}, window, zoomAmount);
                }
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        std::cout << "the right button was pressed" << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    }
                }
                else if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::BackSpace)
                    {
                        window.setView(View1);
                    }
                }
            }
        }
    }
}

void guiMain::drawAllObjects(SolarSystem *system, RenderWindow *window)
{
    for (unsigned int i = 0; i < system->getPlanetSystems().size(); i++)
    {
        system->getPlanetSystems()[i]->getPlanet()->drawObject(window);
    }
    system->getStar()->drawObject(window);
}

void guiMain::drawPaths(SolarSystem *system, RenderWindow *window)
{
    for (const auto &kv : system->getPaths())
    {
        for (unsigned int i = 1; i < kv.second.size(); i++)
        {
            sf::Vertex line[2];
            line[0].position = sf::Vector2f(kv.second[i].getX(), kv.second[i].getY());
            line[0].color = kv.first->getPlanet()->getColor();
            line[1].position = sf::Vector2f(kv.second[i - 1].getX(), kv.second[i - 1].getY());
            line[1].color = kv.first->getPlanet()->getColor();
            window->draw(line, 2, sf::Lines);
        }
    }
}

guiMain::~guiMain()
{
    cout << "deleting guiMain" << endl;
    // delete system;
}

void guiMain::zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, float zoom)
{
    const sf::Vector2f beforeCoord{window.mapPixelToCoords(pixel)};
    sf::View view{window.getView()};
    view.zoom(zoom);
    window.setView(view);
    const sf::Vector2f afterCoord{window.mapPixelToCoords(pixel)};
    const sf::Vector2f offsetCoords{beforeCoord - afterCoord};
    view.move(offsetCoords);
    window.setView(view);
}

SliderSFML guiMain::getSliderTimeScale()
{
    return sliderTimeScale;
}

SliderSFML guiMain::getSliderPathSize()
{
    return sliderPathSize;
}