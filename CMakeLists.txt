cmake_minimum_required(VERSION 3.29)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(lab1
        main.cpp
        application.cpp
        array.cpp
        complex.cpp
)

target_link_libraries(lab1 ${CURSES_LIBRARIES})
