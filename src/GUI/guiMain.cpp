#include "guiMain.hpp"
#include "../PhysicLib/GlobalValues.hpp"

using namespace sf;

SliderSFML guiMain::sliderTimeScale{100, 100, 5000, 30000, "TimeScale"};
SliderSFML guiMain::sliderPathSize{100, 200, 3, 300, "Path Size", 30};

guiMain::guiMain()
    : menuOpen{false}
    , menuButton{sf::Vector2f(30, 24)}
    , menuPanel{sf::Vector2f(380, 220)} {
    systems.clear();

    menuButton.setPosition(sf::Vector2f(10, 10));
    menuButton.setFillColor(sf::Color(25, 29, 33, 200));
    menuButton.setOutlineColor(sf::Color(192, 192, 192));
    menuButton.setOutlineThickness(1);

    menuPanel.setPosition(sf::Vector2f(0, 40));
    menuPanel.setFillColor(sf::Color(25, 29, 33, 200));
}

// Test d'interface graphique : les manipulations des tuiles peuvent se faire au clavier
void guiMain::play(SolarSystem *system) {
    RenderWindow window(sf::VideoMode(sf::Vector2u(900, 900)), "Rendering the rectangle1.");

    systems.push_back(new Galaxy{system->getCenter()});
    systems[0]->addSolarSystem(system);

    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(0, 50));
    sf::Vector2f Center(system->getCenter().getX(), system->getCenter().getY());
    // Initial scale: 5 AU across 900 pixels, kept the same whatever the window size
    const float worldPerPixel = 5 * GlobalValues::ASTROUNIT / 900;
    auto homeView = [&]() {
        return sf::View(Center, sf::Vector2f(window.getSize()) * worldPerPixel);
    };
    window.setView(homeView());
    sf::Vector2u windowSize = window.getSize();

    while (window.isOpen()) {
        GlobalValues::updateGlobalValues();
        // Updating principal window
        window.clear(Color::Black);
        for (auto galaxy : systems) {
            galaxy->newtonGravAll();
            galaxy->updateAllPositions();
        }
        this->drawAllGalaxies(&window);
        this->drawPaths(&window);
        this->drawMenu(window);
        window.display();

        // defining zoom speed
        const float zoomAmount{1.1f}; // zoom by 10%

        // System of turn per second
        const sf::Time freezeLength{sf::milliseconds(1000.0 / GlobalValues::PHYSICS_TICK_SPEED)};
        sf::Clock freezeClock;
        while (freezeClock.getElapsedTime() < freezeLength) {
            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }

                // Resize the view with the window so objects are not stretched,
                // keeping the current zoom level and center
                if (auto resized = event->getIf<sf::Event::Resized>()) {
                    sf::View view = window.getView();
                    view.setSize(sf::Vector2f(view.getSize().x * resized->size.x / windowSize.x,
                                              view.getSize().y * resized->size.y / windowSize.y));
                    window.setView(view);
                    windowSize = resized->size;
                }

                if (auto scroll = event->getIf<sf::Event::MouseWheelScrolled>()) {
                    if (isOverMenu(scroll->position)) {
                        // no zoom while scrolling over the menu
                    } else if (scroll->delta > 0)
                        zoomViewAt(sf::Vector2i(scroll->position), window, 1.f / zoomAmount);
                    else
                        zoomViewAt(sf::Vector2i(scroll->position), window, zoomAmount);
                }

                if (auto mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
                    if (mouse->button == sf::Mouse::Button::Left &&
                        menuButton.getGlobalBounds().contains(sf::Vector2f(mouse->position))) {
                        menuOpen = !menuOpen;
                    }
                    if (mouse->button == sf::Mouse::Button::Right && !isOverMenu(mouse->position)) {
                        sf::Vector2f worldPos = window.mapPixelToCoords(mouse->position);
                        SolarSystem *newSystem = new SolarSystem(Vector2D{worldPos.x, worldPos.y});
                        for (int i = 0; i < 100; i++)
                            newSystem->generateXAxisPlanet();
                        systems[0]->addSolarSystem(newSystem);
                        std::cout << "Created new SolarSystem at: " << worldPos.x << ", "
                                  << worldPos.y << std::endl;
                    }
                }

                if (auto key = event->getIf<sf::Event::KeyPressed>()) {
                    if (key->code == sf::Keyboard::Key::Backspace) {
                        window.setView(homeView());
                    }
                    if (key->code == sf::Keyboard::Key::M) {
                        menuOpen = !menuOpen;
                    }
                }
            }
        }
    }
}

// Draws the menu button and, if open, the slider panel in screen coordinates
void guiMain::drawMenu(sf::RenderWindow &window) {
    const sf::View worldView = window.getView();
    // 1 unit = 1 pixel of the current window size, so the menu never stretches
    window.setView(sf::View(sf::FloatRect({0, 0}, sf::Vector2f(window.getSize()))));

    window.draw(menuButton);
    // three bars of the "hamburger" icon
    for (int i = 0; i < 3; i++) {
        sf::RectangleShape bar(sf::Vector2f(20, 2));
        bar.setPosition(sf::Vector2f(15, 16 + i * 6));
        bar.setFillColor(sf::Color(192, 192, 192));
        window.draw(bar);
    }

    if (menuOpen) {
        window.draw(menuPanel);
        sliderTimeScale.draw(window);
        sliderPathSize.draw(window);
    }

    window.setView(worldView);
}

bool guiMain::isOverMenu(sf::Vector2i pixel) {
    const sf::Vector2f point(pixel);
    return menuButton.getGlobalBounds().contains(point) ||
           (menuOpen && menuPanel.getGlobalBounds().contains(point));
}

void guiMain::drawAllObjects(SolarSystem *system, RenderWindow *window) {
    for (unsigned int i = 0; i < system->getBodys().size(); i++) {
        system->getBodys()[i]->drawObject(window);
    }
    system->getStar()->drawObject(window);
}

void guiMain::drawAllGalaxies(RenderWindow *window) {
    for (int i = 0; i < systems.size(); i++) {
	Galaxy *galaxy = systems[i];

	// Outline of the galaxy, 1 pixel thick whatever the zoom
	const float radius = galaxy->getDimension().getX() / 2;
	const float pixelSize = window->getView().getSize().x / window->getSize().x;
	sf::CircleShape outline(radius, 200);
	outline.setOrigin(sf::Vector2f(radius, radius));
	outline.setPosition(sf::Vector2f(galaxy->getCenter().getX(), galaxy->getCenter().getY()));
	outline.setFillColor(sf::Color::Transparent);
	outline.setOutlineColor(sf::Color(120, 120, 200));
	outline.setOutlineThickness(pixelSize);
	window->draw(outline);

	for (int j = 0; j < galaxy->getSolarSystems().size(); j++) {
	    SolarSystem *system = galaxy->getSolarSystems()[j];
	    drawAllObjects(system, window);
	}
    }
}

void guiMain::drawPaths(RenderWindow *window) {
    for (int i = 0; i < systems.size(); i++) {
	Galaxy *galaxy = systems[i];
	for (int j = 0; j < galaxy->getSolarSystems().size(); j++) {
	    SolarSystem *system = galaxy->getSolarSystems()[j];
	    for (const auto &kv : system->getPaths()) {
		for (unsigned int i = 1; i < kv.second.size(); i++) {
		    sf::Vertex line[2];
		    line[0].position = sf::Vector2f(kv.second[i].getX(), kv.second[i].getY());
		    line[0].color = kv.first->getColor();
		    line[1].position = sf::Vector2f(kv.second[i - 1].getX(), kv.second[i - 1].getY());
		    line[1].color = kv.first->getColor();
		    window->draw(line, 2, sf::PrimitiveType::Lines);
		}
	    }
	}
    }
}

guiMain::~guiMain() {
    for (auto sys : systems)
        delete sys;
    cout << "deleting guiMain" << endl;
    // delete system;
}

void guiMain::zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, float zoom) {
    const sf::Vector2f beforeCoord{window.mapPixelToCoords(pixel)};
    sf::View view{window.getView()};
    view.zoom(zoom);
    window.setView(view);
    const sf::Vector2f afterCoord{window.mapPixelToCoords(pixel)};
    const sf::Vector2f offsetCoords{beforeCoord - afterCoord};
    view.move(offsetCoords);
    window.setView(view);
}

SliderSFML &guiMain::getSliderTimeScale() { return sliderTimeScale; }

SliderSFML &guiMain::getSliderPathSize() { return sliderPathSize; }
