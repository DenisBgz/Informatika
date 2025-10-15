#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

const int cellSize = 50;
const int gridSize = 10;

int main()
{
    RenderWindow window(VideoMode(500, 500), "Grid Pattern");

    RectangleShape cells[gridSize][gridSize];

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            cells[i][j].setSize(Vector2f(cellSize, cellSize));
            cells[i][j].setPosition(j * cellSize, i * cellSize);
            cells[i][j].setOutlineColor(Color::Black);
            cells[i][j].setOutlineThickness(1);

            if (i == 4)
            {
                cells[i][j].setFillColor(Color::Green);
            }
            else if (i == 5 && j >= 1 && j <= 8)
            {
                cells[i][j].setFillColor(Color::Green);
            }
            else if (i == 6 && j >= 2 && j <= 7)
            {
                cells[i][j].setFillColor(Color::Green);
            }
            else if (i == 7 && j >= 3 && j <= 6)
            {
                cells[i][j].setFillColor(Color::Green);
            }
            else if (i == 8 && j >= 4 && j <= 5)
            {
                cells[i][j].setFillColor(Color::Green);
            }
            else
            {
                cells[i][j].setFillColor(Color::White);
            }
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
        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                window.draw(cells[i][j]);
            }
        }
        window.display();
    }

    return 0;
}
