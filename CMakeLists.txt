cmake_minimum_required(VERSION 4.1)
project(SegundoProyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(SegundoProyecto main.cpp
        Room.h
        Room.cpp
        Direction.h
        Item.h
        Item.cpp)
