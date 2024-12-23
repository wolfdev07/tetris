cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Tetris)

# Archivos fuente
set(SOURCES
    src/main.cpp
    #src/Game.cpp
    src/Board.hpp
    #src/Tetromino.cpp
)

# Incluir directorios
include_directories(include)

# Agregar el ejecutable
add_executable(Tetris ${SOURCES})

# Enlazar SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(Tetris sfml-graphics sfml-window sfml-system)
