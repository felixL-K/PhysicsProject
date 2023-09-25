cmake_minimum_required(VERSION 3.16.3)
project(physicProject)
add_library(physicProject Vector2D.cpp CelestialBody.cpp SolarSystem.cpp PlanetSystem.cpp Planet.cpp Star.cpp GlobalValues.cpp Model.cpp Satellite.cpp) 


# install(TARGETS physicProject DESTINATION lib)
# with set_target_properties(...) it becoms :
set_target_properties(physicProject PROPERTIES PUBLIC_HEADER Vector2D.hpp CelestialBody.hpp SolarSystem.hpp PlanetSystem.hpp Star.hpp Planet.hpp GlobalValues.hpp Model.hpp Satellite.hpp)
install(TARGETS physicProject LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)
        