#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.hpp"


using namespace std;
using namespace sf;

int main() {
    //crea un tablero
    Board board;

    //crea una ventana
    sf::RenderWindow window(sf::VideoMode(400, 400), "Tetris");

    // Setear el límite de frames
    window.setFramerateLimit(60);

    //Correr el juego
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();
        }
        //actualizar colores del tablero
        board.updateBoardColors();

        //Limpiar ventana
        window.clear(Color(20, 20, 20));
        
        //Dibujar tablero
        window.draw(board);

        // Mostrar contenido en la pantalla
        window.display();
    }

    return 0;
}