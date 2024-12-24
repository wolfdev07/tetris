// include/Tetromino.hpp
#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Tetromino {

private:
    std::vector<sf::Vector2i> shape;
    unsigned int color;

public:
    Tetromino();
    void setRandomShape();
    void setShape(const std::vector<sf::Vector2i>& newShape);
    const std::vector<sf::Vector2i>& getShape() const; // Declaración
    unsigned int getColor() const; // Declaración
    void rotate();
};

#endif // TETROMINO_HPP
