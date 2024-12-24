// include/Game.cpp
#include "../include/Game.hpp"

Game::Game() 
    : window(sf::VideoMode(600, 800), "Tetris"), isRunning(true), currentX(4), currentY(0), score(0) {
    // Centra el tetromino en la parte superior del tablero
    board.reset(window);
    currentTetromino.setRandomShape();
    moveSound.setBuffer(moveSoundBuffer);
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
                moveSound.play();
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
            } else if (event.key.code == sf::Keyboard::Space)
            {
                hardDrop();
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
    int colorIntensity = std::min(255, score / 10);
    window.clear(sf::Color(20, 20 + colorIntensity, 20));
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

void Game::hardDrop() {
    int dropY = currentY;

    while (board.isValidPosition(currentX, dropY + 1, currentTetromino.getShape()))
    {
        ++dropY;
    }
    
    // Actualizar la posición del Tetromino
    currentY = dropY;
    // Colocar el Tetronimo en el Tablero
    board.placeTetromino(currentX, currentY, currentTetromino.getShape(), currentTetromino.getColor());
    // Limpia líneas completas, si las hay
    score += board.clearFullLines();

    // Genera un nuevo Tetromino
    currentTetromino.setRandomShape();
    currentX = 4; // Centra el nuevo Tetromino
    currentY = 0;

    // Terminar juego al llenar
    if (!board.isValidPosition(currentX, currentY, currentTetromino.getShape()))
    {
        isRunning = false;
    }
}