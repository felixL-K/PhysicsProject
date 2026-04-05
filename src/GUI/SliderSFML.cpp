#include "SliderSFML.hpp"


SliderSFML::SliderSFML(int x, int y) {
    xCord = x;
    yCord = y;
    axisHeight = 10;
    axisWidth = 200;
    sliderWidth = 20;
    sliderHeight = 30;

    if (!font.openFromFile("./Neon.ttf"))
	std::cout << "Error loading font\n";

    axis.setPosition(sf::Vector2f(x, y));
    axis.setOrigin(sf::Vector2f(0, axisHeight / 2));
    axis.setSize(sf::Vector2f(axisWidth, axisHeight));
    axis.setFillColor(sf::Color(63,63,63));
    slider.setPosition(sf::Vector2f(x, y));
    slider.setOrigin(sf::Vector2f(sliderWidth / 2, sliderHeight / 2));
    slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
    slider.setFillColor(sf::Color(192,192,192));
}

SliderSFML::SliderSFML(int x, int y, int min, int max, std::string title1) {
    title = title1;
    xCord = x;
    yCord = y;
    axisHeight = 10;
    axisWidth = 200;
    sliderWidth = 20;
    sliderHeight = 30;

    if (!font.openFromFile("./Neon.ttf"))
	std::cout << "Error loading font\n";

    axis.setPosition(sf::Vector2f(x, y));
    axis.setOrigin(sf::Vector2f(0, axisHeight / 2));
    axis.setSize(sf::Vector2f(axisWidth, axisHeight));
    axis.setFillColor(sf::Color(63,63,63));
    slider.setPosition(sf::Vector2f(x, y));
    slider.setOrigin(sf::Vector2f(sliderWidth / 2, sliderHeight / 2));
    slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
    slider.setFillColor(sf::Color(192,192,192));

    // =========== CREATE ====================
    minValue = min;
    maxValue = max;
    setSliderValue((max-min)/2+min);
}

SliderSFML::SliderSFML(int x, int y, int min, int max, std::string title1, int value) {
    title = title1;
    xCord = x;
    yCord = y;
    axisHeight = 10;
    axisWidth = 200;
    sliderWidth = 20;
    sliderHeight = 30;

    if (!font.openFromFile("./Neon.ttf"))
	std::cout << "Error loading font\n";

    axis.setPosition(sf::Vector2f(x, y));
    axis.setOrigin(sf::Vector2f(0, axisHeight / 2));
    axis.setSize(sf::Vector2f(axisWidth, axisHeight));
    axis.setFillColor(sf::Color(63,63,63));
    slider.setPosition(sf::Vector2f(x, y));
    slider.setOrigin(sf::Vector2f(sliderWidth / 2, sliderHeight / 2));
    slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
    slider.setFillColor(sf::Color(192,192,192));

    // =========== CREATE ====================
    minValue = min;
    maxValue = max;
    setSliderValue(value);
}

sf::Text SliderSFML::returnText(int x, int y, std::string z, int fontSize) {
    sf::Text t(font, z, fontSize);
    t.setPosition(sf::Vector2f(x, y));
    t.setFillColor(sf::Color::Red);
    return t;
}

void SliderSFML::create(int min, int max) {
    sliderValue = min;
    minValue = min;
    maxValue = max;
}

void SliderSFML::logic(sf::RenderWindow &window) {
    if (slider.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))
	&& sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
	if (sf::Mouse::getPosition(window).x >= xCord && sf::Mouse::getPosition(window).x <= xCord + axisWidth) {
	    auto mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	    slider.setPosition(sf::Vector2f(mousePos.x, yCord));
	    sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue)));
	}
    }
}

float SliderSFML::getSliderValue() {
    return sliderValue;
}

void SliderSFML::setSliderValue(float newValue) {
    if (newValue >= minValue && newValue <= maxValue) {
	sliderValue = newValue;
	float diff = maxValue - minValue;
	float diff2 = newValue - minValue;
	float zzz = axisWidth / diff;
	float posX = zzz*diff2;
	posX += xCord;
	slider.setPosition(sf::Vector2f(posX, yCord));
    }
}

void SliderSFML::setSliderPercentValue(float newPercentValue) {
    if (newPercentValue >= 0 && newPercentValue <= 100) {
	sliderValue = newPercentValue / 100 * maxValue;
	slider.setPosition(sf::Vector2f(xCord + (axisWidth*newPercentValue / 100), yCord));
    }
}

void SliderSFML::draw(sf::RenderWindow &window) {
    logic(window);
    window.draw(returnText(xCord - 10, yCord + 5, std::to_string(minValue), 20));
    window.draw(axis);
    window.draw(returnText(xCord + axisWidth - 10, yCord + 5, std::to_string(maxValue), 20));
    window.draw(slider);
    window.draw(returnText(slider.getPosition().x - sliderWidth, slider.getPosition().y - sliderHeight,
			   std::to_string((int)sliderValue), 15));
    window.draw(returnText(10, yCord-sliderHeight*1.75, title, 20));
}
