cmake_minimum_required(VERSION 3.9)
project(PongGame)

set(CMAKE_CXX_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

file(GLOB ALL_SRC
        "*.h"
        "*.cpp"
        )

add_executable(PongGame ${ALL_SRC} ArduinoEmulator.h)
target_link_libraries(PongGame ${CURSES_LIBRARIES})