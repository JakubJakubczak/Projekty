#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h> 

const int SIZE = 8;
sf::Sprite f[32]; //figures



// Function to draw the chess board
void drawBoard(sf::RenderWindow& window, unsigned int SQUARE_SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));

            if ((i + j) % 2 == 0) {
                square.setFillColor(sf::Color(209, 139, 71));  // Light color
            } else {
                square.setFillColor(sf::Color(139, 69, 19));   // Dark color
            }

            square.setPosition(j * SQUARE_SIZE, i * SQUARE_SIZE);
            window.draw(square);
        }
    }
}

// Function to draw chess pieces
void drawPieces(sf::RenderWindow& window, sf::Texture& texture, int chess_board[SIZE][SIZE], unsigned int SQUARE_SIZE) {
    sf::Sprite sprite[32](texture);

    sf::Vector2u texture_Size = texture.getSize();
    texture_Size.x /=6;
    texture_Size.y/=2; 

    int column;
    int row;
    int sprite_Counter=0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
           if(chess_board[i][j]==0) continue;

           if(chess_board[i][j]>0) row=0;
           else                     row=1;
           column = abs(chess_board[i][j]) -1;
           sprite[sprite_Counter].setTextureRect(sf::IntRect( column * texture_Size.x, row * texture_Size.y, texture_Size.x, texture_Size.y));
           sprite[sprite_Counter].setPosition(i*SQUARE_SIZE, j*SQUARE_SIZE);
           if(++sprite_Counter>=32) std::cout<<"Sprite behind range";
        }
        
    

    window.draw(sprite);
}

int main() {
    sf::Texture texture;
    if (!texture.loadFromFile("images/figures.png")) {
        std::cerr << "Failed to load chess_pieces.png" << std::endl;
        return 1;
    }
    const float SQUARE_SIZE = texture.getSize().y/2; // two columns in image figures.png
    sf::RenderWindow window(sf::VideoMode(SIZE * SQUARE_SIZE, SIZE * SQUARE_SIZE), "SFML Chess",sf::Style::Close | sf::Style::Resize);

    int chessBoard[SIZE][SIZE] =
        {1, 2, 3, 4, 6, 3, 2, 1},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {-6, -6, -6, -6, -6, -6, -6, -6},
        {-1, -2, -3, -4, -6, -3, -2, -1}
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        drawBoard(window,SQUARE_SIZE);
        drawPieces(window, texture, chessBoard[SIZE][SIZE],SQUARE_SIZE);

        window.display();
    }

    return 0;
}
