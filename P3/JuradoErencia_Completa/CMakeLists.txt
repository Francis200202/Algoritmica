CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(p3_algoritmica)
ENABLE_LANGUAGE(CXX)
set(CMAKE_CXX_STANDARD 11) # C++11,C++14,17,20
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3 -O0 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3 -Wall")


add_executable(exe main.cpp metodos.cpp serietemporal.cpp punto.cpp recta.cpp)
