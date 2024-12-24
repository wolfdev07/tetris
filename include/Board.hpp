#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>

class Board: public sf::Drawable {

private:
    // dimensiones del tablero
    static constexpr int WIDTH = 10;
    static constexpr int HEIGHT = 20;

    // matriz del tablero
    int board[HEIGHT][WIDTH];

    sf::RectangleShape boardShapes[HEIGHT][WIDTH];

    //

    // texturas y sprites para los bloques
    //static constexpr int CELL_SIZE = 30;
    //sf::Texture blockTexture;
    //sf::Sprite blockSprite;

public:
    // constructor
    Board();

    void updateBoardColors();

    // reinicia el tablero
    //void reset();

    //Dibuja el tablero en la ventana
    //void draw(sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    // Verifica si una posisción es válida
    //bool isValidPosition(int x, int y, const std::vector<sf::Vector2i>& shape);

    //  Fija un tetromino al tablero (bloques caen en su lugar)
    //void placeTetromino(int x, int y, const std::vector<sf::Vector2i>& shape, int color);

    // Limpia líneas completas y retorna cuántas se limpiaron
    //int clearFullLines();

    // Accesor para las dimensiones del tablero
    //int getWidth() const { return WIDTH; }
    //int getHeight() const { return HEIGHT; }
};


#endif // BOARD_HPP