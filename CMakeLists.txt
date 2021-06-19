cmake_minimum_required(VERSION 3.17)
project(SieveEratosthenes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O2 -fopenmp")
add_executable(SieveEratosthenes control_parallelism.cpp data_parallelism.cpp)
