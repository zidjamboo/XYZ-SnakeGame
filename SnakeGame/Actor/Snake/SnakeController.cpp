#include <SFML/Window/Keyboard.hpp>
#include "SnakeController.h"

namespace
{
    SnakeGame::SnakePart NextHead(SnakeGame::Snake& snake)
    {
        SnakeGame::SnakePart nextHead = snake.head();
        if (snake.direction == SnakeGame::Direction::LEFT)
        {
            nextHead.position.x -= 1;
        }
        else if (snake.direction == SnakeGame::Direction::UP)
        {
            nextHead.position.y -= 1;
        }
        else if (snake.direction == SnakeGame::Direction::RIGHT)
        {
            nextHead.position.x += 1;
        }
        else if (snake.direction == SnakeGame::Direction::Down)
        {
            nextHead.position.y += 1;
        }

        return nextHead;
    }

    bool isEatApple(SnakeGame::SnakePart& head, SnakeGame::Apple& apple)
    {
        if (head.position == apple.position)
        {
            return true;
        }

        return false;
    }

    void Grow(SnakeGame::Snake& snake, SnakeGame::SnakePart& nextHead)
    {
        snake.parts.push_front(nextHead);
    }

    void Move(SnakeGame::Snake& snake, SnakeGame::SnakePart& nextHead)
    {
        snake.parts.push_front(nextHead);
        snake.parts.pop_back();
    }
}

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

void SnakeGame::DoSnakeAction(Game& game)
{
    SnakePart nextHead = NextHead(game.snake);
    if (isEatApple(nextHead, game.apple))
    {
        Grow(game.snake, nextHead);
    }
    else
    {
        Move(game.snake, nextHead);
    }
}
