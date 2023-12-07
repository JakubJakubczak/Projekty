#include <SFML/Graphics.hpp>
#include <iostream>

const int SIZE = 8;
const float SQUARE_SIZE = 80.0f;

sf::RenderWindow window(sf::VideoMode(SIZE * SQUARE_SIZE, SIZE * SQUARE_SIZE), "SFML Chess");

// Function to draw the chess board
void drawBoard(sf::RenderWindow& window) {
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
void drawPieces(sf::RenderWindow& window, sf::Texture& texture, char piece, int row, int col) {
    int x = col * SQUARE_SIZE;
    int y = row * SQUARE_SIZE;

    sf::Sprite sprite(texture);

    sf::Vector2u texture_Size = texture.getSize();
    texture_Size.x /=6;
    texture_Size.y/=2; 
    sprite.setTextureRect(sf::IntRect( 2*  texture_Size.x, 1* texture_Size.y, texture_Size.x, texture_Size.y));
    //sprite.setPosition(x, y);

    window.draw(sprite);
}

int main() {
    sf::Texture texture;
    if (!texture.loadFromFile("images/pieces.png")) {
        std::cerr << "Failed to load chess_pieces.png" << std::endl;
        return 1;
    }

    char chessBoard[SIZE][SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        drawBoard(window);

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (chessBoard[i][j] != ' ') {
                    drawPieces(window, texture, chessBoard[i][j], i, j);
                }
            }
        }

        window.display();
    }

    return 0;
}
