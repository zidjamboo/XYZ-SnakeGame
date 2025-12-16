#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "../../Types.h"

namespace SnakeGame
{
    struct SnakePart
    {
        FieldPosition position;
    };

    struct Snake
    {
        Direction direction = Direction::UP;
        Direction lastDirection = Direction::UP;

        std::list<SnakePart> parts;

        SnakePart& head()
        {
            return parts.front();
        }

        SnakePart& back()
        {
            return parts.back();
        }
    };

    struct Game;

    void InitSnake(Snake& snake);
    void DrawSnake(const Snake& snake, sf::RenderWindow & window);
}
