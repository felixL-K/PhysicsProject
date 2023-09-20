
#include "View.hpp"
#include "SliderSFML.hpp"
#include "../PhysicLib/SolarSystem.hpp"
#include "../PhysicLib/Model.hpp"

#include <string>

SliderSFML View::sliderTimeScale{100, 100, 5000, 30000, "TimeScale"};
SliderSFML View::sliderPathSize{100, 200, 3, 300, "Path Size",30};

View::View(int const width_, int const height_, sf::RenderWindow& mainWin_, sf::RenderWindow& sliderWin_)
    : mainWindow{mainWin_}
    , sliderWindow{sliderWin_}
{
    
}

void View::drawSolarSystem(SolarSystem* system, sf::RenderWindow *window) {
    for(unsigned int i = 0; i < system->getBodys().size(); i++) {
        system->getBodys()[i]->drawObject(window);
    }
    system->getStar()->drawObject(window);
}

void View::drawPaths(SolarSystem* system, sf::RenderWindow *window) {
    for (const auto& kv : system->getPaths()) {
        for(unsigned int i = 1; i < kv.second.size(); i++) {
            sf::Vertex line[2];
            line[0].position = sf::Vector2f(kv.second[i].getX(), kv.second[i].getY());
            line[0].color  = kv.first->getColor();
            line[1].position = sf::Vector2f(kv.second[i-1].getX(), kv.second[i-1].getY());
            line[1].color = kv.first->getColor();
            window->draw(line, 2, sf::Lines);
        }
    }
}

void View::drawPathsArt(SolarSystem* system, sf::RenderWindow *window) {
    for (const auto& path : system->getPaths()) {
        int pathSise = path.second.size();
        int n = pathSise;
        int i = 0;
        while(i<pathSise) {
            sf::Vertex line[2];
            line[0].position = sf::Vector2f(path.second[i].getX(), path.second[i].getY());
            line[0].color  = path.first->getColor();
            line[1].position = sf::Vector2f(path.second[i-n].getX(), path.second[i-n].getY());
            line[1].color = path.first->getColor();
            window->draw(line, 2, sf::Lines);
            i += 1;
        }
    }
}

void View::zoomViewAt(sf::Vector2i pixel, sf::RenderWindow& window, float zoom) {
	const sf::Vector2f beforeCoord{ window.mapPixelToCoords(pixel) };
	sf::View view{ window.getView() };
	view.zoom(zoom);
	window.setView(view);
	const sf::Vector2f afterCoord{ window.mapPixelToCoords(pixel) };
	const sf::Vector2f offsetCoords{ beforeCoord - afterCoord };
	view.move(offsetCoords);
	window.setView(view);
}

SliderSFML View::getSliderTimeScale() {
    return sliderTimeScale;
}

SliderSFML View::getSliderPathSize() {
    return sliderPathSize;
}

void View::update(int pos, bool const state, std::uint64_t const iterations_) {
    iterations = iterations_;
    model_was_updated = true;
}

void View::display() {
    if (model_was_updated) {
        model_was_updated = false;
    }

    mainWindow.setTitle(std::to_string(iterations));

    for (int i =0; i< Model::getSolarSystems().size();i++) {
        drawSolarSystem(Model::getSolarSystems()[i],&mainWindow);
    }

    for (int i =0; i< Model::getSolarSystems().size();i++) {
        drawPaths(Model::getSolarSystems()[i],&mainWindow);
    }

    // Updating slider window
    sliderTimeScale.draw(sliderWindow);
    sliderPathSize.draw(sliderWindow);
}
