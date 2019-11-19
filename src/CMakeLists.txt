cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp lagerung/Container.cpp lagerung/Container.h lagerung/Shelf.cpp lagerung/Shelf.h lagerung/Robo.cpp lagerung/Robo.h lagerung/Size.h)