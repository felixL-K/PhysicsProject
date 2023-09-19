
#include "../PhysicLib/Model.hpp"
#include "../GUI/View.hpp"
#include "../PhysicLib/SolarSystem.hpp"

#include <SFML/System.hpp>

class Controller {
    private:
        View view;
        Model model;
        bool is_active = true;

    public:
        Controller(int const width, int const height, sf::RenderWindow& mainWin_, sf::RenderWindow& sliderWin_);

        void update_model();
        void display_view();
        void on_keypress(sf::Event const& event);

        void addSolarSytem(SolarSystem* sys);
    
};
