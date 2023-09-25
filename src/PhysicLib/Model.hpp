
// #include "../GUI/View.hpp"
#include "Planet.hpp"
#include "SolarSystem.hpp"
// #include "Satellite.hpp"

#include <vector>

class View;

class Model
{
private:
    Vector2D center;
    Vector2D dimension;
    std::uint64_t iterations = 0;

    View &view;

    static std::vector<Planet *> planets;
    static std::vector<SolarSystem *> stars;

    // void seed_grid();
    // int count_neighbors(int const m_origin, int const n_origin) const;
    // void check_rules(int const pos, int const neighbors);
    // void apply_rules(int pos, bool const state);

public:
    Model(int const width_, int const height_, View &view_);

    void update();
    void reset();

    static std::vector<Planet *> getPlanets();
    static std::vector<SolarSystem *> getSolarSystems();

    void addSolarSytemModel(SolarSystem *sys);
};
