// src/Board.cpp
#include "../include/Board.hpp"
#include <vector>

Board::Board() { 
    //srand(static_cast<unsigned int>(time(nullptr)));
}

void Board::reset(const sf::RenderWindow& window) {
    cells.resize(HEIGHT, std::vector<sf::RectangleShape>(WIDTH));  // Correct resizing
    float cellWidth = window.getSize().x / static_cast<float>(WIDTH);
    float cellHeight = window.getSize().y / static_cast<float>(HEIGHT);
    float cellSize = std::min(cellWidth, cellHeight);

    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            grid[i][j] = 0;
            cells[i][j].setSize(sf::Vector2f(cellSize, cellSize));
            cells[i][j].setPosition(j * cellSize, i * cellSize);
            cells[i][j].setFillColor(sf::Color(50, 50, 50)); // Set color here
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
            target.draw(cells[i][j]);
        }
    }
}

bool Board::isValidPosition(int x, int y, const std::vector<sf::Vector2i>& shape) {
    for (const auto& block : shape)
    {
        int newX = x + block.x;
        int newY = y + block.y;

        if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT)
        {
            return false;
        }

        if (grid[newY][newX] != 0)
        {
            return false;
        }
    }
    
    return true;
};

void Board::placeTetromino(int x, int y, const std::vector<sf::Vector2i>& shape, int color) {
    for (const auto& block : shape)
    {
        int newX = x + block.x;
        int newY = y + block.y;
        grid[newY][newX] = color; // Marca la celda con el color del tetromino
    }
    updateCellColors();
}

int Board::clearFullLines() {
    int linesCleared = 0;
    for (int i = 0; i < HEIGHT; ++i)
    {
        bool fullLine = true;
        for (int j = 0; j < WIDTH; ++j)
        {
            if (grid[i][j] == 0)
            {
                fullLine = false;
                break;
            }
        }

        if (fullLine)
        {
            ++linesCleared;
            // Desplazar las líneas hacia abajo
            for (int k = i; k > 0; --k)
            {
                for (int j = 0; j < WIDTH; ++j)
                {
                    grid[k][j] = grid[k - 1][j];
                }
            }
            // Limpiar la primera línea
            for (int j = 0; j < WIDTH; ++j)
            {
                grid[0][j] = 0;
            }
        }
    }
    updateCellColors();
    return linesCleared;
}

void Board::updateCellColors() {
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (grid[i][j] != 0)
            {
                cells[i][j].setFillColor(sf::Color(grid[i][j] * 35, grid[i][j] * 35, grid[i][j] * 35));
            } 
            else 
            {
                cells[i][j].setFillColor(sf::Color(50, 50, 50));
            }
        }
    }
}
