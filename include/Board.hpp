// include/Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Board: public sf::Drawable{

private:
    static constexpr int WIDTH = 20;
    static constexpr int HEIGHT = 30;
    int grid[HEIGHT][WIDTH];
    sf::RectangleShape cells[HEIGHT][WIDTH];

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    Board();
    void reset(const sf::RenderWindow& window);
    bool isValidPosition(int x, int y, const std::vector<sf::Vector2i>& shape);
    void placeTetromino(int x, int y, const std::vector<sf::Vector2i>& shape, int color);
    int clearFullLines(); 
};

#endif // BOARD_HPP
