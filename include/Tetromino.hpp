#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tetromino {

private:
    std::vector<sf::Vector2i> shape;
    int color;

public:
    Tetromino();
    void setShape(const std::vector<sf::Vector2i>& newShape);
    const std::vector<sf::Vector2i>& getShape() const;
    int getColor() const;
    void rotate();
};

#endif // TETROMINO_HPP
