#include "../PhysicLib/Vector2D.hpp"

int main() {
    Vector2D v{1,2};
    v.add(v);
    std::cout << v << std::endl;
}