cmake_minimum_required(VERSION 3.10)
project(composite)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-Wl,--gc-sections -s")

add_executable(composite main.cpp reader.cpp app.h app.cpp)

target_link_libraries(composite stdc++fs)
