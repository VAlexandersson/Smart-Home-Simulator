cmake_minimum_required(VERSION 3.26)
project(Smart_Home_Simulator)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)