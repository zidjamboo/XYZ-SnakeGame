#include <SFML/Window/Keyboard.hpp>
#include <functional>
#include "SnakeController.h"

#include "../../Field/Field.h"
#include "../../Game/Game.h"

namespace
{
    int headsToAddCount = 0;

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
        else if (snake.direction == SnakeGame::Direction::DOWN)
        {
            nextHead.position.y += 1;
        }

        return nextHead;
    }

    bool isEatApple(const SnakeGame::SnakePart& head, const SnakeGame::Apple& apple)
    {
        if (head.position == apple.position)
        {
            return true;
        }

        return false;
    }

    void AddNextHead(SnakeGame::Snake& snake, const SnakeGame::SnakePart& nextHead)
    {
        snake.parts.push_front(nextHead);
        SnakeGame::OccupyFieldPosition(nextHead.position);
    }

    void DropTail(SnakeGame::Snake& snake)
    {
        SnakeGame::FreeFieldPosition(snake.back().position);
        snake.parts.pop_back();
    }

    void Grow(SnakeGame::Snake& snake, const SnakeGame::SnakePart& nextHead)
    {
        AddNextHead(snake, nextHead);
    }

    void Move(SnakeGame::Snake& snake, const SnakeGame::SnakePart& nextHead)
    {
        AddNextHead(snake, nextHead);
        DropTail(snake);
    }
}

void SnakeGame::ChangeDirection(Snake& snake)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&
        snake.lastDirection != Direction::RIGHT)
    {
        snake.direction = Direction::LEFT;
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
        snake.lastDirection != Direction::DOWN)
    {
        snake.direction = Direction::UP;
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
        snake.lastDirection != Direction::LEFT)
    {
        snake.direction = Direction::RIGHT;
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) &&
        snake.lastDirection != Direction::UP)
    {
        snake.direction = Direction::DOWN;
    }
}

void SnakeGame::DoSnakeAction(Game& game, const std::function<void()>& onAppleEat)
{
    game.snake.lastDirection = game.snake.direction;
    SnakePart nextHead = NextHead(game.snake);
    if (isEatApple(nextHead, game.apple))
    {

        headsToAddCount += game.gameMode.GetLengthModifier();
        onAppleEat();
    }

    if (headsToAddCount > 0)
    {
        Grow(game.snake, nextHead);
        headsToAddCount--;
    }
    else
    {
        Move(game.snake, nextHead);
    }
}
