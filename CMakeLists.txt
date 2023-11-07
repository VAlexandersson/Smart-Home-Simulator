cmake_minimum_required(VERSION 3.26)
project(Smart_Home_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Smart_Home_Simulator src/main.cpp
        src/Device.cpp
        include/Device.h
        include/Light.h
        include/Controller.h)
