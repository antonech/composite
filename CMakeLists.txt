cmake_minimum_required(VERSION 3.10)
project(patterns)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-Wl,--gc-sections -s")

add_executable(patterns main.cpp composition.cpp app.h app.cpp)

target_link_libraries(patterns stdc++fs)
