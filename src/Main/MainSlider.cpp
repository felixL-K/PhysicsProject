#include "../GUI/SliderSFML.hpp"

int main()
{
	sf::RenderWindow sliderWindow(sf::VideoMode(500, 500), "Slider!");
	sliderWindow.setFramerateLimit(60);

	SliderSFML slider1(100, 100);
	SliderSFML slider2(100, 200);
	SliderSFML slider3(100, 300);

	slider1.create(20, 450);
	slider2.create(0, 200);
	slider3.create(0, 100);

	slider1.setSliderValue(235);

	while (sliderWindow.isOpen())
	{
		sf::Event event;
		while (sliderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				sliderWindow.close();
		}

		sliderWindow.clear(sf::Color(25, 29, 33));

		slider1.draw(sliderWindow);
		slider2.draw(sliderWindow);
		slider3.draw(sliderWindow);

		sliderWindow.display();
	}

	return 0;
}