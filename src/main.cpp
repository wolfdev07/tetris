#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main() {
    //crea una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");

    // Setear el límite de frames
    window.setFramerateLimit(60);

    //Correr el juego
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) window.close();
        }

        //Limpiar ventana
        window.clear(Color(20, 20, 20));
        
        // Mostrar contenido en la pantalla
        window.display();
    }

    return 0;
}