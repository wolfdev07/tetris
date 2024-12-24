// include/Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Board: public sf::Drawable{


public:
    static constexpr int WIDTH = 20;
    static constexpr int HEIGHT = 30;
    Board();
    void reset(const sf::RenderWindow& window);
    bool isValidPosition(int x, int y, const std::vector<sf::Vector2i>& shape);
    void placeTetromino(int x, int y, const std::vector<sf::Vector2i>& shape, int color);
    void updateCellColors();
    int clearFullLines();


private:
    int grid[HEIGHT][WIDTH];
    std::vector<std::vector<sf::RectangleShape>> cells;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // BOARD_HPP
