cmake_minimum_required(VERSION 3.10)
project(Tetris)

# Agregar directorios de encabezados
include_directories(include, assets)

# Agregar archivos fuente
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Board.cpp
    src/Tetromino.cpp
)

# Crear el ejecutable
add_executable(Tetris ${SOURCES})

# Enlazar SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
target_link_libraries(Tetris sfml-graphics sfml-window sfml-system sfml-audio)
