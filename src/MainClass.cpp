#include "MainClass.hpp"
#include "SolarSystem.hpp"

#include <vector>

int main(int argc, char *argv[]) {
    std::cout << "MainClass begins..." << '\n';

    CelestialBody cb{};
    Vector2D v1{1,2};
    CelestialBody cb1{12,v1};
    Vector2D v2{3,4};
    CelestialBody cb2{34,v2};

    SolarSystem s{};

    vector<CelestialBody *> bodys = s.getBodys();
    
    for (long unsigned int i = 0; i < bodys.size(); i++) {
        cout << *bodys[i] << endl;
    }

    for (long unsigned int i = 0; i < s.getPaths()[bodys[0]].size(); i++) {
        cout << i << "=>" << s.getPaths()[bodys[0]][i] << endl;
    }
    //cout << s.getPaths()[bodys[0]][0] << endl;
    cb.addVelocity(v1);
    cb.updatePosition();
    cb.updatePosition();
    cb.updatePosition();
    cb.updatePosition();
    cb.updatePosition();
    cb.updatePosition();
    cb.updatePosition();
    for (long unsigned int i = 0; i < s.getPaths()[bodys[0]].size(); i++) {
        cout << i << "=>" << s.getPaths()[bodys[0]][i] << endl;
    }
    //cout << s.getPaths()[bodys[0]][0] << endl;


    // vector<int> v = {1,2,3,4};
    // v.push_back(5);
    // cout << v.capacity() << endl;
    
    std::cout << "MainClass end..." << '\n';
    return EXIT_SUCCESS;
}


MainClass::MainClass() {}

MainClass::~MainClass() {}

double MainClass::getDeltaTime() {
    return 1 / (double) TICK_SPEED * timeScale;
}