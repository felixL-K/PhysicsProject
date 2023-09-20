#include "MainClass.hpp"
#include "Vector2D.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/GlobalValues.hpp"
#include "../GUI/View.hpp"
#include "Controller.hpp"


#include <iostream>


int main() {

    SolarSystem* system = new SolarSystem{Vector2D{0,0}};
    for(int i=0;i<50;i++) {
        system->generateXAxisPlanet();
    }





	constexpr int width = 900;
    constexpr int height = 900;
    const float zoomAmount{ 1.1f }; // zoom by 10%
    
    // Main window
    sf::RenderWindow window(sf::VideoMode(width, height), "0");
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(0, 50));
    sf::Vector2f Center(system->getCenter().getX(),system->getCenter().getY());
    double HalfSizeX = 5*GlobalValues::ASTROUNIT;
    double HalfSizeY = 5*GlobalValues::ASTROUNIT;
    sf::Vector2f HalfSize(HalfSizeX, HalfSizeY);
    sf::View View1(Center, HalfSize);
    window.setView(View1);

    // Slider window 
    sf::RenderWindow sliderWindow(sf::VideoMode(500, 500), "Slider!");
	sliderWindow.setFramerateLimit(60);
    sliderWindow.setPosition(sf::Vector2i(50, 10));






    Controller controller{width, height, window, sliderWindow};
    controller.addSolarSytem(system);

    
    constexpr float update_delay = 0; //.5;
    sf::Clock clock;
    clock.restart();

    while (window.isOpen() && sliderWindow.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event) || sliderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // Close window button clicked.
                window.close();
                sliderWindow.close();
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0)
                    View::zoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, (1.f / zoomAmount));
                else if (event.mouseWheelScroll.delta < 0)
                    View::zoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, zoomAmount);
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    // get the current mouse position in the window
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    // convert it to world coordinates
                    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                    std::cout << "world x: " << worldPos.x << std::endl;
                    std::cout << "world y: " << worldPos.y << std::endl;
                    SolarSystem* systemN = new SolarSystem{Vector2D{worldPos.x,worldPos.y}};
                    for(int i=0;i<50;i++) {
                        systemN->generateXAxisPlanet();
                    }
                    controller.addSolarSytem(systemN);
                }
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::BackSpace)
                {
                    window.setView(View1);
                }
            }
        }

        GlobalValues::updateGlobalValues();
        window.clear(sf::Color::Black);
        sliderWindow.clear(sf::Color(25,29,33));


        if (clock.getElapsedTime().asSeconds() >= update_delay) {
            controller.update_model();
            clock.restart();
        }

        controller.display_view();

        window.display();
        sliderWindow.display();
    }
}
