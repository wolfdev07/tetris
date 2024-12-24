#include "../include/Board.hpp"

Board::Board() {
    reset();
}

void Board::reset() {
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            grid[i][j] = 0;
            cells[i][j].setSize(sf::Vector2f(20, 20));
            cells[i][j].setPosition(j * 20, i * 20);
            cells[i][j].setFillColor(sf::Color(50, 50, 50));
            cells[i][j].setOutlineThickness(1);
            cells[i][j].setOutlineColor(sf::Color::Black);
        }
    }
    
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            target.draw(cells[i][j], states);
        }
    }
    
}
