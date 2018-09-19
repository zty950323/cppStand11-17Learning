cmake_minimum_required(VERSION 3.0)
project(cpp_stand_learning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -fPIC")

message(CMAKE_CXX_FLAGS)

add_subdirectory(chapter_02)
add_subdirectory(chapter_03)
add_subdirectory(chapter_04)
add_subdirectory(chapter_05)
add_subdirectory(chapter_06)
add_subdirectory(chapter_07)
add_subdirectory(chapter_09)
add_subdirectory(effectiveCpp)