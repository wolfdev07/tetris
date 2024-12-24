#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Tetromino.hpp"
#include <SFML/Graphics.hpp>

class Game {

private:
    sf::RenderWindow window;
    Board board;
    Tetromino currentTetromino;
    bool isRunning;

    // Variables para la posición del tetromino actual
    int currentX; // Columna en la que está el tetromino
    int currentY; // Fila en la que está el tetromino

public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();
};

#endif // GAME_HPP
