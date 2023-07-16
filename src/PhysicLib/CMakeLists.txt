cmake_minimum_required(VERSION 3.16.3)
project(physicProject)
add_library(physicProject Vector2D.cpp CelestialBody.cpp SolarSystem.cpp Planet.cpp Star.cpp GlobalValues.cpp)


# install(TARGETS physicProject DESTINATION lib)
# with set_target_properties(...) it becoms :
set_target_properties(physicProject PROPERTIES PUBLIC_HEADER Vector2D.hpp CelestialBody.hpp SolarSystem.hpp Star.hpp Planet.hpp GlobalValues.hpp ddd)
install(TARGETS physicProject LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)
        