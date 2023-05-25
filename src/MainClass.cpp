#include "MainClass.hpp"

MainClass::MainClass() {}

MainClass::~MainClass() {}


double MainClass::getDeltaTime() {
    return 1 / (double) TICK_SPEED * timeScale;
}

int main(int argc, char *argv[])
{
    std::cout << "MainClass begins" << '\n';
    
    Vector2D v{10,20};

    CelestialBody cb{};
 
    return EXIT_SUCCESS;
}
