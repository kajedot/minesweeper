cmake_minimum_required(VERSION 3.13)
project(minesweeper)

set(CMAKE_CXX_STANDARD 11)

add_executable(minesweeper main.cpp minesBoard.cpp minesBoard.h)