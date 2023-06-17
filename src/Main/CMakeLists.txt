cmake_minimum_required(VERSION 3.16.3)

project(cmakeProject)

# add_executable(${PROJECT_NAME} mainClass.cpp)
add_executable(cmakeProject mainClass.cpp)

install(TARGETS cmakeProject DESTINATION bin)
# install(TARGETS <executable_name/library> DESTINATION bin)
# installs it in the bin dir
# this is to be able to call $cmakeProject anywhere

target_link_libraries(cmakeProject physicProject)
