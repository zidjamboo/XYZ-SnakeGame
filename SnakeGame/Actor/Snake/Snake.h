#pragma once
#include <list>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Direction.h"

typedef sf::Vector2<int> SnakePartPosition;
namespace SnakeGame
{
    struct SnakePart
    {
        SnakePartPosition position;
    };

    struct Snake
    {
        Direction direction = Direction::UP;
        std::list<SnakePart> parts;

        SnakePart& head()
        {
            return parts.front();
        }
    };

    struct Game;

    void DrawSnake(Game& game, sf::RenderWindow & window);
}
