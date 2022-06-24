cmake_minimum_required(VERSION 3.21)
project(s14_hash_tables)

set(CMAKE_CXX_STANDARD 17)

add_executable(${CMAKE_PROJECT_NAME} main.cpp chash.h)
