cmake_minimum_required(VERSION 3.20)
project(esercitazione6) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCES gradientecon.cpp)
add_executable(gradiente ${SOURCES})


target_link_libraries(gradiente PRIVATE Eigen3::Eigen)