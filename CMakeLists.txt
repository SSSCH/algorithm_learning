cmake_minimum_required(VERSION 3.13)
project(algorithm_learning)

set(CMAKE_CXX_STANDARD 11)
add_library(Solution Solution.cpp)
add_executable(algorithm_learning test.cpp Solution.cpp)
target_link_libraries(algorithm_learning Solution)