cmake_minimum_required(VERSION 3.16.3)

project(physicProjectTest)

add_executable(physicTest testMain.cpp)

# target_link_directories(physicTest PRIVATE ${CMAKE_SOURCE_DIR}/../PhysicLib/build)
# because we did ligns 7-9 in ../PhysicLib/CMakeLists.txt
# and make install in ../PhysicLib/build
target_link_libraries(physicTest physicProject)
