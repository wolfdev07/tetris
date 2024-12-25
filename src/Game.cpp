// include/Game.cpp
#include "../include/Game.hpp"
#include <iostream>

Game::Game() 
    : window(sf::VideoMode(800, 800), "Tetris"), isRunning(true), currentX(4), currentY(0), score(0) {
    board.reset(window);
    // Centra el Tetromino en el tablero
    currentX = (Board::WIDTH / 2) - 1;
    currentY = 0;
    currentTetromino.setRandomShape();

    if (!backgroundMusic.openFromFile("../assets/sounds/Tetris.wav"))
    {
        std::cerr << "Error: No se pudo cargar Tetris.mp3" << std::endl;
    }
    backgroundMusic.setLoop(true);  // Repetir la música indefinidamente
    backgroundMusic.play(); // Reproducir la música
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
    int fallSpeed = std::max(60, 30 - score / 500); //Ajustar velocidad de caída

    fallDelay ++;

    if (fallDelay >= fallSpeed)
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
            int linesCleared = board.clearFullLines();
            if (linesCleared > 0)
            {
                score += linesCleared * 10;

            }
            currentX = (Board::WIDTH / 2) - 1;
            currentY = 0;
            currentTetromino.setRandomShape();
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
    window.draw(board);
    // Dibujar el panel lateral
    drawScorePanel();
    // Dibujar el Tetromino actual
    float cellWidth = window.getSize().x / static_cast<float>(Board::WIDTH);
    float cellHeight = window.getSize().y / static_cast<float>(Board::HEIGHT);
    float cellSize = std::min(cellWidth, cellHeight);
    for (const auto& block : currentTetromino.getShape())
    {
        sf::RectangleShape rect(sf::Vector2f(cellSize, cellSize));
        rect.setPosition(
            (currentX + block.x) * cellSize,
            (currentY + block.y) * cellSize
        );
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
    currentX = (Board::WIDTH / 2) - 1; // Centra el nuevo Tetromino
    currentY = 0;
    currentTetromino.setRandomShape();
    // Terminar juego al llenar
    if (!board.isValidPosition(currentX, currentY, currentTetromino.getShape()))
    {
        isRunning = false;
    }
}

void Game::drawScorePanel() {
    // Fondo del panel: 200 px de ancho y 800 px de alto
    sf::RectangleShape panelBackground(sf::Vector2f(200, 800));
    panelBackground.setPosition(600, 0);
    panelBackground.setFillColor(sf::Color(30, 30, 30));
    panelBackground.setOutlineThickness(1);
    panelBackground.setOutlineColor(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("../assets/fonts/void_pixel-7.ttf"))
    {
        std::cerr << "Error: No se pudo cargar Void Pixel" << std::endl;
    }
    
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(620, 400);

    float margin = 10.f;
    panelBackground.setPosition(600 + margin, 0);

    // Dibuja el panel y el texto
    window.draw(panelBackground);
    window.draw(scoreText);
}