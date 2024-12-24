#include "../include/Tetromino.hpp"

Tetromino::Tetromino() {
    setRandomShape();
}

void Tetromino::setRandomShape() {
    static const std::vector<std::vector<sf::Vector2i>> shapes = {
        {{0, 0}, {1, 0}, {0, 1}, {1, 1}},     // Cuadrado
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}},     // Línea
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},     // L normal
        {{0, 0}, {1, 0}, {2, 0}, {0, 1}},     // L invertida
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},     // Z normal
        {{1, 0}, {2, 0}, {0, 1}, {1, 1}},     // Z invertida
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}}      // T
    };

    static const std::vector<unsigned int> colors = {
        sf::Color::Red.toInteger(),
        sf::Color::Green.toInteger(),
        sf::Color::Blue.toInteger(),
        sf::Color::Yellow.toInteger(),
        sf::Color::Magenta.toInteger(),
        sf::Color::Cyan.toInteger(),
        sf::Color::White.toInteger()
    };

    int index = rand() % shapes.size();
    shape = shapes[index];
    color = colors[index];
}

void Tetromino::rotate() {
    for (auto& block : shape)
    {
        int temp = block.x;
        block.x = -block.y;
        block.y = temp;
    }
    
}

const std::vector<sf::Vector2i>& Tetromino::getShape() const {
    return shape; // Devuelve la forma del tetromino
}

unsigned int Tetromino::getColor() const {
    return color; // Devuelve el color del tetromino
}
