cmake_minimum_required(VERSION 2.8) 

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(minesweeper)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(sources
    src/main.cpp 
    src/Game.cpp 
    src/Cell.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${sources})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CURSES_LIBRARIES})