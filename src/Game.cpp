#include "../include/Game.hpp"

Game::Game() : window(sf::VideoMode(400, 800), "Tetris"), isRunning(true) {}

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
        }
        
    }
    
}

void Game::update() {
    // Lógica de actualización del juego
}

void Game::render() {
    window.clear();
    window.draw(board);
    window.display();
}