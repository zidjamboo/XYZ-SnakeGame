#include <SFML/Window/Keyboard.hpp>
#include "SnakeController.h"

void SnakeGame::ChangeDirection(Snake& snake)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        snake.direction = Direction::LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        snake.direction = Direction::UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        snake.direction = Direction::RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        snake.direction = Direction::Down;
    }
}

void SnakeGame::MoveSnake(Snake& snake)
{
    if (snake.direction == Direction::LEFT)
    {
        snake.head().position.x -= 1;
    }
    else if (snake.direction == Direction::UP)
    {
        snake.head().position.y -= 1;
    }
    else if (snake.direction == Direction::RIGHT)
    {
        snake.head().position.x += 1;
    }
    else if (snake.direction == Direction::Down)
    {
        snake.head().position.y += 1;
    }
}
