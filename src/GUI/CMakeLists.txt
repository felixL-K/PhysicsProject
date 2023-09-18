# cmake_minimum_required(VERSION 3.16.3)

# project(physicProjectGUI)

# add_executable(physicGUI guiMain.cpp)

# # target_link_directories(physicTest PRIVATE ${CMAKE_SOURCE_DIR}/../PhysicLib/build)
# # because we did ligns 7-9 in ../PhysicLib/CMakeLists.txt
# # and make install in ../PhysicLib/build
# target_link_libraries(physicGUI physicProject sfml-graphics sfml-window sfml-system sfml-audio)

#===============================================================================================

cmake_minimum_required(VERSION 3.16.3)
project(physicProjectGUI)
add_library(physicProjectGUI guiMain.cpp SliderSFML.cpp)


# install(TARGETS physicProjectGUI DESTINATION lib)
# with set_target_properties(...) it becoms :
set_target_properties(physicProjectGUI PROPERTIES PUBLIC_HEADER guiMain.hpp SliderSFML.hpp ddd)
install(TARGETS physicProjectGUI LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)
        