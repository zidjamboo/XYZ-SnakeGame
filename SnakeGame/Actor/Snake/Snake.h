#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

typedef sf::Vector2<int> SnakePartPosition;
namespace SnakeGame
{
    struct SnakePart
    {
        SnakePartPosition position;
    };

    struct Game;

    void DrawSnake(Game& game, sf::RenderWindow & window);
}
