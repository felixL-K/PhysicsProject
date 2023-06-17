#include "guiMain.hpp"

// #include <iostream>
// #include <SFML/System.hpp> 
// #include <SFML/Window.hpp> 
// #include <SFML/Graphics.hpp> 
// #include <vector>
using namespace sf;

// Test d'interface graphique : les manipulations des tuiles peuvent se faire au clavier
void guiMain::play() {
    RenderWindow window(VideoMode(800,800),"Rendering the rectangle1.");

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                // Close window button clicked.
                window.close();
            }
        }
        window.clear(Color::Black);
        SolarSystem system;
        system.newtonGravAll();
        system.updateAllPositions();
        this->drawAllObjects(system,&window);
        window.display();
    }
}

void guiMain::drawAllObjects(SolarSystem system, RenderWindow *window) {
    for(unsigned int i = 0; i < system.getBodys().size(); i++) {
        system.getBodys()[i]->drawObject(window);
    }
}



int main() {
    SolarSystem system{};

    Vector2D v1{10,20};
    CelestialBody body1{10,v1};
    Vector2D v2{50,50};
    CelestialBody body2{10,v2};
    body2.addVelocity(Vector2D{0.5,0});

    guiMain g;
    g.play();

    return 0;
}