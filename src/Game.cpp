#include "../include/Game.hpp"

Game::Game() : window(sf::VideoMode(400, 800), "Tetris"), isRunning(true), currentX(4), currentY(0) {
    // Centra el tetromino en la parte superior del tablero
    currentTetromino.setRandomShape();
}

void Game::run() { 
    while(isRunning) 
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            isRunning = false;
        } else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left)
            {
                int newX = currentX - 1;
                if (board.isValidPosition(newX, currentY, currentTetromino.getShape()))
                {
                    currentX = newX;
                }
            } else if (event.key.code == sf::Keyboard::Right)
            {
                int newX = currentX + 1;
                if (board.isValidPosition(newX, currentY, currentTetromino.getShape()))
                {
                    currentX = newX;
                }
            } else if (event.key.code == sf::Keyboard::Up)
            {
                currentTetromino.rotate();
                if (!board.isValidPosition(currentX, currentY, currentTetromino.getShape()))
                {
                    currentTetromino.rotate();
                }
            }
        }
    }
}

void Game::update() {
    // Lógica de actualización del juego
    static int fallDelay = 0;
    static const int FALL_SPEED = 30; //Ajustar velocidad de caída

    fallDelay ++;

    if (fallDelay >= FALL_SPEED)
    {
        fallDelay = 0;
        int newX = currentX;
        int newY = currentY + 1;

        if (board.isValidPosition(newX, newY, currentTetromino.getShape()))
        {
            currentY = newY;
        } else
        {
            board.placeTetromino(currentX, currentY, currentTetromino.getShape(), currentTetromino.getColor());
            board.clearFullLines();
            currentTetromino.setRandomShape();
            currentX = 4;
            currentY = 0;
            if (!board.isValidPosition(currentX, currentY, currentTetromino.getShape()))
            {
                isRunning = false;
            }
        }
    }
}

void Game::render() {
    window.clear();
    // Dibujar el tablero
    window.draw(board);

    for (const auto& block : currentTetromino.getShape())
    {
        sf::RectangleShape rect(sf::Vector2f(20, 20));
        rect.setPosition((currentX + block.x) * 20, (currentY + block.y) * 20);
        rect.setFillColor(sf::Color(currentTetromino.getColor()));
        window.draw(rect);
    }

    window.display();
}
