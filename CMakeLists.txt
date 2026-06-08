cmake_minimum_required(VERSION 4.1)
project(SegundoProyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(SegundoProyecto main.cpp
        Room.h
        Room.cpp
        Direction.h
        Item.h
        Item.cpp
        Event.cpp
        Event.h
        Player.cpp
        Player.h
        Enemy.cpp
        Enemy.h
        World.cpp
        World.h
        FileManager.cpp
        FileManager.h
)
file(COPY ${CMAKE_SOURCE_DIR}/data
        DESTINATION ${CMAKE_BINARY_DIR})