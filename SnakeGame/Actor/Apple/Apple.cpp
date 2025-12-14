#include "Apple.h"
#include "../../Constants.h"

void SnakeGame::InitApple(Apple& apple)
{
    apple.position.x = 3;
    apple.position.y = 4;
}

void SnakeGame::DrawApple(const Apple& apple, sf::RenderWindow& window)
{
    sf::RectangleShape rect;
    rect.setPosition({
        CELL_SIZE * static_cast<float>(apple.position.x),
        CELL_SIZE * static_cast<float>(apple.position.y)});
    rect.setSize({CELL_SIZE, CELL_SIZE});
    rect.setFillColor(sf::Color::Green);

    window.draw(rect);
}
