cmake_minimum_required(VERSION 3.8)
project(noughts_and_crosses)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES tictactoe.cpp tictactoe.hpp game.cpp)
add_executable(tictactoe ${SOURCE_FILES})