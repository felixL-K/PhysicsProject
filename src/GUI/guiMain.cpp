#include "guiMain.hpp"

// #include <iostream>
// #include <SFML/System.hpp> 
// #include <SFML/Window.hpp> 
// #include <SFML/Graphics.hpp> 
// #include <vector>
using namespace sf;

guiMain::guiMain(SolarSystem* systemS) : system{systemS} {

}

// Test d'interface graphique : les manipulations des tuiles peuvent se faire au clavier
void guiMain::play() {
    RenderWindow window(VideoMode(system->getDimension().getX(),system->getDimension().getY()),"Rendering the rectangle1.");
    window.setPosition(sf::Vector2i(10, 50));
    sf::Vector2f Center(system->getDimension().getX()/2,system->getDimension().getY()/2);
    sf::Vector2f HalfSize(2000, 2000);
    sf::View View1(Center, HalfSize);
    window.setView(View1);

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                // Close window button clicked.
                window.close();
            }
        }
        window.clear(Color::Black);
        system->newtonGravAll();
        system->updateAllPositions();
        this->drawAllObjects(*system,&window);
        this->drawPaths(*system,&window);
        window.display();
    }
}

void guiMain::drawAllObjects(SolarSystem system, RenderWindow *window) {
    for(unsigned int i = 0; i < system.getBodys().size(); i++) {
        system.getBodys()[i]->drawObject(window);
    }
}

void guiMain::drawPaths(SolarSystem system, RenderWindow *window) {
    for (const auto& kv : system.getPaths()) {
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



int main() {
    SolarSystem system{};

    Vector2D v1{10,20};
    CelestialBody body1{10,v1,&system};
    Vector2D v2{400,400};
    CelestialBody body2{20000,v2,&system};
    body2.addVelocity(Vector2D{0.5,0});
    for(int i=0;i<100;i++)
        system.generateRandomObjetPhysique();

    guiMain g{&system};
    g.play();

    return 0;
}