cmake_minimum_required(VERSION 3.20)
project(trivia_game)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(unit_test)

add_executable(trivia_game GameRunner.cpp Game.cpp GameTest.cpp)
target_link_libraries(trivia_game gtest gtest_main)