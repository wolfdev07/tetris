cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Tetris)

# Agregar directorio de encabezados
include_directories(include)

# Archivos fuente
set(SOURCES
    src/main.cpp
    src/Board.cpp
)

# Agregar ejecutable
add_executable(Game ${SOURCES})

# Enlazar SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(Game sfml-graphics sfml-window sfml-system)
