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

public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();
};

#endif // GAME_HPP
