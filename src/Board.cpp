#include "../include/Board.hpp"

// Constructor
Board::Board() {
    // Inicializar la matriz del tablero a 0
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            board[i][j] = 0;
            boardShapes[i][j] = sf::RectangleShape(sf::Vector2f(20, 20));
            boardShapes[i][j].setPosition(j * 20, i * 20);
            boardShapes[i][j].setFillColor(sf::Color(50, 50, 50));
            boardShapes[i][j].setOutlineThickness(2);
            boardShapes[i][j].setOutlineColor(sf::Color(0, 0, 0));
        }
    }
}

// Actualizar los colores de las celdas del tablero
void Board::updateBoardColors() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            switch (board[i][j]) {
                case 0: boardShapes[i][j].setFillColor(sf::Color(50, 50, 50)); break;
                case 1: boardShapes[i][j].setFillColor(sf::Color(255, 166, 0)); break;
                case 2: boardShapes[i][j].setFillColor(sf::Color(245, 152, 245)); break;
                case 3: boardShapes[i][j].setFillColor(sf::Color(51, 204, 153)); break;
                case 4: boardShapes[i][j].setFillColor(sf::Color(255, 110, 110)); break;
                case 5: boardShapes[i][j].setFillColor(sf::Color(255, 204, 77)); break;
                case 6: boardShapes[i][j].setFillColor(sf::Color(166, 166, 255)); break;
                case 7: boardShapes[i][j].setFillColor(sf::Color(138, 194, 247)); break;
            }
        }
    }
}

// Sobrescribir método draw para dibujar el tablero
void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            target.draw(boardShapes[i][j], states);
        }
    }
}