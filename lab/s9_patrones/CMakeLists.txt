cmake_minimum_required(VERSION 3.19)
project(s9_patrones)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable(${PROJECT_NAME}
        main.cpp
        render.h
        application.cpp application.h
        componente.h
        sfml_factory.h
        sfml_button.h
        sfml_label.h
        sdl_factory.h
        sdl_button.h
        sdl_label.h
        factory.h
        )

target_link_libraries(${PROJECT_NAME}  sfml-system sfml-window sfml-graphics sfml-audio)
