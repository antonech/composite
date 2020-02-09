cmake_minimum_required(VERSION 3.15)
project(patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(patterns main.cpp composition.cpp app.h app.cpp)

target_link_libraries(patterns stdc++fs)
