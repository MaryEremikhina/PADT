cmake_minimum_required(VERSION 3.31)
project(StarsWatching)

set(CMAKE_CXX_STANDARD 20)

add_executable(StarsWatching main.cpp
        HASH.h
        HASH.cpp)
