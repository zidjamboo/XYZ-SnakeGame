#pragma once

#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Background
    {
        sf::Texture texture;
        sf::Sprite sprite;
    };

    struct Game;

    void InitBackground(Game& game);
}
