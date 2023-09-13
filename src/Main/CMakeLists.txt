# cmake_minimum_required(VERSION 3.16.3)

# project(cmakeProject)

# # add_executable(${PROJECT_NAME} mainClass.cpp)
# add_executable(cmakeProject mainClass.cpp)

# install(TARGETS cmakeProject DESTINATION bin)
# # install(TARGETS <executable_name/library> DESTINATION bin)
# # installs it in the bin dir
# # this is to be able to call $cmakeProject anywhere

# target_link_libraries(cmakeProject physicProject)



# ==========================================================

cmake_minimum_required(VERSION 3.16.3)

project(physicProjectMain)

add_executable(physicMain mainClass.cpp)

# target_link_directories(physicTest PRIVATE ${CMAKE_SOURCE_DIR}/../PhysicLib/build)
# because we did ligns 7-9 in ../PhysicLib/CMakeLists.txt
# and make install in ../PhysicLib/build
target_link_libraries(physicMain physicProject physicProjectGUI sfml-graphics sfml-window sfml-system sfml-audio)
