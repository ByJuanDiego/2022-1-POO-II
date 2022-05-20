cmake_minimum_required(VERSION 3.21)
project(s9_SFML)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES main.cpp render.h apliccation.h component.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} button.h lable.h)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}  sfml-system sfml-window sfml-graphics sfml-audio)
