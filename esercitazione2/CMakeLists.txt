
cmake_minimum_required(VERSION 3.20)

project(es_2) 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(PROG1 eser.cpp)
set(PROG2 alg.cpp)
add_executable(primo_es ${PROG1})


add_executable(secondo_es ${PROG2})