#include "MainClass.hpp"
#include "SolarSystem.hpp"

#include <vector>

MainClass::MainClass() {}

MainClass::~MainClass() {}


double MainClass::getDeltaTime() {
    return 1 / (double) TICK_SPEED * timeScale;
}

int main(int argc, char *argv[]) {
    std::cout << "MainClass begins..." << '\n';

    CelestialBody cb{};
    SolarSystem s{};

    vector<CelestialBody *> bodys = s.getBodys();
    CelestialBody *body0 = s.getBodys()[0];
    cout << *body0 << endl;
     
    // for (int i = 0; i < paths.size(); i++) {
    //     cout << paths[i] << endl;
    // }

    // vector<int> v = {1,2,3,4};
    // v.push_back(5);
    // cout << v.capacity() << endl;
    
    std::cout << "MainClass end..." << '\n';
    return EXIT_SUCCESS;
}
