cmake_minimum_required(VERSION 3.20)
project(trivia_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(trivia_game GameRunner.cpp Game.cpp)
