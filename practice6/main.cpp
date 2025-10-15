#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

const int cellSize = 50;
const int gridSize = 10;

int main()
{
    RenderWindow window(sf::VideoMode(500, 500), "Grid Pattern");

    int pattern[gridSize][gridSize] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    RectangleShape cells[gridSize][gridSize];

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cells[i][j].setSize(Vector2f(cellSize, cellSize));
            cells[i][j].setPosition(j * cellSize, i * cellSize);
            cells[i][j].setOutlineColor(Color::Black);
            cells[i][j].setOutlineThickness(1);

            if (pattern[i][j] == 1)
                cells[i][j].setFillColor(Color::Green);
            else
                cells[i][j].setFillColor(Color::White);
        }
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                window.draw(cells[i][j]);
            }
        }
        window.display();
    }

    return 0;
}