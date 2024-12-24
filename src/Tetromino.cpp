#include "../include/Tetromino.hpp"

Tetromino::Tetromino(): color(1) {
    shape = {{0, 0}, {1, 0}, {1, 1 }, {0, 1}};
}

void Tetromino::setShape(const std::vector<sf::Vector2i>& newShape) {
    shape = newShape;
}

const std::vector<sf::Vector2i>& Tetromino::getShape() const {
    return shape;
}

int Tetromino::getColor() const {
    return color;
}

void Tetromino::rotate() {
    for (auto& block : shape)
    {
        int temp = block.x;
        block.x = -block.y;
        block.y = temp;
    }
}