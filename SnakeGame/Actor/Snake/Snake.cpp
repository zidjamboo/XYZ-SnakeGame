#include "Snake.h"

#include "../../Constants.h"
#include "../../Field/Field.h"

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
        rect.setPosition(ToDrawPosition(part.position));
        rect.setFillColor(sf::Color::Red);

        window.draw(rect);
    }
}

bool SnakeGame::isSnakeSelfCollide(Snake& snake)
{
    for (auto it = ++snake.parts.begin(); it != snake.parts.end(); ++it)
    {
        if (it->position == snake.head().position)
        {
            return true;
        }
    }

    return false;
}
