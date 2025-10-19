#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

const int gridSize = 10;
const int windowSize = 600;
const int cellSize = windowSize / gridSize;

int main()
{
    RenderWindow window(VideoMode(windowSize, windowSize), "Practice 6");

    RectangleShape cell(Vector2f(cellSize, cellSize));
    cell.setOutlineColor(Color::Black);
    cell.setOutlineThickness(1);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        window.clear(Color::White);

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                cell.setPosition(j * cellSize, i * cellSize);

                int startRow = gridSize / 2 - 1;
                int height = gridSize - startRow;

                if (i >= startRow) {
                    int level = i - startRow;
                    int left = level;
                    int right = gridSize - level - 1;

                    if (j >= left && j <= right)
                        cell.setFillColor(Color::Green);
                    else
                        cell.setFillColor(Color::White);
                }
                else {
                    cell.setFillColor(Color::White);
                }

                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
