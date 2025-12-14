#include "Snake.h"

#include "../../Constants.h"

void SnakeGame::InitSnake(Snake& snake)
{
    snake.parts.clear();
    SnakePart head;
    head.position.x = 16;
    head.position.y = 12;
    snake.parts.emplace_front(head);
}

void SnakeGame::DrawSnake(const Snake& snake, sf::RenderWindow& window)
{
    for (auto& part: snake.parts)
    {
        sf::RectangleShape rect;
        rect.setSize({CELL_SIZE, CELL_SIZE});
        rect.setPosition(
            CELL_SIZE * static_cast<float>(part.position.x),
            CELL_SIZE * static_cast<float>(part.position.y));
        rect.setFillColor(sf::Color::Red);

        window.draw(rect);
    }
}
